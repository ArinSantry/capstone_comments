/*File Name: Fall MP1 2018
  Author:    [REDACTED]
  Date:      Due 9/27/2018
  Professor: Dr. Estell
  Course:    Programming 1*/

/*This program is to be used for a donut shop. This program will
accomplish multiple tasks. The first task is to read in how many
regular and fancy donuts the customer orders, and the cost of the
order. The second tasks it to determine the change by subtracting 
the price of the order from how much money the customer gives.
Finally, the program takes the change, and determiend how the 
user can pay back the customer in types of coins and dollars,
including dollar bills, quarters, nickels, and dimes.*/

#include <iostream> //basic setup of program 
using namespace std; //basic setup of program

int main(void) {



	/* SECTION 1
	This section is for declaring variables.
	All variables are integers, except for "period", which is for
	when the user enters in a period seperating the dollars and cents.*/


	//These variables are for the number of donuts the customer buys:
	int regDonuts; //variable for number of reular donuts
	int fanDonuts; //variable for number of fancy donuts
	int regDonutsDozen; //variable for number of dozens of regular donuts
	int regDonutsIndiv; //variable for number of individual regular donuts
	int fanDonutsDozen; //variable for number of dozons of fancy donuts
	int fanDonutsIndiv; //variable for number of individual fancy donuts

	//These varibles are for the money the customers pays and the price of the donuts.
	int dollarsPayed; //how many the customer pays, not including the cents
	int centsPayed; //how much cents the customer pays, not including the dollars
	int priceInCents; //variable for amount that the customer owes entirely in cents
	int changeInCents; /*displays the change in entirely cents for easier math
					   (instead of $19.99 or 19 dollars and 99 cents, it is 1999 cents)*/

	//These variables are for the types of coins the customer will recieve in change.
	int dollars; //how many dollars the customer will recieve in change
	int quarters; //how many quarters the customer will recieve in change
	int dimes; //how many dimes the customer will recieve in change
	int nickels; //how many nickles the customer will recieve in change
	int pennies; //how many pennies the customer will recieve in change
	int coinTypes; /*this is for many different tpyes of coin will
				   be returned to the customer, the variable is used
				   for grammar purposes when displaying change*/

	char period; /*this is for when the user inputs the amount the customer pays,
				 and is for reading in the period between the dollars and cents*/



	/* SECTION 2
	This section is for determining the number of regular and fancy donuts
	the customer buys, and the cost.*/


	cout << "Number of regular donuts ordered: "; /*prompts user to enter
												  number of regular donuts*/
	cin >> regDonuts; //reads in input for number of regular donuts

	cout << "Number of fancy donuts ordered: "; /*promts user to enter
												number of fancy donuts*/
	cin >> fanDonuts; //reads in input for number of fancy donuts

	regDonutsDozen = regDonuts / 12; /*calculates the number of dozens of regular
									 donuts using division (remainder not included
									 as the variables are integers)*/
	regDonutsIndiv = regDonuts % 12; /*calculates the individual number of regular donuts
									 after the dozens using modulo*/
	fanDonutsDozen = fanDonuts / 12; /*calculates the number of dozens of regular donuts
									 using division (remainder not included as the
									 variables are integers)*/
	fanDonutsIndiv = fanDonuts % 12; /*calculates the individual number of fancy
									 donuts after the dozens*/

	priceInCents = /*the prices are converted entirely into cents for easier arithmatic
				   (instead of $19.99 or 19 dollars and 99 cents, it is 1999 cents)*/
		  regDonutsDozen * 799 //adds the price of the dozen regular donuts
		+ regDonutsIndiv * 75 //adds the prince of the individual regular donuts
		+ fanDonutsDozen * 849 //adds the price of the dozen fancy donuts
		+ fanDonutsIndiv * 85; //adds the pricce of the individual regular donuts

	/*converts amount owed in cents into a dollar and cents amount
	sepereated by a period (i.e. "1.50")*/
	cout << "Customer owes $" << priceInCents / 100 << '.'; 
	//the above line displays the dollar section 
	
	if (priceInCents % 100 < 10) cout << '0' << priceInCents % 100 << endl; 
	/*for the line above: if the cents section after the period is less than ten,
	a zero is added after the period (i.e. "1.08" instead of "1.8")*/

	else cout << priceInCents % 100 << endl;
	/*for the line above: if the cents section after the period is more than ten, 
	the cents section wil simply be the remainder of the priceInCents / 100, or
	priceInCents % 100*/
	
	cout << "Customer pays $"; //user inputs how much the customer payed
	cin >> dollarsPayed >> period >> centsPayed; 
	
	changeInCents = (centsPayed + dollarsPayed * 100) - (priceInCents);
	//converts the difference between the amount payed and the price into cents only

	if (changeInCents > 0) {
		cout << "Change owed is $" << changeInCents / 100 << '.'; 
		/* For the line above:
		outputs the dollar section of the change,
		converting the changeInCents into dollars*/

		if (changeInCents % 100 < 10) cout << '0' << changeInCents % 100 << " - "; 
		/*a dash is added to indicate the number of
		coins to be returned are about to be given
			if the cents section after the period is less
			than ten, a zero is added after the period
			(i.e. "1.08" instead of "1.8")*/
		else cout << changeInCents % 100 << " - "; 
		/*a dash is added to indicate the number of
		coins to be returned are about to be given
			if the cents section after the period is
			more than ten, the cents section wil simply
			be the remainder of the "priceInCents" / 100,
			or priceInCents % 100*/
	}

	else if (changeInCents < 0) {
		cout << "Customer payment has not met the price of donuts.";
	}

	else cout << "Exact payment recieved - no change owed.";



	/* SECTION 3
	This section is for determining the amount of change the customer will recieve.
	It achieves so with the following steps:
	1) The number of dollars to go into the change, or int "changeInCents"
	is determined by diving "changeInCents" by 100.
	2) The remaining cents that can't be returned in dollars is
	determined using modulo.
	3) The program then checks to see how many quarters will
	go into the remaining "changeInCents" by diving "changeInCents" by 25
	4) The remaining cents that can't be returned in
	quarters is determined using modulo.
	5) The process continues for dimes
	("changeInCents" / 10) and nickels ("changeInCents" / 5).
	6) The final remainder than can't be returned
	with dollars, quarters, dimes, or nickels then covered with pennies*/
	

	dollars = changeInCents / 100; 
	/*determines the number of one dollar bills that will go
	into the change and can be returned to the customer*/
	changeInCents = changeInCents % 100; 
	/*sets the change to the remainder after the dollar
	bills are determined using modulo*/

	quarters = changeInCents / 25; 
	/*determines the number of quarters that will go
	into the change and can be returned to the customer*/
	changeInCents = changeInCents % 25; 
	/*sets the change to the remainder after the
	quarters are determined using modulo*/

	dimes = changeInCents / 10; 
	/*determines the number of dimes that will go
	into the change and can be returned to the customer*/
	changeInCents = changeInCents % 10; 
	/*sets the change to the remainder after the
	dimes are determined  using modulo*/

	nickels = changeInCents / 5; 
	/*determines the number of dimes that will go
	into the change and can be returned to the customer*/
	changeInCents = changeInCents % 5;
	/*sets the change to the remainder after the
	nickles are determined using modulo*/

	pennies = changeInCents; /*the final remainder not able to be covered
							 with dollars, quarters, dimes, or nickels will
							 be covered with pennies*/



	/*SECTION 4
	This final section will tell the user how many
	coins need to be returned to the customer.
	The section will also determine the correct
	grammar to display, for example, making words
	plural or singular depending on how many coins there are.*/


	coinTypes = 0; //this determines how many types of coins there are
	if (dollars > 0) coinTypes++; 
	//if a coin type is present, add to the "coinTypes" variable
	if (quarters > 0) coinTypes++;
	if (dimes > 0) coinTypes++;
	if (nickels > 0) coinTypes++;
	if (pennies > 0) coinTypes++;

	if (coinTypes > 1) { //checks for coin types after dollar, puts comma after if true
		if (dollars == 1) { //if there is one dollar, make dollar singular
			cout << dollars << " dollar, ";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
		else if (dollars > 1) { //if there are multiple dollars, make dollar plural
			cout << dollars << " dollars, ";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
	}
	else if (coinTypes == 1) { //checks for coin types after dollar, puts period if false
		if (dollars == 1) {
			cout << dollars << " dollar.";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
		else if (dollars > 1) {
			cout << dollars << " dollars.";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
	}

	//determining grammar for quarters
	if (coinTypes > 1) { //checks for coin types after quarter, puts period if false
		if (quarters == 1) {
			cout << quarters << " quarter, ";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
		else if (quarters > 1) {
			cout << quarters << " quarters, ";
			coinTypes--; //coin type has been displayed, decrease the "coinTypes" variable
		}
	}
	else if (coinTypes == 1) { //checks for coin types after quarter, puts period if false
		if (quarters == 1) {
			cout << quarters << " quarter.";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
		else if (quarters > 1) {
			cout << quarters << " quarters.";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
	}


	//determining grammar for dimes
	if (coinTypes > 1) { //checks for coin types after dime, puts comma if true
		if (dimes == 1) {
			cout << dimes << " dime, ";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
		else if (dimes > 1) {
			cout << dimes << " dimes, ";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
	}
	else if (coinTypes == 1) { //checks for coin types after dime, puts period if false
		if (dimes == 1) {
			cout << dimes << " dime.";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
		else if (dimes > 1) {
			cout << dimes << " dimes.";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
	}

	//determining grammar for nickels
	if (coinTypes > 1) { //checks for coin types after nickel, puts comma if true
		if (nickels == 1) {
			cout << nickels << " nickel, ";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
		else if (nickels > 1) {
			cout << nickels << " nickels, ";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
	}
	else if (coinTypes == 1) { //checks for coin types after nickel, put period if false
		if (nickels == 1) {
			cout << nickels << " nickel.";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
		else if (nickels > 1) {
			cout << nickels << " nickels.";
			coinTypes--; //coin type has been displayed, decrease "coinTypes" variable
		}
	}

	//determining grammar for pennies
	if (pennies == 1) cout << pennies << " penny."; 
	//if there is only one penny in change, make the word "penny" singular - "penny"
	if (pennies > 1) cout << pennies << " pennies.";
	//if there are multiple pennnies, and the word "penny" plural - "pennies"
	/*NOTE: because pennies will always be the
	last type of coin to be printed out, it will
	always end with a period*/
}