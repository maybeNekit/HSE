#include <iostream>
#include <vector>
#include <string>

class Car {
public:
    enum class Model {
        RaceCar,
        Bus,
        Truck
    };

private:
    int maxSpeed;
    const Model model;

public:
    Car(int speed, Model m) : maxSpeed(speed), model(m) {}

    int getMaxSpeed() const {
        return maxSpeed;
    }

    void setMaxSpeed(int speed) {
        maxSpeed = speed;
    }

    friend std::ostream& operator<<(std::ostream& os, const Car& car) {
        os << "Model: ";
        switch (car.model) {
            case Model::RaceCar: os << "RaceCar"; break;
            case Model::Bus:     os << "Bus"; break;
            case Model::Truck:   os << "Truck"; break;
        }
        os << ", max speed: " << car.getMaxSpeed();
        return os;
    }
};

int main() {
    std::vector<Car> cars;

    for (int i = 0; i < 3; ++i) {
        int speed;
        int modelCode;

        if (std::cin >> speed >> modelCode) {
            Car::Model currentModel = static_cast<Car::Model>(modelCode);
            // Car::Model currentModel;
            // if (modelCode == 0) {
            //     currentModel = Car::Model::RaceCar;
            // } else if (modelCode == 1) {
            //     currentModel = Car::Model::Bus;
            // } else {
            //     currentModel = Car::Model::Truck;
            // }
            cars.emplace_back(speed, currentModel);
        }
    }

    for (const auto& car : cars) {
        std::cout << car << std::endl;
    }

    for (int i = 0; i < 3; ++i) {
        int newSpeed;
        std::cin >> newSpeed;
        cars[i].setMaxSpeed(newSpeed);
    }

    for (const auto& car : cars) {
        std::cout << car << std::endl;
    }

    return 0;
}