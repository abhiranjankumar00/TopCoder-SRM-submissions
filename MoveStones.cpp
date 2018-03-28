#include <bits/stdc++.h>
using namespace std;

long long oo = LONG_LONG_MAX;

long long solve(vector<long long> arr) {
	long long steps = 0l;
	long long carry = 0l;

	for(auto x: arr) {
		carry += x;
		steps += abs(carry);
	}

	/*
	cout << "Arr: [";
	copy(arr.begin(), arr.end(), ostream_iterator<long long>(cout, " "));
	printf("], steps: %lld\n", steps);
	*/

	return steps;
}

void rotate(vector<long long> &arr) {
	int head = arr[0];
	int N = (int)arr.size();
	for(int i = 0; i < N-1; i++)
		arr[i] = arr[i+1];
	arr[N-1] = head;
}

class MoveStones
{
	vector<long long> diff;
	int N;

public:
    long long get(vector <int> a, vector <int> b)
    {
		N = (int)a.size();

		for(int i = 0; i < N; i++)
			diff.push_back(b[i] - a[i]);

		if(accumulate(diff.begin(), diff.end(), 0L) != 0l)
			return -1;

		/*
		cout << "Diff: [";
		copy(diff.begin(), diff.end(), ostream_iterator<int>(cout, " "));
		cout << "]" << endl << endl;
		*/

        long long ret = LONG_LONG_MAX;

		for(int i = 0; i < N; i++) {
			ret = min(ret, solve(diff));
			rotate(diff);
		}

        return ret;
    }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	MoveStones *obj;
	long long answer;
	obj = new MoveStones();
	clock_t startTime = clock();
	answer = obj->get(p0, p1);
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
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	vector <int> p0;
	vector <int> p1;
	long long p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {12};
	p1 = {12};
	p2 = 0ll;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {10};
	p1 = {9};
	p2 = -1ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {0,5};
	p1 = {5,0};
	p2 = 5ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {1,2,3};
	p1 = {3,1,2};
	p2 = 2ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {1,0,1,1,0};
	p1 = {0,3,0,0,0};
	p2 = 4ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {1000000000,0,0,0,0,0};
	p1 = {0,0,0,1000000000,0,0};
	p2 = 3000000000ll;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
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
// 
// There are n piles of stones arranged around a circle.
// The piles are numbered 0 through n-1, in order.
// In other words: 
// For each valid i, piles i and i+1 are adjacent.
// Piles 0 and n-1 are also adjacent.
// 
// 
// 
// You are given two vector <int>s a and b, each with n elements.
// For each i, a[i] is the current number of stones in pile i, and b[i] is the desired number of stones for this pile.
// You want to move some stones to create the desired configuration.
// In each step you can take any single stone from any pile and move the stone to any adjacent pile.
// Find and return the smallest number of steps needed to create the desired configuration, or -1 if the desired distribution of stones cannot be reached.
// 
// 
// DEFINITION
// Class:MoveStones
// Method:get
// Parameters:vector <int>, vector <int>
// Returns:long long
// Method signature:long long get(vector <int> a, vector <int> b)
// 
// 
// NOTES
// -At any moment during the game some piles may be empty. Empty piles still remain in place. For example, if pile 5 is empty, you are not allowed to move a stone from pile 4 directly to pile 6 in a single step. Instead, you must place the stone onto the empty pile 5 first.
// 
// 
// CONSTRAINTS
// -n will be between 1 and 1000, inclusive.
// -a will have exactly n elements.
// -b will have exactly n elements.
// -Each element of a and b will be between 0 and 10^9, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {12}
// {12}
// 
// Returns: 0
// 
// The desired configuration is the same as the initial configuration.
// No steps are needed.
// 
// 1)
// {10}
// {9}
// 
// Returns: -1
// 
// We cannot add or remove stones, we can only move them around the circle.
// 
// 2)
// {0, 5}
// {5, 0}
// 
// Returns: 5
// 
// 
// 
// 3)
// {1, 2, 3}
// {3, 1, 2}
// 
// Returns: 2
// 
// Move one stone from pile 1 to pile 0 and another stone from pile 2 to pile 0.
// 
// 4)
// {1, 0, 1, 1, 0}
// 
// {0, 3, 0, 0, 0}
// 
// Returns: 4
// 
// 
// 
// 5)
// {1000000000, 0, 0, 0, 0, 0}
// {0, 0, 0, 1000000000, 0, 0}
// 
// Returns: 3000000000
// 
// Watch out for integer overflow.
// 
// END KAWIGIEDIT TESTING
