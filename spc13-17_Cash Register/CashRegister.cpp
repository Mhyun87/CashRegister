// Implementation file for the CashRegister class
#include <iostream>
#include <iomanip>
#include "CashRegister.h"
using namespace std;

//*****************************************************
// Constructor                                        *
// This constructor accepts an array of InventoryItem *
// objects and copies it to the internal array.       *
//*****************************************************

CashRegister::CashRegister(InventoryItem *i, int size)
{  
	// Create an array of inventory items.
	inventory = nullptr;
	inventory = new InventoryItem [size];
   
	// Copy the array passed as i to the new
	// inventory item array.
	for(int count = 0; count < size; count++)
		inventory[count] = i[count];
}

//*****************************************************
// Destructor                                         *
// Frees memory allocated to the internal array.      *
//*****************************************************
CashRegister::~CashRegister()
{
   delete [] inventory;
   inventory = nullptr;
}

//***************************************************
// The makeChoice function displays a list of items *
// and lets the user select one.                    *
//***************************************************

void CashRegister::makeChoice()
{
   cout << setw(5) << left << "#" << setw(20);
   cout << left <<"Item" << setw(12);
   cout << left << "qty on Hand\n";
   cout << "---------------------------------"
        << "-----------------------------\n";

   for (int index = 0; index < 5; index++)
   {
      cout << setw(5) << left << (index+1);
      cout << setw(20) << inventory[index].getDescription();
      cout << setw(12) << inventory[index].getUnits() << endl;
   }

   cout << "Which item above is being purchased? ";
   cin >> choice;
   while (choice < 0 || choice > 5)
   {
      cout << "That is not a valid choice.\n";
      cout << "Which item above is being purchased? ";
      cin >> choice;
   }
   choice--;
}

//***************************************************
// findUnitPrice member function                    *
//***************************************************

void CashRegister::findUnitPrice()
{
   unitPrice = inventory[choice].getCost() * 1.3;
}

//***************************************************
// findSalesTax member function                     *
//***************************************************

void CashRegister::findSalesTax()
{
   tax = subTotal * 0.06;
}

//***************************************************
// findTotal member function                        *
//***************************************************

void CashRegister::findTotal()
{
   total = subTotal + tax;
}

//***************************************************
// adjustUnits member function                      *
//***************************************************

bool CashRegister::adjustUnits()
{
	bool status = false;

	int quantity = inventory[choice].getUnits();
	if (quantity >= qty)
	{
		inventory[choice].setUnits(quantity - qty);
		status = true;
	}

	return status;
}

//***************************************************
// makeSale member function                         *
//***************************************************

void CashRegister::makeSale()
{
   // Display a list of items to choose from.
   makeChoice();
   
   // Get the number of units.
   cout << "How many units? ";
   cin >> qty;
   
   // Validate it.
   while (qty < 0)
   {
      cout << "Enter 0 or greater please: ";
      cin >> qty;
   }

   // Determine the unit price.
   findUnitPrice();
   
   // Calculate the subtotal.
   subTotal = qty * unitPrice;
   
   // Determine the sales tax.
   findSalesTax();
   
   // Determine the total.
   findTotal();
   
   // Adjust the units on hand.
   if (adjustUnits())
      displaySale();
   else
      cout << "There aren't enough units in stock.\n";
}

//***************************************************
// displaySale member function                      *
//***************************************************

void CashRegister::displaySale()
{
   cout << fixed << showpoint << setprecision(2);
   cout << "Subtotal:  $" << subTotal << endl;
   cout << "Sales Tax: $" << tax << endl;
   cout << "Total:     $" << total << endl;
}