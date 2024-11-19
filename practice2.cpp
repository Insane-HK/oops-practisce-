#include <iostream>
using namespace std;

class Sample {
 
   protected:
    int age;
};


class SampleChild : public Sample {

   public:
    void displayAge(int a) {
        age = a;
        cout << "Age = " << age << endl;
    }

};

int main() {
    int ageInput;

    SampleChild child;

    cout << "Enter your age: ";
    cin >> ageInput;


    child.displayAge(ageInput);

    return 0;
}
