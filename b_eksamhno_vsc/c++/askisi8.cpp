#include <iostream>
#include <string>

using namespace std;

class Customer {
private:
    string name;

public:
    Customer() {
        name = "Unknown";
    }

    Customer(string n) {
        name = n;
    }

    ~Customer() {
        cout << "Destructor Customer: " << name << endl;
    }

    string getName() {
        return name;
    }
};

class Product {
protected:
    int id;
    string name;
    double basePrice;

public:
    Product() {
        id = 0;
        name = "Unknown";
        basePrice = 0.0;
    }

    Product(int i, string n, double p) {
        id = i;
        name = n;
        basePrice = p;
    }

    virtual ~Product() {
        cout << "Destructor Product: " << name << endl;
    }

    virtual double getFinalPrice() {
        return basePrice;
    }

    string getName() {
        return name;
    }
};

class FragileProduct : public Product {
private:
    double packagingCost;

public:
    FragileProduct() : Product() {
        packagingCost = 0.0;
    }

    FragileProduct(int i, string n, double p, double pc) : Product(i, n, p) {
        packagingCost = pc;
    }

    ~FragileProduct() {
        cout << "Destructor FragileProduct: " << name << endl;
    }

    double getFinalPrice() override {
        return basePrice + packagingCost;
    }
};

class Supplier {
private:
    string companyName;

public:
    Product* products[3];

    Supplier() {
        companyName = "Unknown";
        for (int i = 0; i < 3; i++) {
            products[i] = nullptr;
        }
    }

    Supplier(string name, Product* p1, Product* p2, Product* p3) {
        companyName = name;
        products[0] = p1;
        products[1] = p2;
        products[2] = p3;
    }

    ~Supplier() {
        cout << "Destructor Supplier: " << companyName << endl;
    }

    string getCompanyName() {
        return companyName;
    }
};

class Order {
private:
    Customer* customer;
    Supplier* supplier;
    int quantity;

public:
    Order() {
        customer = nullptr;
        supplier = nullptr;
        quantity = 0;
    }

    Order(Customer* c, Supplier* s, int q) {
        customer = c;
        supplier = s;
        quantity = q;
    }

    Order(const Order& other) {
        customer = other.customer;
        supplier = other.supplier;
        quantity = other.quantity;
        cout << "Copy Constructor: Δημιουργήθηκε αρχείο παραγγελίας." << endl;
    }

    ~Order() {
        cout << "Destructor Order" << endl;
    }

    void displayOrderDetails() {
        if (customer != nullptr && supplier != nullptr) {
            cout << "Πελάτης: " << customer->getName() 
                 << ", Προμηθευτής: " << supplier->getCompanyName() 
                 << ", Ποσότητα: " << quantity << endl;
        }
    }
};

int main() {
    Product p1(1, "Τραπέζι", 120.0);
    Product p2(2, "Καρέκλα", 40.0);
    FragileProduct p3(3, "Καθρέφτης", 70.0, 15.0);

    Supplier sup("Έπιπλα ΑΕ", &p1, &p2, &p3);

    Customer cust("Γιώργος");

    cout << "--- Δημιουργία Παραγγελίας ---" << endl;
    Order ord1(&cust, &sup, 10);
    ord1.displayOrderDetails();

    cout << "\n--- Αρχειοθέτηση Παραγγελίας (Copy Constructor) ---" << endl;
    Order archiveOrder = ord1;
    archiveOrder.displayOrderDetails();

    cout << "\n--- Αποδέσμευση Αντικειμένων ---" << endl;
    return 0;
}