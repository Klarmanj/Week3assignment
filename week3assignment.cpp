#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;
const int DOTTS_LENGTH = 50;
const int RECEIPT = 28;
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

double usa_shipping(string fragile_item, double total_order_cost) {
    if (fragile_item == "Y" && total_order_cost < 50.00) {
        ship_to_usa = 8.00;
    }
    else if (fragile_item == "Y" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        ship_to_usa = 11.00;
    }
    else if (fragile_item == "Y" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        ship_to_usa = 14.00;
    }
    else if (fragile_item == "Y" && total_order_cost > 150) {
        ship_to_usa = 0;
    }
    else if (fragile_item == "N" && total_order_cost < 50.00) {
        ship_to_usa = 6.00;
    }
    else if (fragile_item == "N" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        ship_to_usa = 9.00;
    }
    else if (fragile_item == "N" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        ship_to_usa = 12.00;
    }
    else if (fragile_item == "N" && total_order_cost > 150) {
        ship_to_usa = 0;
    }
    return (ship_to_usa);
}
double can_shipping(string fragile_item, double total_order_cost)
{
    if (fragile_item == "Y" && total_order_cost < 50.00) {
        ship_to_canada = 10.00;
    }
    else if (fragile_item == "Y" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        ship_to_canada = 14.00;
    }
    else if (fragile_item == "Y" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        ship_to_canada = 17.00;
    }
    else if (fragile_item == "Y" && total_order_cost > 150) {
        ship_to_canada = 0;
    }
    else if (fragile_item == "N" && total_order_cost < 50.00) {
        ship_to_canada = 8.00;
    }
    else if (fragile_item == "N" && total_order_cost < 50.00) {
        ship_to_canada = 8.00;
    }
    else if (fragile_item == "N" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        ship_to_canada = 12.00;
    }
    else if (fragile_item == "N" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        ship_to_canada = 15.00;
    }
    else if (fragile_item == "N" && total_order_cost > 150) {
        ship_to_canada = 0;
    }
    return (ship_to_canada);
}
double aus_shipping(string fragile_item, double total_order_cost)
{
    if (fragile_item == "Y" && total_order_cost < 50.00) {
        ship_to_aus = 12.00;
    }
    else if (fragile_item == "Y" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        ship_to_aus = 16.00;
    }
    else if (fragile_item == "Y" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        ship_to_aus = 19.00;
    }
    else if (fragile_item == "Y" && total_order_cost > 150) {
        ship_to_aus = 0;
    }
    else if (fragile_item == "N" && total_order_cost < 50.00) {
        ship_to_aus = 10.00;
    }
    else if (fragile_item == "N" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        ship_to_aus = 14.00;
    }
    else if (fragile_item == "N" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        ship_to_aus = 17.00;
    }
    else if (fragile_item == "N" && total_order_cost > 150) {
        ship_to_aus = 0;
    }
    return (ship_to_aus);
}
int main()
{

    dotts();
    cout << left << "ITCS 2530 - Programming Assignment for week #3" << endl;
    dotts();
    cout << " " << endl;

    string item_name = "Please enter the item name (no spaces)";
    string fragile =  "Is the item fragile? (y=yes/n=no)";
    string order_total = "Please enter your order total";
    string destination = "Please enter destination. (usa/can/aus)";
    cout << left << item_name << setfill('.') << setw(DOTTS_LENGTH - item_name.length()) << right << ":";
    cin >> name_of_item;
    transform(name_of_item.begin(), name_of_item.end(), name_of_item.begin(), ::toupper);
    cout << fragile << setfill('.') << setw(DOTTS_LENGTH - fragile.length()) << ":";
    cin >> fragile_item;
    if ((fragile_item != "n") && (fragile_item != "y")){
        cout << endl;
        cout << "Invalid entry, exiting";
        return 1;
    }
    transform(fragile_item.begin(), fragile_item.end(), fragile_item.begin(), ::toupper);
    cout << order_total << setfill('.') << setw(DOTTS_LENGTH - order_total.length()) << ":";
    cin >> total_order_cost;
    cout << fixed << setprecision(2);
    cout << destination << setfill('.') << setw(DOTTS_LENGTH - destination.length()) << ":";
    cin >> location;
    transform(location.begin(), location.end(), location.begin(), ::toupper);
    if ((location != "USA") && (location != "CAN") && (location != "AUS")){
        cout << endl;
        cout << "Invalid entry, exiting";
        return 1;
    }
    cout << endl;

    cout << "Your item is" << setfill('.') << setw(RECEIPT) << "" << name_of_item << endl;
    if (location == "USA") {
        cout << "Your shipping cost is" << setfill('.') << setw(20) << "$"
        << usa_shipping(fragile_item, total_order_cost);
    }
    else if (location == "CAN"){
        cout << "Your shipping cost is" <<  setfill('.') << setw(20) << "$" <<
        can_shipping(fragile_item, total_order_cost);
    }
    else if (location == "AUS") {
        cout << "Your shipping cost is" << setfill('.') << setw(20) << "$" <<
             aus_shipping(fragile_item, total_order_cost);
    }
    cout << endl;
    cout << "You are shipping to" << setfill('.') << setw(21) << "" << location << endl;
    if (location == "USA") {
        cout << "Your total shipping costs are" << setfill('.') << setw(12) << "$"
             << usa_shipping(fragile_item, total_order_cost) + total_order_cost;
    }
    else if (location == "CAN"){
        cout << "Your total shipping costs are" <<  setfill('.') << setw(12) << "$" <<
             can_shipping(fragile_item, total_order_cost) + total_order_cost;
    }
    else if (location == "AUS") {
        cout << "Your total shipping costs are" << setfill('.') << setw(12) << "$" <<
             aus_shipping(fragile_item, total_order_cost) + total_order_cost;
    }
    cout << endl;
    cout << setfill('-') << setw(50) << "Thank you!";

//    ifstream fs;
//    fs.open("Order.txt", ios::in | ios::out | ios::binary);
//    if (fs.is_open())
//        fs << "You are shipping to" << setfill('.') << setw(21) << "" << location << endl;
//    fs.close();
}
