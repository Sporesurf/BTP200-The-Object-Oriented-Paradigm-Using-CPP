#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Item.h"

namespace sdds {
   class Bill 
   {
      char m_title[37];
      Item* m_items;
      int m_noOfItems = 0;
      int m_itemsAdded = 0;
      double totalTax()const; // querries
      double totalPrice()const;
      void Title()const;
      void footer()const; //may not need, double check
      void setEmpty();
      bool isValid()const;
   public:
      void init(const char* title, int noOfItems); //validator
      bool add(const char* item_name, double price, bool taxed); //modifier
      void display()const;
      void deallocate();
   };
}
#endif // !SDDS_TRANSCRIPT_H
