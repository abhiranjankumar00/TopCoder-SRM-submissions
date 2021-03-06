#include <bits/stdc++.h>
using namespace std;

class AutoLoan
{
public:
	double interestRate(double price, double monthlyPayment, int loanTerm);
};

double amountLeft(double price, double payment, int term, double interest) {
//  printf("interest rate = %lf\n\n", interest);
  while(term--) {
    price += interest*price;
//    printf("interest = %lf, ", interest*price);
    price -= payment;
//    printf("balance = %lf\n", price);
  }

//  cout << "\n" << "\n";
  return price;
}

double AutoLoan::interestRate (double price, double monthlyPayment, int loanTerm) 
{
  double l = 0, r = 100;

  for(int i = 0; i < (int)1000; ++i) {
    double mid = (l+r)/2;
//    mid = 9.56205462458368;
    double left = amountLeft(price, monthlyPayment, loanTerm, mid/1200);
//    printf("interest = %lf, left = %lf\n", mid, left);
    (left > 0?r : l) = mid;
  }

  return l;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, double p0, double p1, int p2, bool hasAnswer, double p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	AutoLoan *obj;
	double answer;
	obj = new AutoLoan();
	clock_t startTime = clock();
	answer = obj->interestRate(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == answer && fabs(p3 - answer) <= 1e-9 * max(1.0, fabs(p3));
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	double p0;
	double p1;
	int p2;
	double p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 6800;
	p1 = 100;
	p2 = 68;
	p3 = 1.3322616182218813E-13;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 2000;
	p1 = 510;
	p2 = 4;
	p3 = 9.56205462458368;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 15000;
	p1 = 364;
	p2 = 48;
	p3 = 7.687856394581649;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// Auto dealerships frequently advertise tempting loan offers in order to make it easier for people to afford the "car of their dreams".  A typical sales tactic is to show you various cars, and then talk in terms of what your monthly payment would be, to say nothing of how much you are actually paying for the car, how much interest you pay, or how long you have to make payments.
// 
// A typical auto loan is calculated using a fixed interest rate, and is set up so that you make the same monthly payment for a set period of time in order to fully pay off the balance.  The balance of your loan starts out as the sticker price of the car.  Each month, the monthly interest is added to your balance, and the amount of your payment is subtracted from your balance.  (The payment is subtracted after the interest is added.)  The monthly interest rate is 1/12 of the yearly interest rate.  Thus, if your annual percentage rate is 12%, then 1% of the remaining balance would be charged as interest each month.
// 
// You have been checking out some of the cars at your local dealership, TopAuto.  An excited salesman has just approached you, shouting about how you can have the car you are looking at for a payment of only monthlyPayment for only loanTerm months!   You are to return a double indicating the annual percentage rate of the loan, assuming that the initial balance of the loan is price.
// 
// 
// DEFINITION
// Class:AutoLoan
// Method:interestRate
// Parameters:double, double, int
// Returns:double
// Method signature:double interestRate(double price, double monthlyPayment, int loanTerm)
// 
// 
// NOTES
// -Because of the way interest is compounded monthly, the actual interest accrued over the course of a year is not necessarily the same as (balance * yearly interest rate).  In fact, it's usually more.
// -In a real situation, information like this would typically need to be disclosed, but since you aren't at a point of signing any paperwork, the salesman has no legal obligation to tell you anything.
// -The return value must be within 1e-9 absolute or relative error of the actual result.
// 
// 
// CONSTRAINTS
// -price will be between 1 and 1000000, inclusive.
// -monthlyPayment will be between 0 and price / 2, inclusive.
// -loanTerm will be between 1 and 600, inclusive.
// -The resulting interest rate will be between 0 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 6800
// 100
// 68
// 
// Returns: 1.3322616182218813E-13
// 
// Noting that 68 payments of 100 equals the total price of 6800, so there is no interest.
// 
// 1)
// 2000
// 510
// 4
// 
// Returns: 9.56205462458368
// 
// Here, we do pay a little interest.  At 9.562% annual interest, that means each month we pay 0.7968% of the balance in interest.  Our payment schedule looks like this:
// 
// 
// Month | + Interest | - Payment | = Balance
// ------------------------------------------
//       |            |           |  2000.00
//    1  |     15.94  |   510.00  |  1505.94
//    2  |     12.00  |   510.00  |  1007.94
//    3  |      8.03  |   510.00  |   505.97
//    4  |      4.03  |   510.00  |     0.00
// 
// 
// 
// 2)
// 15000
// 364
// 48
// 
// Returns: 7.687856394581649
// 
// This is similar to what purchasing a new car with no money down might look like, if you make payments for 4 years.
// 
// END KAWIGIEDIT TESTING
