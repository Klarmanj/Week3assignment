#include <iostream>
#include <iomanip>

using namespace std;
void dotts()
{
    cout << setw(50) << setfill('.') << "" << endl;
}
int main()
{
    dotts();
    cout << left << "ITCS 2530 - Programming Assignment for week #3" << endl;
    dotts();
    cout << " ";

    cout << left << "Please enter the item name: (no spaces)" << endl;
    cout << left << "Is the item fragile? (y=yes/n=no)";

}
