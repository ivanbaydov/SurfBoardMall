//---------------------------------------------------------------------------------
//
// Title:          SurBoardMall
// Lab Course:     ITCS 2530 V0801 2021FA
// Author:         Ivan Baydov
// Date:           11/21/2021
//---------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>// Formatted inputs and Outputs.
#include <string>// For String data type.
#include <algorithm>// For Transfrom Method.

using namespace std;

// Function Prototype

void ShowUsage();
void MakePurchase(int& iTotalXXXS, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);
void DisplayPurchase(const int iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);
void DisplayTotal(const int iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);

int main()
{
	// Quantity variables
	int iTotalXXXS = 0; 
	int iTotalSmall = 0;
	int iTotalMedium = 0;
	int iTotalLarge= 0;

	// Input variable
	string userInput;

	// Print menu
	ShowUsage();

	// Format decimal notation and number of places
	cout << fixed << setprecision(2);
	
	// Menu loop
	do
	{
		cout << "Please enter selection: ";
		cin >> userInput;
		// Makes string to upper case
		transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

		if (userInput == "S")
		{
			ShowUsage();
		}
		else if (userInput == "P")
		{
			MakePurchase(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
		}
		else if (userInput == "C")
		{
			DisplayPurchase(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
		}
		else if (userInput == "T")
		{
			DisplayTotal(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
		}
		else if (userInput == "Q")
		{
			cout << "Thank you!!" << endl;
		}
		else
		{
			cout << "Invalid option." << endl;
		}

		cout << endl;

	} while (userInput != "Q");

	return 0;
}

/*
* Shows menu.
*/
void ShowUsage()
{
	const int WIDTH = 60;

	// Clear the console window
	system("CLS");

	cout << setfill('*') << setw(WIDTH) << "*" << endl
		<< setw(9) << "*" << " Welcome To the Michigan Surf Board Mall. " << setw(9) << "*" << endl
		<< setfill('*') << setw(WIDTH) << "*" << endl;

	cout << endl
		<< endl;

	cout << "To show program usage 'S'" << endl
		<< "To purchase a surfboard press 'P'" << endl
		<< "To display current purchases press 'C'" << endl
		<< "To display total amount due, press 'T'" << endl
		<< "To quit the program press 'Q'" << endl;

	cout << endl;
}
/*
* This function makes a pruchase.
* 
* @param int& iTotalXXXS: number of extra smalls.
* @param int& iTotalSmall: number of smalls.
* @param int& iTotalMedium: number of mediums.
* @param int& iTotalLarge: number of larges.
*/
void MakePurchase(int& iTotalXXXS, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
	string userPurchase;
	int quantity;

	cout << "Please enter the quantity and type (XXXS = extra extra extra small, S = small, M = medium, L = large) of surfboard you would like to purchase: ";
	cin >> quantity;
	cin >> userPurchase;
	transform(userPurchase.begin(), userPurchase.end(), userPurchase.begin(), ::toupper);
	
	// Reference variable adjusts value in main function too
	if (userPurchase == "XXXS")
	{
		iTotalXXXS = iTotalXXXS + quantity;

	}
	else if (userPurchase == "S")
	{
		iTotalSmall = iTotalSmall + quantity;
	}
	else if (userPurchase == "M")
	{
		iTotalMedium = iTotalMedium + quantity;
	}
	else if (userPurchase == "L")
	{
		iTotalLarge = iTotalLarge + quantity;
	}
	else
	{
		cout << "Invalid Option." << endl;
	}

}

/*
* Shows the number of items in cart.
* @param const int iTotalXXXS: number of extra small.
* @param const int iTotalSmall: number of small.
* @param const int iTotalMedium: number of medium.
* @param const int iTotalLarge: number of large.
*/
void DisplayPurchase(const iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
	if (iTotalXXXS <= 0 && iTotalSmall <= 0 && iTotalMedium <= 0 && iTotalLarge <= 0)
	{
		cout << "No purchases made yet.";
	}
	if (iTotalXXXS > 0)
	{
		cout << "The total number of extra extra extra small surfboards is " << iTotalXXXS << endl;
	}
	if (iTotalSmall > 0)
	{
		cout << "The total number of small surfboards is " << iTotalSmall << endl;
	}
	if (iTotalMedium > 0)
	{
		cout << "The total number of medium surfboards is " << iTotalMedium << endl;
	}
	if (iTotalLarge > 0)
	{
		cout << "The total number of large surfboards is " << iTotalLarge << endl;
	}
}

/*
* Shows the number of items in cart and the total.
* @param const int iTotalXXXS: number of extra small.
* @param const int iTotalSmall: number of small.
* @param const int iTotalMedium: number of medium.
* @param const int iTotalLarge: number of large.
*/
void DisplayTotal(const iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
	// Costs of items
	const double EXTRA_SMALL_PRICE = 150.00;
	const double SMALL_PRICE = 175.00;
	const double MEDIUM_PRICE = 190.00;
	const double LARGE_PRICE = 200.00;

	// Calculate user costs
	double extrasmallCost = EXTRA_SMALL_PRICE * iTotalXXXS;
	double smallCost = SMALL_PRICE * iTotalSmall;
	double mediumCost = MEDIUM_PRICE * iTotalMedium;
	double largeCost = LARGE_PRICE * iTotalLarge;
	double totalCost = extrasmallCost + smallCost + mediumCost + largeCost;

	if (iTotalXXXS > 0)
	{
		cout << "The total number of extra extra extra small surfboards is " << iTotalXXXS << " at a total of $" << extrasmallCost << endl;
	}
	if (iTotalSmall > 0)
	{
		cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << smallCost <<  endl;
	}
	if (iTotalMedium > 0)
	{
		cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << mediumCost << endl;
	}
	if (iTotalLarge > 0)
	{
		cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << largeCost << endl;
	}

	if (iTotalXXXS <= 0 && iTotalSmall <= 0 && iTotalMedium <= 0 && iTotalLarge <= 0)
	{
		cout << "No purchases made yet.";
	}
	else
	{
		cout << "Amount due: $" << totalCost << endl;
	}
	
}

