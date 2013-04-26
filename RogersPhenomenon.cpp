#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <climits>
#include <cstring>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long  int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector <int> > vvi;
typedef pair<int,int> ii;
typedef vector <string> vs;

#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define endl 		("\n")

#define	ep		1e-9
#define PI		M_PI
#define E 		M_E

#define	CL(a, b)	memset(a, b, sizeof(a))
#define	mp		make_pair
#define	pb		push_back

#define	all(c)		(c).begin(), (c).end()
#define	tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())		//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())		//vector & list//

#define forn(i, n)	for(int i = 0, loop_ends_here = (int)n; i < loop_ends_here ; i++)
#define forab(i, a, b)	for(int i = a, loop_ends_here = (int)b; i <= loop_ends_here; i++)
#define rep(i, a, b)	for(int i = a, loop_ends_here = (int)b; i >= loop_ends_here; i--)

#define Pf		printf
#define	Sf		scanf

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

class RogersPhenomenon
{
public:
	int countTriggers(vector <int> set1, vector <int> set2);
};

struct RealNumber {
	int num, den;
	bool operator >(const RealNumber &ob) const {
		return num * ob.den > ob.num * den;
	}
	void set(int a, int b) {
		num = a, den = b;
		if(num == 0 || den == 0)
			return;
		int d = __gcd(a, b);
		d = d < 0 ? -d : d;
		num /= d;
		den /= d;
	}
	RealNumber() {}
	RealNumber(int a, int b ) {set(a, b);}
};

int solve(vi fromSet, vi toSet) {
	if(fromSet.size() < 2)
		return 0;

	int ret = 0;
	int sumFromSet = accumulate(all(fromSet), 0), sumToSet = accumulate(all(toSet), 0);
	RealNumber fromMean(sumFromSet, fromSet.size()), toMean(sumToSet, toSet.size());

	Pf("fromMean = %d/%d, toMean = %d/%d\n", fromMean.num, fromMean.den, toMean.num, toMean.den);
	tr(it, fromSet) {
		RealNumber mean1(sumFromSet - *it, fromSet.size()-1), mean2(sumToSet + *it, toSet.size()+1);
		bool flag = (mean1 > fromMean && mean2 > toMean);
		Pf("moving %d: newFromMean = %d/%d, newToMean = %d/%d = %s\n", *it, mean1.num, mean1.den, mean2.num, mean2.den, flag?"yes":"no");
		if(flag)
			ret++;
	}
	cout << endl;
	return ret;
}

int RogersPhenomenon::countTriggers (vector <int> set1, vector <int> set2) 
{
	int ret = solve(set1, set2) + solve(set2, set1);
	
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
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
	RogersPhenomenon *obj;
	int answer;
	obj = new RogersPhenomenon();
	clock_t startTime = clock();
	answer = obj->countTriggers(p0, p1);
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	
	{
	// ----- test 0 -----
	int t0[] = {1,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,5,6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {3,100,90};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {5,1,18,29};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,1,1,1,1,5};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-10,-9,-8,-7,-6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 5;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {12,94,53,43,58,85,55,83,47,57};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {23,100,98,27,9,70,39,39,54};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
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
// The Will Rogers phenomenon is the apparent paradox which occurs when, upon moving an element from one set of numbers to another set, the means (averages) of both sets increase.
// 
// For example, the sets { 1, 2, 3 } and { 4, 5, 6 } have means 2 and 5, respectively. Moving the 4 to the first set would increase its mean to 2.5, while also increasing the mean of the second set to 5.5.
// 
// More precisely, we will consider the phenomenon to have occured if, upon moving a number between sets, the mean of both of the sets has strictly increased. An element may be moved from a set only if the set contains at least two elements.
// 
// You are to move exactly one number from one of the sets to the other. Given the initial configuration of the sets as two vector <int>s, set1 and set2, return the number of elements which trigger the phenomenon when chosen to be moved.
// 
// 
// DEFINITION
// Class:RogersPhenomenon
// Method:countTriggers
// Parameters:vector <int>, vector <int>
// Returns:int
// Method signature:int countTriggers(vector <int> set1, vector <int> set2)
// 
// 
// NOTES
// -The sets may contain duplicate elements, all of which should be included when calculating averages.
// 
// 
// CONSTRAINTS
// -Both set1 and set2 will contain between 1 and 50 elements, inclusive.
// -Each element in set1 and set2 will be between -1000 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// { 1, 2, 3 }
// { 4, 5, 6 }
// 
// Returns: 1
// 
// This is the example from the problem statement. The number 4 from the second set is the only one which triggers the Rogers phenomenon.
// 
// 1)
// { 3, 100, 90 }
// { 5, 1, 18, 29 }
// 
// Returns: 0
// 
// 2)
// { 1, 1, 1, 1, 1, 5 }
// { -10, -9, -8, -7, -6 }
// 
// Returns: 5
// 
// The sets may contain duplicate elements. Moving any of the 1's from the first set increases the means of both sets.
// 
// 3)
// { 12, 94, 53, 43, 58, 85, 55, 83, 47, 57 }
// { 23, 100, 98, 27, 9, 70, 39, 39, 54 }
// 
// Returns: 4
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!