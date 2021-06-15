// Include all libraries needed for the program to run correctly
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;
// Declaring variables to hold lengths
const int DOTTS_LENGTH = 50;
const int RECEIPT = 28;
const int MAX_LENGTH = 40;
// Declaring variable to hold the total order cost
double total_order_cost = 0.00;

// Created a function that when called, will create the dots in the welcome message
void dotts()
{

    cout << setw(DOTTS_LENGTH) << setfill('.') << "" << endl;
}

// Created 3 separate functions that when called, will pass in whether item is fragile, and what the order cost is to determine
// what the shipping cost will be.

// I know I can reduce the stress on readability, but I have created these functions knowing they work. Will apply some
// knowledge in the future to this program to make it easier to read
double usa_shipping(string fragile_item, double total_order_cost) {
    if (fragile_item == "Y" && total_order_cost < 50.00) {
        return  8.00;
    }
    else if (fragile_item == "Y" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        return 11.00;
    }
    else if (fragile_item == "Y" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        return 14.00;
    }
    else if (fragile_item == "Y" && total_order_cost > 150) {
        return 0;
    }
    else if (fragile_item == "N" && total_order_cost < 50.00) {
        return 6.00;
    }
    else if (fragile_item == "N" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        return 9.00;
    }
    else if (fragile_item == "N" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        return 12.00;
    }
    else if (fragile_item == "N" && total_order_cost > 150) {
        return 0;
    }
}
double can_shipping(string fragile_item, double total_order_cost)
{
    if (fragile_item == "Y" && total_order_cost < 50.00) {
        return 10.00;
    }
    else if (fragile_item == "Y" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        return 14.00;
    }
    else if (fragile_item == "Y" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        return 17.00;
    }
    else if (fragile_item == "Y" && total_order_cost > 150) {
        return 0;
    }
    else if (fragile_item == "N" && total_order_cost < 50.00) {
        return 8.00;
    }
    else if (fragile_item == "N" && total_order_cost < 50.00) {
        return 8.00;
    }
    else if (fragile_item == "N" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        return 12.00;
    }
    else if (fragile_item == "N" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        return 15.00;
    }
    else if (fragile_item == "N" && total_order_cost > 150) {
        return 0;
    }
}
double aus_shipping(string fragile_item, double total_order_cost)
{
    if (fragile_item == "Y" && total_order_cost < 50.00) {
        return 12.00;
    }
    else if (fragile_item == "Y" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        return 16.00;
    }
    else if (fragile_item == "Y" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        return 19.00;
    }
    else if (fragile_item == "Y" && total_order_cost > 150) {
        return 0;
    }
    else if (fragile_item == "N" && total_order_cost < 50.00) {
        return 10.00;
    }
    else if (fragile_item == "N" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        return 14.00;
    }
    else if (fragile_item == "N" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        return 17.00;
    }
    else if (fragile_item == "N" && total_order_cost > 150) {
        return 0;
    }
}
// Created another destination location called "mars_shipping"
double mars_shipping(string fragile_item, double total_order_cost) {
    if (fragile_item == "Y" && total_order_cost < 50.00) {
        return  20.00;
    }
    else if (fragile_item == "Y" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        return 22.00;
    }
    else if (fragile_item == "Y" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        return 24.00;
    }
    else if (fragile_item == "Y" && total_order_cost > 150) {
        return 0;
    }
    else if (fragile_item == "N" && total_order_cost < 50.00) {
        return 15.00;
    }
    else if (fragile_item == "N" && total_order_cost >= 50.01 && total_order_cost <= 100) {
        return 17.00;
    }
    else if (fragile_item == "N" && total_order_cost >= 100.01 && total_order_cost <= 150) {
        return 19.00;
    }
    else if (fragile_item == "N" && total_order_cost > 150) {
        return 0;
    }
}
// Declaring main function which will run most of the program
int main()
{
// Outputs welcome message
    dotts();
    cout << left << "ITCS 2530 - Programming Assignment for week #3" << endl;
    dotts();
    cout << " " << endl;
// Declare all string variables
    string name_of_item = "";
    string fragile_item = "";
    string location = "";
    string item_name = "Please enter the item name (no spaces)";
    string fragile =  "Is the item fragile? (y=yes/n=no)";
    string order_total = "Please enter your order total";
    string destination = "Please enter destination. (usa/can/aus/mars)";
    string shipping_cost = "Your shipping cost is";
    string shipping_to = "You are shipping to";
    string total_shipping_cost = "Your total shipping costs are";
// This is where the user will input the name of the item and whether or not the item is fragile
    cout << left << item_name << setfill('.') << setw(DOTTS_LENGTH - item_name.length()) << right << ":";
    cin >> name_of_item;
    transform(name_of_item.begin(), name_of_item.end(), name_of_item.begin(), ::toupper);
    cout << fragile << setfill('.') << setw(DOTTS_LENGTH - fragile.length()) << ":";
    cin >> fragile_item;
    // This if function checks if the user enters "n" or "y", and if they dont, the program will end with an error message
    if ((fragile_item != "n") && (fragile_item != "y")){
        cout << endl;
        cout << "Invalid entry, exiting";
        return 1;
    }
    transform(fragile_item.begin(), fragile_item.end(), fragile_item.begin(), ::toupper);
    // This is where the user will enter the total order cost and the location they wish to ship to
    cout << order_total << setfill('.') << setw(DOTTS_LENGTH - order_total.length()) << ":";
    cin >> total_order_cost;
    cout << fixed << setprecision(2);
    cout << destination << setfill('.') << setw(DOTTS_LENGTH - destination.length()) << ":";
    cin >> location;
    transform(location.begin(), location.end(), location.begin(), ::toupper);
    // This if function checks if the user inputs one of the 3 locations, and if not, will return an error message
    if ((location != "USA") && (location != "CAN") && (location != "AUS") && (location != "MARS")){
        cout << endl;
        cout << "Invalid entry, exiting";
        return 1;
    }
    cout << endl;
    // This is where the text file will open and gather all the information that needs to be output to said text file
    ofstream fs;
    fs.open("Order.txt", ios::out);
    cout << "Your item is" << setfill('.') << setw(RECEIPT) << "" << name_of_item << endl;
    fs << "Your item is" << setfill('.') << setw(RECEIPT) << "" << name_of_item << endl;
    // These if/else if functions get the shipping cost and will display it to the user depending on the input they type in
    // These functions also take the output and write it to the text file
    if (location == "USA") {
        cout << shipping_cost << setfill('.') << setw(MAX_LENGTH - shipping_cost.length() + string("$").length()) << "$"
        << usa_shipping(fragile_item, total_order_cost);
        fs << shipping_cost << setfill('.') << setw(MAX_LENGTH - shipping_cost.length() + string("$").length()) << "$"
             << usa_shipping(fragile_item, total_order_cost) << endl;
    }
    else if (location == "CAN"){
        cout << shipping_cost <<  setfill('.') << setw(MAX_LENGTH - shipping_cost.length() + string("$").length()) << "$" <<
        can_shipping(fragile_item, total_order_cost);
        fs << shipping_cost <<  setfill('.') << setw(MAX_LENGTH - shipping_cost.length() + string("$").length()) << "$" <<
             can_shipping(fragile_item, total_order_cost) << endl;
    }
    else if (location == "AUS") {
        cout << shipping_cost << setfill('.') << setw(MAX_LENGTH - shipping_cost.length() + string("$").length()) << "$" <<
             aus_shipping(fragile_item, total_order_cost);
        fs << shipping_cost << setfill('.') << setw(MAX_LENGTH - shipping_cost.length() + string("$").length()) << "$" <<
             aus_shipping(fragile_item, total_order_cost) << endl;
    }
    else if (location == "MARS") {
        cout << shipping_cost << setfill('.') << setw(MAX_LENGTH - shipping_cost.length() + string("$").length()) << "$"
             <<
             mars_shipping(fragile_item, total_order_cost);
        fs << shipping_cost << setfill('.') << setw(MAX_LENGTH - shipping_cost.length() + string("$").length()) << "$"
           <<
           mars_shipping(fragile_item, total_order_cost) << endl;
    }
    cout << endl;
    cout << shipping_to << setfill('.') << setw(MAX_LENGTH - shipping_to.length()) << "" << location << endl;
    fs << shipping_to<< setfill('.') << setw(MAX_LENGTH - shipping_to.length()) << "" << location << endl;
    // These if/else if functions will grab the input from the user and depending on what they input, will call the correct
    // function and will output it to the console and text file
    if (location == "USA") {
        cout << total_shipping_cost << setfill('.') << setw(MAX_LENGTH - total_shipping_cost.length() + string("$").length()) << "$"
             << usa_shipping(fragile_item, total_order_cost) + total_order_cost;
        fs << total_shipping_cost << setfill('.') << setw(MAX_LENGTH - total_shipping_cost.length() + string("$").length()) << "$"
             << usa_shipping(fragile_item, total_order_cost) + total_order_cost << endl;
    }
    else if (location == "CAN"){
        cout << total_shipping_cost <<  setfill('.') << setw(MAX_LENGTH - total_shipping_cost.length() + string("$").length()) << "$" <<
             can_shipping(fragile_item, total_order_cost) + total_order_cost;
        fs << total_shipping_cost <<  setfill('.') << setw(MAX_LENGTH - total_shipping_cost.length() + string("$").length()) << "$" <<
             can_shipping(fragile_item, total_order_cost) + total_order_cost << endl;
    }
    else if (location == "AUS") {
        cout << total_shipping_cost << setfill('.') << setw(MAX_LENGTH - total_shipping_cost.length() + string("$").length()) << "$" <<
             aus_shipping(fragile_item, total_order_cost) + total_order_cost;
        fs << total_shipping_cost << setfill('.') << setw(MAX_LENGTH - total_shipping_cost.length() + string("$").length()) << "$" <<
             aus_shipping(fragile_item, total_order_cost) + total_order_cost << endl;
    }
    else if (location == "MARS") {
        cout << total_shipping_cost << setfill('.')
             << setw(MAX_LENGTH - total_shipping_cost.length() + string("$").length()) << "$" <<
             mars_shipping(fragile_item, total_order_cost) + total_order_cost;
        fs << total_shipping_cost << setfill('.')
           << setw(MAX_LENGTH - total_shipping_cost.length() + string("$").length()) << "$" <<
           mars_shipping(fragile_item, total_order_cost) + total_order_cost << endl;
    }
    // Ending "Thank you" message
    cout << endl;
    cout << setfill('-') << setw(DOTTS_LENGTH) << "Thank you!";
    fs << setfill('-') << setw(DOTTS_LENGTH) << "Thank you!";
    // Close the text file
      fs.close();
      cout << "this is a random line" << endl;
}
