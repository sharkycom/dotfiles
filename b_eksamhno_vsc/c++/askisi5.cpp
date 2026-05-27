#include <iostream>
#include <string>

class Customer {
private:
    std::string name;
    std::string phone;

public:
    Customer() : name("Unknown"), phone("0000000000") {
        std::cout << "[Customer] Default Constructor\n";
    }

    Customer(std::string n, std::string p) : name(n), phone(p) {
        std::cout << "[Customer] Parameterized Constructor\n";
    }

    Customer(const Customer& other) : name(other.name), phone(other.phone) {
        std::cout << "[Customer] Copy Constructor\n";
    }

    ~Customer() {
        std::cout << "[Customer] Destructor\n";
    }

    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
};

class Car {
private:
    std::string model;
    std::string plateNumber;

public:
    Car() : model("Generic"), plateNumber("AAA-0000") {
        std::cout << "[Car] Default Constructor\n";
    }

    Car(std::string m, std::string p) : model(m), plateNumber(p) {
        std::cout << "[Car] Parameterized Constructor\n";
    }

    Car(const Car& other) : model(other.model), plateNumber(other.plateNumber) {
        std::cout << "[Car] Copy Constructor\n";
    }

    ~Car() {
        std::cout << "[Car] Destructor\n";
    }

    std::string getModel() const { return model; }
    std::string getPlateNumber() const { return plateNumber; }
};

class Rental {
private:
    Customer customer;
    Car car;
    int days;

public:
    Rental() : customer(), car(), days(0) {
        std::cout << "[Rental] Default Constructor\n";
    }

    Rental(Customer cust, Car c, int d) : customer(cust), car(c), days(d) {
        std::cout << "[Rental] Parameterized Constructor\n";
    }

    Rental(const Rental& other) : customer(other.customer), car(other.car), days(other.days) {
        std::cout << "[Rental] Copy Constructor\n";
    }

    ~Rental() {
        std::cout << "[Rental] Destructor\n";
    }

    void displayInfo() const {
        std::cout << "Customer: " << customer.getName() << " (" << customer.getPhone() << ")\n"
                  << "Car: " << car.getModel() << " (" << car.getPlateNumber() << ")\n"
                  << "Days: " << days << "\n";
    }
};

int main() {
    Customer customer1("Giannis Papadopoulos", "6912345678");
    Car car1("Toyota Yaris", "YNB-1234");
    
    Rental rental1(customer1, car1, 5);
    Rental rental2 = rental1;

    rental1.displayInfo();
    rental2.displayInfo();

    return 0;
}