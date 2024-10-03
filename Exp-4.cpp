#include <iostream>
using namespace std;

string pt[] = {"Ground", "Air", "Express"};

class Transportation {
private:
    double weight, length, height, width;
    string packageType;
    double cost_weight;

public:
    void set_details(double w, double l, double h, double wi, string pt) {
        if (w >= 0.1 && w <= 50)
            weight = w;
        length = l;
        width = wi;
        height = h;
        packageType = pt;
    }
    void calculateCost(double weight) {
        if (weight >= 0.1 && weight <= 1) {
            cost_weight = 5 + (2 * weight);
        } else if (weight > 1 && weight <= 10) {
            cost_weight = 10 + (1.5 * weight);
        } else {
            cost_weight = 20 + (1 * weight);
        }
    }
    void calculateCost(double length, double width, double height) {
        double volume;
        if ((length >= 10 && length <= 200) || (width >= 10 && width <= 100) || (height >= 10 && height <= 50)) {
            volume = (length / 100) * (width / 100) * (height / 100);

            if (volume < 0.1) {
                cost_weight = 10 + (0.5 * volume);
            } else if (volume < 0.5) {
                cost_weight = 15 + (0.25 * volume);
            } else {
                cost_weight = 25 + (0.1 * volume);
            }
        }
    }
    void calculateCost(string packageType, double weight) {
        if (packageType == "Ground") {
            calculateCost(weight);
        } else if (packageType == "Air") {
            if (weight >= 0.1 && weight <= 1) {
                cost_weight = 10 + (3 * weight);
            } else if (weight > 1 && weight <= 10) {
                cost_weight = 20 + (2 * weight);
            } else {
                cost_weight = 30 + (1.5 * weight);
            }
        } else if (packageType == "Express") {
            if (weight >= 0.1 && weight <= 1) {
                cost_weight = 15 + (4 * weight);
            } else if (weight > 1 && weight <= 10) {
                cost_weight = 30 + (3 * weight);
            } else {
                cost_weight = 40 + (2 * weight);
            }
        }
    }
    double getCost() {
        return cost_weight;
    }
};

int main() {
    Transportation t1;

    // Set details for a package
    t1.set_details(25.5, 150, 40, 20, pt[1]);

    // Calculate cost for Ground
    t1.calculateCost("Ground", 9.0);
    cout << "Ground Cost: " << t1.getCost() << endl;

    // Calculate cost for Air
    t1.calculateCost("Air", 5.0);
    cout << "Air Cost: " << t1.getCost() << endl;

    // Calculate cost for Express
    t1.calculateCost("Express", 7.0);
    cout << "Express Cost: " << t1.getCost() << endl;

    return 0;
}
