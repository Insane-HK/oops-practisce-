#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    int age;
    double marks;
};

int main() {
    Student students[10] = {
        {1, "A", 20, 85.5},
        {2, "B", 21, 90.0},
        {3, "C", 22, 78.0},
        {4, "D", 19, 92.5},
        {5, "E", 20, 88.0},
        {6, "F", 21, 75.5},
        {7, "G", 22, 80.0},
        {8, "H", 20, 95.0},
        {9, "I", 21, 82.0},
        {10, "J", 19, 87.5}
    };

    cout << "Details of all students:\n";
    for (int i = 0; i < 10; ++i) {
        cout << "Roll No: " << students[i].rollNo << ", "
             << "Name: " << students[i].name << ", "
             << "Age: " << students[i].age << ", "
             << "Marks: " << students[i].marks << endl;
    }

    return 0;
}
