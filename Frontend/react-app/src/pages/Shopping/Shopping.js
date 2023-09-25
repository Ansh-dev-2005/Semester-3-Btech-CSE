import React, { useState, useEffect } from "react";
import axios from 'axios';

export default function Shopping() {
    const [userLocation, setUserLocation] = useState(null);
    const [ShoppingPlaces, setShoppingPlaces] = useState([]);
    const [error, setError] = useState(null);
    const formatCategoryName = (category) => {
        // Split the category name by underscores and capitalize each word
        const words = category.split('_').map(word => word.charAt(0).toUpperCase() + word.slice(1));
        // Join the words back together with spaces
        return words.join(' ');
    };

    useEffect(() => {
        // Check if Geolocation is available in the user's browser
        if ("geolocation" in navigator) {
            navigator.geolocation.getCurrentPosition(
                (position) => {
                    // Get the user's latitude and longitude
                    const { latitude, longitude } = position.coords;

                    // Store the user's location in state
                    setUserLocation({ latitude, longitude });

                    // Now you can update the Axios request with the user's location
                    fetchShoppingPlaces(latitude, longitude);
                },
                (error) => {
                    setError("Error getting location: " + error.message);
                }
            );
        } else {
            setError("Geolocation is not available in your browser.");
        }
    }, []);

    // Function to fetch nearby places related to Shopping using the user's location
    const fetchShoppingPlaces = async (latitude, longitude) => {
        const apiKey = '271302dc76msh353a518ef7811f8p115db8jsn15cfd6685b76';

        const options = {
            method: 'GET',
            url: 'https://map-places.p.rapidapi.com/nearbysearch/json',
            params: {
                location: `${latitude},${longitude}`, // Use the user's location here
                radius: '150000',
                keyword: 'Shopping Places', // You can adjust the keyword as needed
                type: 'point_of_interest', // You can adjust the type as needed
                fields: 'name,photos,formatted_address,opening_hours,rating' // Request additional fields
            },
            headers: {
                'X-RapidAPI-Key': apiKey,
                'X-RapidAPI-Host': 'map-places.p.rapidapi.com'
            }
        };

        try {
            const response = await axios.request(options);
            const places = response.data.results; // Get nearby places
            groupPlacesByCategory(places);
        } catch (error) {
            setError("Error fetching nearby places: " + error.message);
        }
    };

    // Function to group places by category
    const groupPlacesByCategory = (places) => {
        const categories = {};
        places.forEach((place) => {
            const category = place.types[0]; // Assuming the first type is the category
            if (!categories[category]) {
                categories[category] = [];
            }
            categories[category].push({ ...place, showDropdown: false });
        });
        setShoppingPlaces(categories);
    };

    // Function to toggle dropdown visibility for a specific place
    // Function to toggle dropdown visibility for a specific place
    const toggleDropdown = (category, placeIndex) => {
        setShoppingPlaces((prevState) => {
            const updatedCategories = { ...prevState };
            updatedCategories[category] = updatedCategories[category].map((place, index) => {
                if (index === placeIndex) {
                    return { ...place, showDropdown: !place.showDropdown };
                } else {
                    return place;
                }
            });
            return updatedCategories;
        });
    };


    return (
        <div className="p-4">
            {Object.keys(ShoppingPlaces).map((category, index) => (
                <div key={index} className="mb-4">
                    <h2 className="text-2xl font-bold">{formatCategoryName(category)}</h2>
                    <ul>
                        {ShoppingPlaces[category].map((place, placeIndex) => (
                            <li key={placeIndex} className="mb-2">
                                <div className="flex ">
                                    <div>
                                        <span className="text-lg">{place.name}</span>
                                        <button
                                            className="ml-2 text-blue-500 hover:text-blue-700"
                                            onClick={() => toggleDropdown(category, placeIndex)}
                                        >
                                            Show Details
                                        </button>
                                    </div>
                                    {place.showDropdown && (
                                        <div className="mt-2">
                                            <p>Address: {place.vicinity}</p>
                                            <p>Rating: {place.rating}</p>
                                            {place.photos && (
                                                <div>
                                                    <p>Photos:</p>
                                                    {place.photos.map((photo, photoIndex) => (
                                                        <img
                                                            key={photoIndex}
                                                            src={`https://maps.googleapis.com/maps/api/place/photo?maxwidth=400&photoreference=${place.photos[0].photo_reference}&key=271302dc76msh353a518ef7811f8p115db8jsn15cfd6685b76`}
                                                            alt={`Photo ${photoIndex + 1}`}
                                                            className="max-w-full h-auto mt-2"
                                                        />
                                                    ))}
                                                </div>
                                            )}
                                            {/* Add more details here */}
                                        </div>
                                    )}
                                </div>
                            </li>
                        ))}
                    </ul>
                </div>
            ))}
            {error && <p className="text-red-500">{error}</p>}
        </div>
    );
}
