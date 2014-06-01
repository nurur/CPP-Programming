// Example
// Self-Test Exercises 12, 13, 14, 15


#include <iostream>
using namespace std;



class Automobile
{
public:
  void setPrice(double newPrice)   { price  = newPrice;  }
  void setProfit(double newProfit) { profit = newProfit; }
  void setCount(int newCount)      { count  = newCount;  }

  double getPrice() { return price; }
  double getProfit() { return profit; }
  void getCount() { cout << "Total number of cars is : " << count << endl; }

private:
  double price, profit;
  int count;

  //double getPrice() { return price; }
  //ouble getProfit() { return profit; }
  //void getCount() { cout << "Total number of cars is : " << count << endl; }
};



int main()
{
  Automobile jaguar, hundai, tata;
  jaguar.setPrice(30000.99);
  jaguar.setProfit(300.99);
  jaguar.setCount(500);

  cout << jaguar.getPrice()  << endl;
  cout << jaguar.getProfit() << endl;
  jaguar.getCount();


  return 0;
}
