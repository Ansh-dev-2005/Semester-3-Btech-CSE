import React from "react";

const LandingSection = () => {
  return (
    <section className="bg-blue-500 py-16 h-full text-white">
      <div className="container mx-auto text-center  h-full max-h-full">
        <h1 className="text-4xl font-semibold mb-4">
          Welcome to City Place Locator
        </h1>
        <p className="text-lg mb-8">
          Discover the best places in the city with ease.
        </p>
        <button className="bg-yellow-500 text-blue-500 hover:bg-yellow-400 hover:text-blue-400 py-2 px-6 rounded-full text-lg font-semibold">
          Get Started
        </button>
      </div>
    </section>
  );
};

export default LandingSection;
