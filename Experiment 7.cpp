#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Item {
private:
    string name;
    int quantity;
    double price;

public:
    Item(string n, int q, double p) : name(n), quantity(q), price(p) {}

    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    void setQuantity(int q) { quantity = q; }
    void setPrice(double p) { price = p; }

    void display() const {
        cout << left << setw(20) << name
             << setw(10) << quantity
             << fixed << setprecision(2) << "$" << price << endl;
    }

    double getTotalPrice() const {
        return quantity * price;
    }
};

class ShoppingList {
private:
    vector<Item> items;

public:
    ShoppingList() {
        cout << "Shopping List Initialized." << endl;
    }

    void addItem(const string& name, int quantity, double price) {
        items.emplace_back(name, quantity, price);
        cout << "Item added: " << name << endl;
    }

    void updateItem(const string& name, int quantity, double price) {
        for (auto& item : items) {
            if (item.getName() == name) {
                item.setQuantity(quantity);
                item.setPrice(price);
                cout << "Item updated: " << name << endl;
                return;
            }
        }
        cout << "Item not found: " << name << endl;
    }

    void removeItem(const string& name) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getName() == name) {
                items.erase(it);
                cout << "Item removed: " << name << endl;
                return;
            }
        }
        cout << "Item not found: " << name << endl;
    }

    void displayList() const {
        if (items.empty()) {
            cout << "Shopping list is empty." << endl;
            return;
        }
        cout << left << setw(20) << "Item Name" << setw(10) << "Quantity" << "Price" << endl;
        cout << "-----------------------------------------------------" << endl;
        for (const auto& item : items) {
            item.display();
        }
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.getTotalPrice();
        }
        return total;
    }
};

int main() {
    ShoppingList shoppingList;

    shoppingList.addItem("Apple", 5, 0.99);
    shoppingList.addItem("Milk", 2, 1.49);
    shoppingList.displayList();

    shoppingList.updateItem("Apple", 10, 0.89);
    shoppingList.removeItem("Milk");
    shoppingList.displayList();

    cout << "Total Price: $" << fixed << setprecision(2) << shoppingList.calculateTotal() << endl;

    return 0;
}
