#include <iostream>

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

    int getCost() const {
        return cost;
    }

    void print() const override {
        std::cout << "Model: Bus, max speed: " << getMaxSpeed()
                  << ", ticket cost: " << cost;
    }

    ~Bus() {}
};

int main() {
    int speed, cost;
    if (std::cin >> speed >> cost) {
        Bus bus(speed, cost);

        bus.print();
        std::cout << std::endl;

        int newSpeed;
        if (std::cin >> newSpeed) {
            bus.setMaxSpeed(newSpeed);

            bus.print();
            std::cout << std::endl;
        }
    }

    return 0;
}