#include <iostream>
using namespace std;

class Electricity
{
private:
    double bill;

public:
    void payment(double unit)
    {
        if (unit > 0 && unit <= 100)
        {
            bill = unit * 1.5;
        }
        else if (unit > 100 && unit <= 200)
        {
            bill = unit * 2;
        }
        else if (unit > 200 && unit <= 300)
        {
            bill = unit * 3;
        }
        else
        {
            bill = 0; // Handle negative or zero units
        }
    }

    void displayBill() const
    {
        cout << "Total Bill: " << bill << endl;
    }
};

int main()
{
    Electricity A;
    double n; // Changed to double for more accurate input
    cout << "Enter the amount of electricity units used: ";
    cin >> n;

    A.payment(n);    // Pass the input to the payment method
    A.displayBill(); // Display the calculated bill

    return 0;
}
