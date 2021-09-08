#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds
{
   class Account 
   {
      int m_number = 0;
      double m_balance = 0.0; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      operator bool() const;
      operator int() const;
      operator double() const;

      bool operator ~() const;

      Account& operator=(int nAcc);
      Account& operator=(Account&);
      Account& operator+=(double bDeposit);
      Account& operator-=(double bReduce);
      Account& operator<<(Account&);
      Account& operator>>(Account&);
   };
   double operator+(const Account& left, const Account& right);
   double operator+=(double& t_balance, const Account& right);
}
#endif // SDDS_ACCOUNT_H