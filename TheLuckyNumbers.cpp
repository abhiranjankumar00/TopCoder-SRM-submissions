#include <bits/stdc++.h>
using namespace std;

class TheLuckyNumbers
{
public:
	int count(int a, int b);
};

long long A, B;
vector <long long> vec;

void gen(long long x) {
  if(x > B)
    return;
  vec.push_back(x);
  gen(x*10+4);
  gen(x*10+7);
}

int TheLuckyNumbers::count (int a, int b) 
{
  A = a, B = b;
  vec.clear();
  gen(4);
  gen(7);
  int ret = 0;
  for(auto it = (vec).begin(); it != (vec).end(); ++it) {
    if(*it >= A && *it <= B)
      ret++;
  }
  return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	TheLuckyNumbers *obj;
	int answer;
	obj = new TheLuckyNumbers();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 10;
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 11;
	p1 = 20;
	p2 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 74;
	p1 = 77;
	p2 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 1000000;
	p1 = 5000000;
	p2 = 64;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// 
// John thinks 4 and 7 are lucky digits, and all other digits are not lucky.  A lucky number is a number that contains only lucky digits in decimal notation.
// 
// 
// 
// You are given ints a and b.  Return the number of lucky numbers between a and b, inclusive.
// 
// 
// 
// DEFINITION
// Class:TheLuckyNumbers
// Method:count
// Parameters:int, int
// Returns:int
// Method signature:int count(int a, int b)
// 
// 
// CONSTRAINTS
// -a will be between 1 and 1,000,000,000, inclusive.
// -b will be between a and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 10
// 
// Returns: 2
// 
// There are only two lucky numbers among the first ten positive integers.
// 
// 1)
// 11
// 20
// 
// Returns: 0
// 
// But there are none among the next ten.
// 
// 2)
// 74
// 77
// 
// Returns: 2
// 
// These two numbers are lucky. There are no additional lucky numbers between them.
// 
// 
// 3)
// 1000000
// 5000000
// 
// Returns: 64
// 
// 
// 
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
