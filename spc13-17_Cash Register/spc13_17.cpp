//  Chapter 13, Programming Challenge 17: Cash Register
#include <iostream>
#include <cctype>
#include "CashRegister.h"
using namespace std;

const int NUM_ITEMS = 5;

int main()
{
   InventoryItem inventory[NUM_ITEMS] = { 
             InventoryItem("Adjustable Wrench", 7.0, 10),
             InventoryItem("Screwdriver", 3.5, 20),
             InventoryItem("Pliers", 9.0, 35),
             InventoryItem("Ratchet", 10.0, 10),
             InventoryItem("Socket Wrench", 9.75, 7) };
             
   CashRegister reg(inventory, NUM_ITEMS);
   char again;

   do
   {
      reg.makeSale();
      cout << "Do you want to purchase another item? ";
      cin >> again;

      while (toupper(again) != 'Y' && toupper(again) != 'N')
      {
         cout << "Enter Y or N please: ";
         cin >> again;
      }

   } while (toupper(again) != 'N');
}