class Vehicle {
public:
    virtual string getType() = 0;
};

class Car : public Vehicle {
public:
    string getType() override {
        return "Car";
    }
};

class Bike : public Vehicle {
public:
    string getType() override {
        return "Bike";
    }
};

class Truck : public Vehicle {
public:
    string getType() override {
        return "Truck";
    }
};

class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
};

class CarFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Car();
    }
    // Write your code here
};

class BikeFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Bike();
    }
    // Write your code here
};

class TruckFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Truck();
    }
    // Write your code here
};
