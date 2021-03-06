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
using namespace std;

typedef long long  int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector <int> > vvi;
typedef pair<int,int> ii;
typedef vector <string> vs;

#define Pf	printf
#define	Sf	scanf

#define	ep	1e-9
#define PI M_PI
#define E M_E

#define	CL(a, b)	memset(a, b, sizeof(a))
#define	mp	make_pair

#define	pb	push_back

#define	all(c)	(c).begin(), (c).end()
#define	tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())		//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0, loop_ends_here = (int)n; i < loop_ends_here; i++)
#define forab(i, a, b)	for(int i = a, loop_ends_here = (int) b; i <= loop_ends_here; i++)
#define rep(i, a, b)	for(int i = a, loop_ends_here = (int)b; i>=loop_ends_here; i--)

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

class PatrolRoute
{
public:
	int countRoutes(int X, int Y, int minT, int maxT);
};

const int64 p = 1e9 + 7;

int PatrolRoute::countRoutes (int X, int Y, int minT, int maxT) 
{
	int64 ret = 0;
	forab(x, 2, X-1)	forab(y, 2, Y-1)	if(2*x + 2*y >= minT && 2*x + 2*y <= maxT) {
		ret += ( X - x*1ll) * (x-1ll) * (Y - y*1ll) * (y-1ll);
		ret %= p;
	}
	
	return (ret*6)%p;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	PatrolRoute *obj;
	int answer;
	obj = new PatrolRoute();
	clock_t startTime = clock();
	answer = obj->countRoutes(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	int p3;
	int p4;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 3;
	p2 = 1;
	p3 = 20000;
	p4 = 6;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 3;
	p2 = 4;
	p3 = 7;
	p4 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 6;
	p2 = 9;
	p3 = 12;
	p4 = 264;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 7;
	p1 = 5;
	p2 = 13;
	p3 = 18;
	p4 = 1212;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 4000;
	p1 = 4000;
	p2 = 4000;
	p3 = 14000;
	p4 = 859690013;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
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
// There are exactly X*Y places in the Planar Kingdom: For each pair of integers (x, y) such that 0 <= x < X and 0 <= y < Y there is a place with coordinates (x, y). When a citizen of the kingdom wants to move from (x1, y1) to (x2, y2), the required time is |x1 - x2| + |y1 - y2| (where |t| denotes the absolute value of t).
// 
// In order to improve stability in the kingdom, the police wants to introduce a specific patrol route. The route will contain exactly three places A, B, and C.
// A policeman will visit these three places and verify that everything is as it should be. The three places that determine a valid route must satisfy the following criteria::
// 
// x-coordinates of A, B and C are pairwise distinct.
// y-coordinates of A, B and C are pairwise distinct.
// Let T be the total time required to follow along the route: first from A to B, then from B to C and finally from C back to A. T must be between minT and maxT, inclusive.
// 
// 
// You are given the ints X, Y, minT, and maxT. Return the number of different patrol routes that satisfy these criteria, modulo 1,000,000,007. Two routes are considered to be different if there is a place that belongs to one of them, but does not belong to the other one.
// 
// DEFINITION
// Class:PatrolRoute
// Method:countRoutes
// Parameters:int, int, int, int
// Returns:int
// Method signature:int countRoutes(int X, int Y, int minT, int maxT)
// 
// 
// CONSTRAINTS
// -X and Y will each be between 3 and 4,000, inclusive.
// -minT will be between 1 and 20,000, inclusive.
// -maxT will be between minT and 20,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// 3
// 1
// 20000
// 
// Returns: 6
// 
// The time requirement is very flexible in this case. There are 6 patrol routes where both x and y coordinates of places are pairwise distinct.
// 
// 1)
// 3
// 3
// 4
// 7
// 
// Returns: 0
// 
// The time of 7 is too small for any patrol route.
// 
// 2)
// 4
// 6
// 9
// 12
// 
// Returns: 264
// 
// 
// 
// 3)
// 7
// 5
// 13
// 18
// 
// Returns: 1212
// 
// 
// 
// 4)
// 4000
// 4000
// 4000
// 14000
// 
// Returns: 859690013
// 
// Don't forget about the modulo!
// 
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!3**/6
