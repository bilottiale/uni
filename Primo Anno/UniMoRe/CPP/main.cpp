#include <iostream>
#include <string> // Include this header to use std::string

class Car {
public:
    std::string make;

    void accelerate() {
        std::cout << "accelerating" << std::endl;
    }

    void brake() {
        std::cout << "braking" << std::endl; // Fixed typo from "nraking" to "braking"
    }
};

int main() {
    Car car1;
    car1.make = "Toyota";
    std::cout << car1.make << std::endl;

    // Example usage of the methods
    car1.accelerate();
    car1.brake();

    return 0;
}
