/* File: MP1.cpp
*  Author: Arin Santry
*  Date started: 9/7/18
*  Date due: 9/27/18
*  Desc: Calculate cost of donut purchase, change due, and change to be given
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
	int regDonuts; //number of regular donuts purchased
	int dozenReg; //number of dozens of regular donuts
	int remainReg; //remainder after converting to dozens
	int fancyDonuts; //number of fancy donuts purchased
	int dozenFancy; //number of dozens of fancy dozens
	int remainFancy; //remainder after converting to dozens
	const int REG_PRICE = 75; //regular donuts cost 75 cents
	const int REG_DOZEN = 799; //cost of 12 regular donuts in cents
	const int FANCY_PRICE = 85; //fancy donuts cost 85 cents
	const int FANCY_DOZEN = 849; //cost of 12 fancy donuts in cents

	cout << "Number of regular donuts ordered: ";
	cin >> regDonuts;
	cout << "Number of fancy donuts ordered: ";
	cin >> fancyDonuts;

	//convert into dozens
	dozenReg = regDonuts / 12;
	dozenFancy = fancyDonuts / 12;

	//use modulo to find remainder
	remainReg = regDonuts % 12;
	remainFancy = fancyDonuts % 12;

	//calculate cost, still all in cents
	int netCost;
	int change;

	//for payment
	int dollarsPaid; //will be in cents
	int centsPaid;
	char period;

	netCost = (dozenReg * REG_DOZEN + remainReg * REG_PRICE + dozenFancy * FANCY_DOZEN + remainFancy * FANCY_PRICE);

	cout << "Customer owes $" << netCost / 100 << "." << setw(2) << setfill('0') << netCost % 100 << endl;
	cout << "Customer pays $";
	cin >> dollarsPaid >> period >> centsPaid;

	int totalPaid = dollarsPaid * 100 + centsPaid;

	change = totalPaid - netCost;

	if (change == 0)
		cout << "Exact payment received, no change owed.";
	else
		cout << "Change owed is $" << change / 100 << "." << setw(2) << setfill('0') << change % 100 << " - ";

	//find change coins
	int dollars;
	int quarters;
	int dimes;
	int nickles;
	int pennies;

	dollars = change / 100;
	change -= dollars * 100;
	quarters = change / 25;
	change -= quarters * 25;
	dimes = change / 10;
	change -= dimes * 10;
	nickles = change / 5;
	change -= nickles * 5;
	pennies = change;

	//print out change owed
	if (dollars > 0)
	{
		cout << dollars << " dollar";
		if (dollars > 1)
			cout << "s";
		if (quarters > 0 || dimes > 0 || nickles > 0 || pennies > 0)  //if there are coins remaining, add a comma, if not, add a period
			cout << ", ";
		else
			cout << ".";
	}
	if (quarters > 0)
	{
		cout << quarters << " quarter";
		if (quarters > 1)
			cout << "s";
		if (dimes > 0 || nickles > 0 || pennies > 0)
			cout << ", ";
		else
			cout << ".";
	}
	if (dimes > 0)
	{
		cout << dimes << " dime";
		if (dimes > 1)
			cout << "s";
		if (nickles > 0 || pennies > 0)
			cout << ", ";
		else
			cout << ".";
	}
	if (nickles > 0)
	{
		cout << nickles << " nickel";
		if (nickles > 1)
			cout << "s";
		if (pennies > 0)
			cout << ", ";
		else
			cout << ".";
	}
	if (pennies > 0)
	{
		cout << pennies << " penn";
		if (pennies > 1)
			cout << "ies";
		else
			cout << "y";
		cout << ".";
	}
	cout << endl;
	system("pause");
	return 0;
}