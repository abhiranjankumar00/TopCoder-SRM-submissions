#include <bits/stdc++.h>
using namespace std;

class Nisoku
{
public:
	double theMax(vector <double> cards);
};

double Nisoku::theMax (vector <double> cards) 
{
	double ret = 0;
  set <int> in;

  while(in.size() < cards.size() -1) {
    int id1 = -1, id2 = -1;
    double curMax = -1;

    for(int i = 0; i < (int)cards.size(); ++i) if (in.find(i) == in.end()){
      for(int j = (int)i+1; j <= (int)cards.size()-1; ++j)  if(in.find(j) == in.end()){
        double tmp = max(cards[i]+cards[j], cards[i]*cards[j]);

        if(id1 == -1 ) {
          id1 = i;
          id2 = j;
          curMax = tmp;
        }
        else if(curMax < tmp) {
          id1 = i;
          id2 = j;
          curMax = tmp;
        }
      }
    }

    in.insert(id1);
    in.insert(id2);
    ret = max(ret + curMax, ret * curMax);

  }

	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <double> p0, bool hasAnswer, double p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	Nisoku *obj;
	double answer;
	obj = new Nisoku();
	clock_t startTime = clock();
	answer = obj->theMax(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == answer && fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
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
	
	vector <double> p0;
	double p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {5,8};
	p1 = 40.0;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {1.5,1.8};
	p1 = 3.3;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {8.26,7.54,3.2567};
	p1 = 202.82857868;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {1.5,1.7,1.6,1.5};
	p1 = 9.920000000000002;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
	p1 = 1.0E50;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
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
// Taro and Hanako are playing a game called Nisoku, which is played as follows. Initially, there is a pile of cards. Each card contains a real number between 1.5 and 10.0, inclusive. You are given a vector <double> cards, the i-th element of which is the number written on the i-th card.
// 
// 
// Repeat the following step until there is only one card left in the pile: Remove any two cards from the pile, and add one new card to the pile. Write either a+b or a*b on the new card, where a and b are the numbers written on the two cards that were removed.
// 
// 
// Return the maximal possible number written on the final card in the pile.
// 
// DEFINITION
// Class:Nisoku
// Method:theMax
// Parameters:vector <double>
// Returns:double
// Method signature:double theMax(vector <double> cards)
// 
// 
// NOTES
// -Your return value must have an absolute or relative error less than 1e-9.
// 
// 
// CONSTRAINTS
// -cards will contain between 2 and 50 elements, inclusive.
// -Each element of cards will be between 1.5 and 10.0, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {5, 8}
// 
// Returns: 40.0
// 
// 5 * 8 = 40.
// 
// 1)
// {1.5, 1.8}
// 
// Returns: 3.3
// 
// 1.5 + 1.8 = 3.3.
// 
// 2)
// {8.26, 7.54, 3.2567}
// 
// Returns: 202.82857868
// 
// 
// 
// 3)
// {1.5, 1.7, 1.6, 1.5}
// 
// Returns: 9.920000000000002
// 
// 
// 
// 4)
// {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
// 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
// 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
// 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
// 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}
// 
// Returns: 1.0E50
// 
// The answer can be extremely big.
// 
// END KAWIGIEDIT TESTING
