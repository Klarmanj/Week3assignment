#include <iostream>
#include <iomanip>

using namespace std;

void dotts() {

    cout << setw(50) << setfill('.') << "" << endl;
}
int main()
{
    dotts();
    cout << left << "ITCS 2530 - Programming Assignment for week #3" << endl;
    dotts();
    cout << " " << endl;

    cout << left << "Please enter the item name: (no spaces)" << endl;
    cout << "Is the item fragile? (y=yes/n=no)" << endl;
    cout << "Please enter your order total" << endl;
    cout << "Please enter destination" << endl << endl;

    cout << "Your item is" << endl;
    cout << "Your shipping cost is" << endl;
    cout << "You are shipping to" << endl;
    cout << "Your total shipping costs are" << endl;
}
