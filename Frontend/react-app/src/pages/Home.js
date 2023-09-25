import React from "react";
import { Carousel } from 'react-responsive-carousel';
import 'react-responsive-carousel/lib/styles/carousel.min.css';
import img1 from "./images/clock-tower-8914657.jpg";
import img2 from "./images/clock-tower-9815592.jpg";
import img3 from "./images/download.jpg";
import img4 from "./images/Rishikesh-Yoga-City-India.jpg";
import Ourstory from "../component/Our Story/Ourstory";

const popularPlaces = [
  img1,
  img2,
  img3,
  img4,
  // Add more image URLs as needed
];

export default function Home() {
  return (
    <div className="min-h-full">
      <main>
        <div className="mx-auto h-full">
          <Carousel
            showThumbs={false}
            showStatus={false}
            infiniteLoop={true}
            autoPlay={true}
            interval={5000}
            className="w-full"
          >
            {popularPlaces.map((place, index) => (
              <div key={index} className="relative">
                {/* Image */}
                <img src={place} alt={`Popular Place ${index + 1}`} />
                {/* Glassmorphism Text overlay */}
                <div className="absolute inset-0 flex items-center justify-center">
                  <div className="bg-opacity-60 border-2 backdrop-blur-md backdrop-filter bg-white bg-opacity-10 p-4 text-center">
                    <h1 className="text-6xl font-bold tracking-tight text-white">
                      Welcome to Dehradun <br /> Tourist Information System
                    </h1>
                  </div>
                </div>
              </div>
            ))}
          </Carousel>
        </div>
        <div>
          <Ourstory />
        </div>
      </main>
    </div>
  );
}
