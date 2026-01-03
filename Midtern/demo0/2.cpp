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

class Garage {
private:
    std::vector<Car> cars;

public:
    void add(int maxSpeed, Car::Model model) {
        Car c(maxSpeed, model);
        cars.emplace_back(c);
    }

    friend std::ostream& operator<<(std::ostream& os, const Garage& garage) {
        for (size_t i = 0; i < garage.cars.size(); ++i) {
            os << garage.cars[i];
            if (i < garage.cars.size() - 1) {
                os << "\n";
            }
        }
        return os;
    }
};

int main() {
    Garage garage;
    int n;

    if (std::cin >> n) {
        for (int i = 0; i < n; ++i) {
            int speed;
            int modelCode;
            std::cin >> speed >> modelCode;

            Car::Model currentModel = static_cast<Car::Model>(modelCode);
            garage.add(speed, currentModel);
        }
    }

    std::cout << garage << std::endl;

    return 0;
}