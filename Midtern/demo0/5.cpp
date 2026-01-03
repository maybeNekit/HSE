#include <iostream>
#include <vector>

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

    virtual ~Car() {}

    int getMaxSpeed() const {
        return maxSpeed;
    }

    Model getModel() const {
        return model;
    }

    void setMaxSpeed(int speed) {
        maxSpeed = speed;
    }

    virtual void print() const = 0;
};

class Bus : public Car {
private:
    int cost;

public:
    Bus(int maxSpeed, int c) : Car(maxSpeed, Model::Bus), cost(c) {}

    ~Bus() {}

    int getCost() const {
        return cost;
    }

    void print() const override {
        std::cout << "Model: Bus, max speed: " << getMaxSpeed()
                  << ", ticket cost: " << cost;
    }
};

class RaceCar : public Car {
private:
    double aerodynamics;

public:
    RaceCar(int maxSpeed, double aero) : Car(maxSpeed, Model::RaceCar), aerodynamics(aero) {}

    ~RaceCar() {}

    double getAerodynamics() const {
        return aerodynamics;
    }

    void print() const override {
        std::cout << "Model: RaceCar, max speed: " << getMaxSpeed()
                  << ", aerodynamics: " << aerodynamics;
    }
};

class Truck : public Car {
private:
    int storage;

public:
    Truck(int maxSpeed, int s) : Car(maxSpeed, Model::Truck), storage(s) {}

    ~Truck() {}

    int getStorage() const {
        return storage;
    }

    void print() const override {
        std::cout << "Model: Truck, max speed: " << getMaxSpeed()
                  << ", storage: " << storage;
    }
};

class Garage {
private:
    std::vector<Car*> cars;

public:
    ~Garage() {
        for (Car* car : cars) {
            delete car;
        }
    }

    void add(Car* car) {
        cars.push_back(car);
    }

    void printAll() const {
        for (const auto& car : cars) {
            car->print();
            std::cout << std::endl;
        }
    }

    Car::Model countMostPopular() const {
        int raceCarCount = 0;
        int busCount = 0;
        int truckCount = 0;

        for (const auto& car : cars) {
            switch (car->getModel()) {
                case Car::Model::RaceCar: raceCarCount++; break;
                case Car::Model::Bus:     busCount++; break;
                case Car::Model::Truck:   truckCount++; break;
            }
        }

        if (busCount >= raceCarCount && busCount >= truckCount) {
            return Car::Model::Bus;
        } else if (truckCount >= raceCarCount && truckCount >= busCount) {
            return Car::Model::Truck;
        } else {
            return Car::Model::RaceCar;
        }

        // int maxVal = std::max({raceCarCount, busCount, truckCount});
        // if (maxVal == busCount) return Car::Model::Bus;
        // if (maxVal == truckCount) return Car::Model::Truck;
        // return Car::Model::RaceCar;
    }
};

int main() {
    Garage garage;
    int n;

    if (std::cin >> n) {
        for (int i = 0; i < n; ++i) {
            int modelCode;
            std::cin >> modelCode;

            if (modelCode == 0) {
                int speed;
                double aero;
                std::cin >> speed >> aero;
                garage.add(new RaceCar(speed, aero));
            } else if (modelCode == 1) {
                int speed;
                int cost;
                std::cin >> speed >> cost;
                garage.add(new Bus(speed, cost));
            } else if (modelCode == 2) {
                int speed;
                int storage;
                std::cin >> speed >> storage;
                garage.add(new Truck(speed, storage));
            }
        }
    }

    garage.printAll();

    Car::Model popular = garage.countMostPopular();
    std::cout << "Most popular model: ";
    switch (popular) {
        case Car::Model::RaceCar: std::cout << "RaceCar"; break;
        case Car::Model::Bus:     std::cout << "Bus"; break;
        case Car::Model::Truck:   std::cout << "Truck"; break;
    }
    std::cout << std::endl;

    return 0;
}