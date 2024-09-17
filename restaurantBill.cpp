#include <iostream>
#include <cmath>

#define SUBCHARGE_RATE 0.05 
#define TAX_RATE 0.0875
void input_recieve(double& subtotal);
void caculate_subcharge(double subtotal, double& subcharge);
void caculate_tax(double subtotal, double subcharge, double& tax);
void caculate_total(double subtotal, double subcharge, double tax, double& total);
void print_bill(double subtotal, double subcharge, double tax, double total);

int main() {
	double subtotal, subcharge, tax, total;

	input_recieve(subtotal);
	//std::cout << subtotal << std::endl;
	caculate_subcharge(subtotal, subcharge);
	//std::cout << subcharge << std::endl;
	caculate_tax(subtotal, subcharge, tax);
	//std::cout << tax << std::endl;
	caculate_total(subtotal, subcharge, tax, total);
	//std::cout << total << std::endl;
	print_bill(subtotal, subcharge, tax, total);

}
//
//This module recieve input from user
//
void input_recieve(double &subtotal) {
	std::cout << "Enter subtotal: ";
	std::cin >> subtotal;
	while (true) {
		//check if input operation failed
		if (std::cin.fail()) { //if fail
			std::cin.clear();// Clear the error flags on the input stream.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // leave the rest of the line or clear buffer line
			std::cout << "Please enter a number: "; //ask user enter new value
			std::cin >> subtotal;
		}
		else {
			break;
		}
	}
}
//
//this module caculate the subchager
//
void caculate_subcharge(double subtotal, double &subcharge) {
	subcharge = subtotal * SUBCHARGE_RATE;
	subcharge = std::round(subcharge * 100) / 100;
}
//
//this module caculate tax of subtotal +subcharge
//
void caculate_tax(double subtotal, double subcharge, double& tax) {
	tax = (subcharge + subtotal) * TAX_RATE;
	tax = std::round(tax * 100.0) / 100.0;

}
//
//this module caculate total bill
//
void caculate_total(double subtotal, double subcharge, double tax, double& total) {
	total = subcharge + subtotal + tax;
}
//
//this module print out the bill
//
void print_bill(double subtotal, double subcharge, double tax, double total) {
	std::cout << "Subtotal: $" << subtotal << std::endl;
	std::cout << "Lingving Wage Subcharge(5.00%): $" << subcharge << std::endl;
	std::cout << "Tax(8.75%): $" << tax << std::endl;
	std::cout << "Total: $" << total << std::endl;



}