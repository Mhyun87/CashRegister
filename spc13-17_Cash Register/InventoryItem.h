#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include <string>
using namespace std;

class InventoryItem
{
private:
	string description;	// The item description
	double cost;		// The item cost
	int units;          // Number of units on hand

public:
   // Constructor #1
   InventoryItem()
	  { description = ""; cost = 0.0; units = 0; }

   // Constructor #2
   InventoryItem(string desc)
	  { description = desc; cost = 0.0; units = 0; }

   // Constructor #3
   InventoryItem(string desc, double c, int u)
	  { description = desc; cost = c; units = u; }

   // Mutator functions
   void setDescription(string d) 
	  { description = d; }

   void setCost(double c)
      { cost = c; }
      
   void setUnits(int u)
      { units = u; }

   // Accessor functions
   const string getDescription() const
      { return description; }
         
   double getCost() const
      { return cost; }

   int getUnits() const
      { return units; }
};

#endif