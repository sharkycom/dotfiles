#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    string brand;
    string model;
    int year;
    double mileage;

public:
    void setBrand(string b) { brand = b; }
    string getBrand() { return brand; }
    void setModel(string m) { model = m; }
    string getModel() { return model; }
    void setYear(int y) { year = y; }
    int getYear() { return year; }
    void setMileage(double m) { mileage = m; }
    double getMileage() { return mileage; }

    void printVehicleInfo() {
        cout << "Brand: " << brand << ", Model: " << model 
             << ", Year: " << year << ", Mileage: " << mileage << " km" << endl;
    }
};

class Driver {
private:
    string name;
    string licenseNumber;
    Vehicle assignedVehicles[3];

public:
    void setName(string n) { name = n; }
    string getName() { return name; }
    void setLicenseNumber(string ln) { licenseNumber = ln; }
    string getLicenseNumber() { return licenseNumber; }

    void setVehicleAt(int i, Vehicle v) {
        if (i >= 0 && i < 3) {
            assignedVehicles[i] = v;
        }
    }

    void printDriverInfo() {
        cout << "Driver Name: " << name << ", License: " << licenseNumber << endl;
        for (int i = 0; i < 3; i++) {
            cout << "  Vehicle " << i + 1 << ": ";
            assignedVehicles[i].printVehicleInfo();
        }
    }
};

int main() {
    Vehicle v1, v2, v3, v4, v5, v6;

    v1.setBrand("Toyota"); v1.setModel("Corolla"); v1.setYear(2020); v1.setMileage(50000);
    v2.setBrand("Honda"); v2.setModel("Civic"); v2.setYear(2021); v2.setMileage(30000);
    v3.setBrand("Ford"); v3.setModel("Focus"); v3.setYear(2019); v3.setMileage(70000);
    v4.setBrand("BMW"); v4.setModel("X3"); v4.setYear(2022); v4.setMileage(20000);
    v5.setBrand("Audi"); v5.setModel("A4"); v5.setYear(2023); v5.setMileage(10000);
    v6.setBrand("VW"); v6.setModel("Golf"); v6.setYear(2021); v6.setMileage(40000);

    Driver drivers[2];

    drivers[0].setName("Giannis");
    drivers[0].setLicenseNumber("A12345");
    drivers[0].setVehicleAt(0, v1);
    drivers[0].setVehicleAt(1, v2);
    drivers[0].setVehicleAt(2, v3);

    drivers[1].setName("Maria");
    drivers[1].setLicenseNumber("B67890");
    drivers[1].setVehicleAt(0, v4);
    drivers[1].setVehicleAt(1, v5);
    drivers[1].setVehicleAt(2, v6);

    for (int i = 0; i < 2; i++) {
        drivers[i].printDriverInfo();
        cout << "------------------------------------------" << endl;
    }

    return 0;
}