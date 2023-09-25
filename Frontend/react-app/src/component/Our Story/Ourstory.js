import React from "react";

import "./Ourstory.css"
import img1 from "./Images/dehradun.jpg"
import img2 from "./Images/mussoorie.jpg"
import img3 from "./Images/sir-george-everest-house-9518421.jpg"
const Ourstory = () => {
  return (
    <div className="our-story container pt-6">
      <div className="container py-5">
        <div className="row align-items-center">
          <div className="col-lg-6 pb-4">
            <img
              src={img1}
              alt="Mussoorie"
              className="img-fluid w-auto rounded"
              loading="lazy"
            />
          </div>
          <div className="col-lg-6 pb-4">
            <div className="Tagline pb-4" style={{ width: 288, height: 25, position: "relative" }}>
              <div className="KingOfFort" style={{ left: 96, top: 0, position: "absolute", color: "#FBD784", fontSize: 18, fontWeight: "700", textTransform: "uppercase", letterSpacing: 6, wordWrap: "break-word" }}>
                Dehradun
              </div>
              <div className="Line" style={{ width: 72, height: 2, left: 0, top: 10, position: "absolute", background: "#FBD784" }} />
            </div>

            <p className="pt-5 mt-4 text-black font-weight-normal">
              Dehradun is the capital of the Indian state of Uttarakhand, near
              the Himalayan foothills. At its core is the 6-sided Ghanta Ghar
              clock tower. To the southwest is Paltan Bazaar, a busy shopping
              area. Just east is the Sikh temple Gurdwara Nanaksar, topped with
              ornate white and golden domes. In Clement Town to the city’s
              southwest, Mindrolling Monastery is a Tibetan Buddhist center with
              shrine rooms in its Great Stupa.

            </p>
            <div className="text-center">
              {/* Wrap the button in a div with text-center class */}
            </div>
          </div>
        </div>
      </div>


      <div className="container py-5">
        <div className="row align-items-center">
          <div className="col-lg-6 pb-4 order-lg-last">
            <img
              src={img2}
              alt="Our service"
              className="img-fluid w-auto rounded"
              loading="lazy"
            />
          </div>
          <div className="col-lg-6 pb-4 order-lg-first">
            <div
              className="Tagline pb-4"
              style={{ width: 288, height: 25, position: "relative" }}
            >
              <div
                className="KingOfFort"
                style={{
                  left: 96,
                  top: 0,
                  position: "absolute",
                  color: "#FBD784",
                  fontSize: 18,
                  fontWeight: "700",
                  textTransform: "uppercase",
                  letterSpacing: 6,
                  wordWrap: "break-word",
                }}
              >
                Mussoorie
              </div>
              <div
                className="Line"
                style={{
                  width: 72,
                  height: 2,
                  left: 0,
                  top: 10,
                  position: "absolute",
                  background: "#FBD784",
                }}
              />
            </div>

            <p className="pt-5 mt-4 text-black font-weight-normal ">
              
            Mussoorie is a hill station and a municipal board in the Dehradun District of the Indian state of Uttarakhand. It is about 35 kilometres from the state capital of Dehradun and 290 km north of the national capital of New Delhi. The hill station is in the foothills of the Garhwal Himalayan range.
            </p>
            <div className="text-center">
              {" "}
              {/* Wrap the button in a div with text-center class */}
              
            </div>
          </div>
        </div>
      </div>
      <div className="container py-5">
        <div className="row align-items-center">
          <div className="col-lg-6 mb-4 mb-lg-0">
            <img src={img3} alt="Our Story" className="img-fluid rounded" />
          </div>
          <div className="col-lg-6 pb-4">
            <div
              className="Tagline pb-2"
              style={{ width: 288, height: 25, position: "relative" }}
            >
              <div
                className="KingOfFort pd-5"
                style={{
                  left: 96,
                  top: 0,
                  position: "absolute",
                  color: "#FBD784",
                  fontSize: 18,

                  fontWeight: "700",
                  textTransform: "uppercase",
                  letterSpacing: 6,
                  wordWrap: "break-word",
                }}
              >
                George Everest
              </div>
              <div
                className="Line"
                style={{
                  width: 72,
                  height: 2,
                  left: 0,
                  top: 10,
                  position: "absolute",
                  background: "#FBD784",
                }}
              />
            </div>

            <p className="pt-5 mt-3 text-black font-weight-normal">
              Sir George Everest was a British surveyor and geographer who
              served as Surveyor General of India from 1830 to 1843. He is best
              known for having Mount Everest, the highest mountain on Earth,
              named in his honour.
              
            </p>
            <div className="text-center">
              {" "}
              {/* Wrap the button in a div with text-center class */}
              
            </div>
          </div>
        </div>
      </div>
    </div>
  );
};

export default Ourstory;
