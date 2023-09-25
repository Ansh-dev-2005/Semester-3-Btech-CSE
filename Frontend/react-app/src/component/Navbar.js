import React from "react";
import { Disclosure, Menu, Transition } from "@headlessui/react";
import { BellIcon, XMarkIcon } from "@heroicons/react/24/outline";
import { FaFilm, FaHouseUser, FaUtensils, FaMap, FaShoppingBag } from "react-icons/fa";

const navigation = [
  { name: "Home", href: "/", current: true, icon: <FaHouseUser className="mr-2" /> },
  { name: "Entertainment", href: "/Entertainment", current: false, icon: <FaFilm className="mr-2" /> },
  { name: "Restaurants", href: "/Restaurants", current: false, icon: <FaUtensils className="mr-2" /> },
  { name: "Tourist Places", href: "/TouristPlaces", current: false, icon: <FaMap className="mr-2" /> },
  { name: "Shopping", href: "/Shopping", current: false, icon: <FaShoppingBag className="mr-2" /> },
];

function classNames(...classes) {
  return classes.filter(Boolean).join(" ");
}

export default function Navbar() {
  return (
    <Disclosure as="nav" className="bg-gray-800">
      {({ open }) => (
        <>
          <div className="mx-auto max-w-7xl px-4 sm:px-6 lg:px-8">
            <div className="flex h-16 items-center justify-between">
              <div className="flex items-center">
                <div className="flex-shrink-0">
                  <p className="text-white">Dehradun</p>
                </div>
                <div className="hidden md:block">
                  <div className="ml-10 flex items-baseline space-x-4">
                    {navigation.map((item) => (
                      <a
                        key={item.name}
                        href={item.href}
                        className={classNames(
                          item.current
                            ? "bg-gray-900 text-white"
                            : "text-gray-300 hover:bg-gray-700 hover:text-white",
                          "rounded-md px-3 py-2 text-sm font-medium flex items-center"
                        )}
                        aria-current={item.current ? "page" : undefined}
                      >
                        {item.icon} {item.name}
                      </a>
                    ))}
                  </div>
                </div>
              </div>
              {/* ... Rest of your navbar code */}
            </div>
          </div>
          {/* ... Rest of your navbar code */}
        </>
      )}
    </Disclosure>
  );
}
