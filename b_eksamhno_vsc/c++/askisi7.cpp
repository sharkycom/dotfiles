#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(string b, int y) {
        brand = b;
        year = y;
    }
};

class Truck : public Vehicle {
private:
    double loadCapacity;

public:
    Truck(string b, int y, double lc) : Vehicle(b, y) {
        loadCapacity = lc;
    }

    void displayInfo() {
        cout << "Μάρκα: " << brand << ", Έτος: " << year 
             << ", Χωρητικότητα: " << loadCapacity << " τόνοι" << endl;
    }

    double getLoadCapacity() {
        return loadCapacity;
    }
};

int main() {
    Truck trucks[2] = {
        Truck("Volvo", 2018, 12.5),
        Truck("Mercedes", 2021, 18.0)
    };

    double totalCapacity = 0;

    for (int i = 0; i < 2; i++) {
        cout << "--- Φορτηγό " << i + 1 << " ---" << endl;
        trucks[i].displayInfo();
        totalCapacity += trucks[i].getLoadCapacity();
    }

    cout << "\nΣυνολική Ικανότητα Μεταφοράς: " << totalCapacity << " τόνοι" << endl;

    return 0;
}