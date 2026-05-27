#include <iostream>
#include <string>
using namespace std;

void applyDiscount(double &price) {
    price *= 0.9;
}
int main() {
    int n;
    cout << "Πόσα προϊόντα θέλετε να καταχωρήσετε; ";
    cin >> n;
    string* names = new string[n];
    double* prices = new double[n];
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "--- Εισαγωγή Προϊόντος " << i + 1 << " ---" << endl;
        cout << "Δώστε όνομα προϊόντος: ";
        getline(cin, names[i]);
        cout << "Δώστε τιμή: ";
        cin >> prices[i];
        cin.ignore();
    }

    cout << "==== ΚΑΤΑΛΟΓΟΣ ΠΡΟΪΟΝΤΩΝ ====" << endl;
    for (int i = 0; i < n; i++) {
        cout.setf(ios::left, ios::adjustfield);
        cout.fill('.');
        cout.width(25);
        cout << names[i];
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << prices[i] << " €" << endl;
    }

    for (int i = 0; i < n; i++) {
        applyDiscount(prices[i]);
    }

    cout << "==== ΕΚΠΤΩΣΗ 10% ΣΕ ΟΛΑ ====" << endl;
    for (int i = 0; i < n; i++) {
        cout.setf(ios::left, ios::adjustfield);
        cout.fill('.');
        cout.width(25);
        cout << names[i];
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << prices[i] << " €" << endl;
    }

    string searchTerm;
    cout << "Δώστε λέξη για αναζήτηση: ";
    getline(cin, searchTerm);

    for (int i = 0; i < n; i++) {
        if (names[i].find(searchTerm) != string::npos) {
            cout << "Βρέθηκε: " << names[i] << " με τιμή ";
            cout.setf(ios::fixed, ios::floatfield);
            cout.precision(2);
            cout << prices[i] << " €" << endl;
        }
    }
    delete[] names;
    delete[] prices;
    return 0;
}


