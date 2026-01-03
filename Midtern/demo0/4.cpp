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


    double getAerodynamics() const {
        return aerodynamics;
    }
    ~RaceCar() {}

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

    int getStorage() const {
        return storage;
    }

    ~Truck() {}

    void print() const override {
        std::cout << "Model: Truck, max speed: " << getMaxSpeed()
                  << ", storage: " << storage;
    }
};

class Garage {
private:
    std::vector<Car*> cars;

public:

    void add(Car* car) {
        cars.push_back(car);
    }

    void printAll() const {
        for (const auto& car : cars) {
            car->print();
            std::cout << std::endl;
        }
    }
    ~Garage() {
        for (const auto& car : cars) {
            delete car;
        }
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

    return 0;
}