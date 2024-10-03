#include <iostream>
using namespace std;

double rectangle(double length, double breadth) {
    return length * breadth;
}

double triangle(double height, double base) {
    return 0.5 * height * base;
}

int main() {
    double l, b, area1;
    double h, base, area2;

    cout << "Enter the length and breadth of the rectangle: ";
    cin >> l >> b;

    cout << "Enter the height and base of the triangle: ";
    cin >> h >> base;

    area1 = rectangle(l, b);
    area2 = triangle(h, base);

    cout << "The area of the rectangle is " << area1 << endl;
    cout << "The area of the triangle is " << area2 << endl;

    return 0;
}
