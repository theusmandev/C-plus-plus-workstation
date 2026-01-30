#include <iostream>
#include <string>
using namespace std;

// Generic template for delivery vehicles
template <typename VehicleType, typename FuelType>
class DeliveryVehicle {
private:
    VehicleType name;
    FuelType fuel;

public:
    DeliveryVehicle(VehicleType n, FuelType f) : name(n), fuel(f) {}

    void print() {
        cout << "General Delivery Vehicle: " << name 
             << ", Fuel Type: " << fuel << endl;
    }
};

// Full specialization for Trucks (VehicleType = string, FuelType = string)
template <>
class DeliveryVehicle<string, string> {
private:
    string name;
    string fuel;

public:
    DeliveryVehicle(string n, string f) : name(n), fuel(f) {}

    void print() {
        cout << "Truck Delivery Vehicle: " << name 
             << ", Fuel Type: " << fuel << endl;
    }
};

// Full specialization for Electric Bicycles (VehicleType = string, FuelType = const char*)
template <>
class DeliveryVehicle<string, const char*> {
private:
    string name;
    const char* fuel;

public:
    DeliveryVehicle(string n, const char* f) : name(n), fuel(f) {}

    void print() {
        cout << "Electric Bicycle Delivery Vehicle: " << name 
             << ", Fuel Type: " << fuel << endl;
    }
};

int main() {
    // Generic delivery vehicle (motorbike)
    DeliveryVehicle<string, string> truck("BigTruck", "Diesel");
    DeliveryVehicle<string, string> bike("Motorbike", "Petrol");

    // Specialized electric bicycle
    DeliveryVehicle<string, const char*> eBike("E-Bike", "Electric");

    cout << "--- Vehicles ---\n";
    truck.print();   // Specialized truck template
    bike.print();    // Specialized truck template as VehicleType=string, FuelType=string
    eBike.print();   // Specialized electric bicycle template

    // Generic vehicle with other types
    DeliveryVehicle<int, string> drone(101, "Battery");
    drone.print();

    return 0;
}

