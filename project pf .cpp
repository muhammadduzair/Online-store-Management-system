#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    string category;
    int stock;
};

int main() {
    // Product database
    Product products[5] = {
        {101, "Laptop", "Electronics", 10},
        {102, "Smartphone", "Electronics", 20},
        {103, "Coffee Maker", "Kitchen", 15},
        {104, "Blender", "Kitchen", 5},
        {105, "Desk Lamp", "Home", 7}
    };

    // Pointer to structure array
    Product* ptr = products;

    int productID, quantity;
    string customerName;

    cout << "=============================\n";
    cout << "   SIMPLE ONLINE STORE\n";
    cout << "=============================\n";

    cout << "\nEnter your name: ";
    getline(cin, customerName);

    cout << "\nAvailable Products:\n";
    cout << "ID\tName\t\tCategory\tStock\n";
    cout << "-------------------------------------------\n";

    // Accessing array using pointer
    for (int i = 0; i < 5; i++) {
        cout << (ptr + i)->id << "\t"
             << (ptr + i)->name << "\t"
             << (ptr + i)->category << "\t\t"
             << (ptr + i)->stock << endl;
    }

    cout << "\nEnter Product ID to buy: ";
    cin >> productID;

    cout << "Enter quantity: ";
    cin >> quantity;

    bool found = false;

    for (int i = 0; i < 5; i++) {
        if ((ptr + i)->id == productID) {
            found = true;

            if ((ptr + i)->stock >= quantity) {
                (ptr + i)->stock -= quantity;

                cout << "\n? Order Successful!\n";
                cout << "Customer: " << customerName << endl;
                cout << "Product: " << (ptr + i)->name << endl;
                cout << "Quantity: " << quantity << endl;
                cout << "Remaining Stock: " << (ptr + i)->stock << endl;
            } else {
                cout << "\n? Not enough stock available!\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "\n? Product not found!\n";
    }

    cout << "\nThank you for shopping with us!\n";
    return 0;
}