#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;
int dotts_length = 50;
int receipt = 28;
string name_of_item = "";
string fragile_item = "";
string location = "";
const double SHIPPING_COST = 2.00;
double ship_to_usa = 0;
double ship_to_canada = 0;
double ship_to_aus = 0;
double total_order_cost = 0.00;
double cost = 0;


void dotts()
{

    cout << setw(50) << setfill('.') << "" << endl;
}

double shipping() {
    if (fragile_item == "y" || "Y" && total_order_cost < 50.00) {
        ship_to_usa = 8.00;
        ship_to_canada = 10.00;
        ship_to_aus = 12.00;
    }
    else if (fragile_item == "y" || "Y" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        ship_to_usa = 11.00;
        ship_to_canada = 14.00;
        ship_to_aus = 16.00;
    }
    else if (fragile_item == "y" || "Y" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        ship_to_usa = 14.00;
        ship_to_canada = 17.00;
        ship_to_aus = 19.00;
    }
    else if (fragile_item == "y" || "Y" && total_order_cost > 150) {
        ship_to_usa = 0;
        ship_to_canada = 0;
        ship_to_aus = 0;
    }
    else if (fragile_item == "n" || "N" && total_order_cost < 50.00) {
        ship_to_usa = 6.00;
        ship_to_canada = 8.00;
        ship_to_aus = 10.00;
    }
    return cost;
}
int main()
{
    dotts();
    cout << left << "ITCS 2530 - Programming Assignment for week #3" << endl;
    dotts();
    cout << " " << endl;
    string glassware = "Glassware";

    string item_name = "Please enter the item name (no spaces)";
    string fragile =  "Is the item fragile? (y=yes/n=no)";
    string order_total = "Please enter your order total";
    string destination = "Please enter destination. (usa/can/aus)";
    cout << left << item_name << setfill('.') << setw(dotts_length - item_name.length()) << right << ":";
    cin >> name_of_item;
    cout << fragile << setfill('.') << setw(dotts_length - fragile.length()) << ":";
    cin >> fragile_item;
    cout << order_total << setfill('.') << setw(dotts_length - order_total.length()) << ":";
    cin >> total_order_cost;
    cout << fixed << setprecision(2);
    shipping();
    cout << destination << setfill('.') << setw(dotts_length - destination.length()) << ":";
    cin >> location;
    cout << endl;

    cout << "Your item is" << setfill('.') << setw(receipt) << "" << name_of_item << endl;
    cout << "Your shipping cost is" << cost << endl;
    cout << "You are shipping to" << endl;
    cout << "Your total shipping costs are" << endl;
}
