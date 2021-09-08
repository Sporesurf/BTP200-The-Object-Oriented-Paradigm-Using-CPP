#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds
{
   void Account::setEmpty() 
   {
      m_number = -1;
      m_balance = 0.0;
   }
  
   Account::Account() 
   {  
      m_number = 0;
      m_balance = 0.0;
   }

   Account::Account(int number, double balance ) 
   {
      setEmpty();
      if (number >= 10000 && number <= 99999 && balance > 0) 
      {
         m_number = number;
         m_balance = balance;
      }
   }

   std::ostream& Account::display() const
   {
      if (*this) 
      {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this)
      {
         cout << "  NEW  |         0.00 ";
      }
      else 
      {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const
   {
       if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0)
       {
           return true;
       }
       return false;
   }

   Account::operator int() const { return m_number; }

   Account::operator double() const { return m_balance; }

   bool Account::operator ~() const
   {
       if (m_number == 0)
       {
           return true;
       }
       return false;
   }

   Account& Account::operator=(int nAcc)
   {
       if (~*this) 
       {
            m_number = nAcc;
       }
       else if (!*this && !~*this) 
       {
           setEmpty();
       }
       return *this;
   }

   Account& Account::operator=(Account& rhs)
   {
       if (~*this && rhs)
       {
           m_number = rhs.m_number;
           m_balance = rhs.m_balance;
           rhs.m_number = 0;
           rhs.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator+=(double bDeposit)
   {
       if (*this && bDeposit > 0.0)
       {
           m_balance += bDeposit;
       }
       return *this;
   }

   Account& Account::operator-=(double bReduce)
   {
       if (*this && bReduce > 0.0 && m_balance > bReduce)
       {
           m_balance -= bReduce;
       }
       return *this;
   }

   Account& Account::operator<<(Account& rAcc)
   {
       if (*this && m_number != rAcc.m_number)
       {
           m_balance += rAcc.m_balance;
           rAcc.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator>>(Account& lAcc)
   {
       if (*this && lAcc.m_number != m_number)
       {
           lAcc.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }

   double operator+(const Account& left, const Account& right)
   {
       if (left.operator bool() && right.operator bool())
       {
          return left.operator double() + right.operator double();
       }
       return 0.0;
   }

   double operator +=(double& t_balance, const Account& right)
   {
       return t_balance += right.operator double();
   }
}

