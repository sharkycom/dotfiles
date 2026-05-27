#include <iostream>
#include <string>

using namespace std;

class Material {
private:
    string kind;
    string origin;
    double costPerUnit;

public:
    void setKind(string k) { kind = k; }
    void setOrigin(string o) { origin = o; }
    void setCostPerUnit(double c) { costPerUnit = c; }

    string getKind() { return kind; }
    string getOrigin() { return origin; }
    double getCostPerUnit() { return costPerUnit; }

    void printMaterialInfo() {
        cout << "Υλικό: " << kind << ", Προέλευση: " << origin << ", Κόστος: " << costPerUnit << endl;
    }
};

class Worker {
private:
    string name;
    string position;
    int experienceYears;

public:
    void setName(string n) { name = n; }
    void setPosition(string p) { position = p; }
    void setExperienceYears(int e) { experienceYears = e; }

    string getName() { return name; }
    string getPosition() { return position; }
    int getExperienceYears() { return experienceYears; }

    void printWorkerInfo() {
        cout << "Εργαζόμενος: " << name << ", Θέση: " << position << ", Εμπειρία: " << experienceYears << " έτη" << endl;
    }
};

class FurnitureItem {
private:
    string title;
    double size;
    Material usedMaterial;

public:
    void setTitle(string t) { title = t; }
    void setSize(double s) { size = s; }
    void setMaterial(Material m) { usedMaterial = m; }

    string getTitle() { return title; }
    double getSize() { return size; }
    Material getMaterial() { return usedMaterial; }

    void printFurnitureInfo() {
        cout << "Έπιπλο: " << title << ", Μέγεθος: " << size << " τ.μ." << endl;
        usedMaterial.printMaterialInfo();
        cout << "Συνολικό Κόστος: " << size * usedMaterial.getCostPerUnit() << endl;
        cout << "------------------------------------------" << endl;
    }
};

int main() {
    Material m1;
    m1.setKind("Ξύλο");
    m1.setOrigin("Ελλάδα");
    m1.setCostPerUnit(50.0);

    Worker w1;
    w1.setName("Γιώργος");
    w1.setPosition("Ξυλουργός");
    w1.setExperienceYears(10);

    FurnitureItem items[2];

    items[0].setTitle("Τραπέζι");
    items[0].setSize(2.0);
    items[0].setMaterial(m1);

    Material m2;
    m2.setKind("Βαμβάκι");
    m2.setOrigin("Εισαγωγή");
    m2.setCostPerUnit(30.0);

    items[1].setTitle("Φούτερ");
    items[1].setSize(1.0);
    items[1].setMaterial(m2);

    w1.printWorkerInfo();
    cout << endl;

    for(int i = 0; i < 2; i++) {
        items[i].printFurnitureInfo();
    }

    return 0;
}