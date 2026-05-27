#include <iostream>
#include <string>

using namespace std;

class Material {
private:
    string kind;
    string origin;
    double costPerUnit;
public:
    Material(string k, string o, double c) : kind(k), origin(o), costPerUnit(c) {}
    string getKind() { return kind; }
    void setKind(string k) { kind = k; }
    string getOrigin() { return origin; }
    void setOrigin(string o) { origin = o; }
    double getCostPerUnit() { return costPerUnit; }
    void setCostPerUnit(double c) { costPerUnit = c; }
    void printMaterialInfo() {
        cout << "Material: " << kind << ", Origin: " << origin << ", Cost per unit: " << costPerUnit << endl;
    }
};

class Worker {
private:
    string name;
    string position;
    int experienceYears;
public:
    Worker(string n, string p, int e) : name(n), position(p), experienceYears(e) {}
    string getName() { return name; }
    void setName(string n) { name = n; }
    string getPosition() { return position; }
    void setPosition(string p) { position = p; }
    int getExperienceYears() { return experienceYears; }
    void setExperienceYears(int e) { experienceYears = e; }
    void printWorkerInfo() {
        cout << "Worker: " << name << ", Position: " << position << ", Experience: " << experienceYears << " years" << endl;
    }
};

class FurnitureItem {
private:
    string title;
    double size;
    Material usedMaterial;
public:
    FurnitureItem(string t, double s, Material m) : title(t), size(s), usedMaterial(m) {}
    string getTitle() { return title; }
    void setTitle(string t) { title = t; }
    double getSize() { return size; }
    void setSize(double s) { size = s; }
    Material getUsedMaterial() { return usedMaterial; }
    void setUsedMaterial(Material m) { usedMaterial = m; }
    void printFurnitureInfo() {
        cout << "Furniture: " << title << ", Size: " << size << " sqm" << endl;
        usedMaterial.printMaterialInfo();
        double totalCost = size * usedMaterial.getCostPerUnit();
        cout << "Total Cost: " << totalCost << endl;
    }
};

int main() {
    Material mat1("Wood", "Forest", 10.0);
    Material mat2("Metal", "Factory", 15.0);
    Worker worker("John", "Carpenter", 5);
    
    FurnitureItem items[2] = {
        FurnitureItem("Chair", 2.0, mat1),
        FurnitureItem("Table", 5.0, mat2)
    };
    
    for (int i = 0; i < 2; i++) {
        items[i].printFurnitureInfo();
        cout << endl;
    }
    
    return 0;
}