#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    double salary;

public:
    Employee(string n, double s) {
        name = n;
        salary = s;
    }

    void displayInfo() {
        cout << "Όνομα: " << name << endl;
        cout << "Βασικός Μισθός: " << salary << endl;
    }
};

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string n, double s, double b) : Employee(n, s) {
        bonus = b;
    }

    void displayManagerInfo() {
        displayInfo();
        cout << "Συνολικό Ποσό (Μισθός + Bonus): " << salary + bonus << endl;
    }
};

int main() {
    Employee ypallilos("Γιάννης", 1200.0);
    cout << "--- Στοιχεία Υπαλλήλου ---" << endl;
    ypallilos.displayInfo();

    cout << endl;

    Manager dieuthintis("Μαρία", 2000.0, 500.0);
    cout << "--- Στοιχεία Διευθυντή ---" << endl;
    dieuthintis.displayManagerInfo();

    return 0;
}