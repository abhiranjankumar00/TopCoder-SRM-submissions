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

class PaintingBoards
{
public:
	double minimalTime(vector <int> boardLength, vector <int> painterSpeed);
};


double PaintingBoards::minimalTime (vector <int> boardLength, vector <int> painterSpeed) 
{
	double ret;
	
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, double p2) {
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
	PaintingBoards *obj;
	double answer;
	obj = new PaintingBoards();
	clock_t startTime = clock();
	answer = obj->minimalTime(p0, p1);
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
		res = answer == answer && fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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
	double p2;
	
	{
	// ----- test 0 -----
	int t0[] = {5,3,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,3,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {1,2,1,4,2,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2.0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {40,46,82,89,33,46,3,50,95,81,69,40,94,93,90,98,17,34,45,18,93,28,43,38,35};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {49,51,35,27,48,36,54,10};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4.686274509803922;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {3,3,20};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {9,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2.888888888888889;
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
// There are several boards arranged side by side in a straight line. Boards go in order and you can't change the order of boards. The length of the i-th board in the line is boardLength[i] inches.  There are also several painters.  The i-th painter can paint a one inch length of board in 1/painterSpeed[i] seconds. You can assign jobs to some of painters (not necessarily to all of them). Each painter can be assigned at most a single block of one or more consecutive boards. All the painters start at the same time and work simultaneously.  Return the minimal number of seconds needed to paint all the boards.
// 
// 
// DEFINITION
// Class:PaintingBoards
// Method:minimalTime
// Parameters:vector <int>, vector <int>
// Returns:double
// Method signature:double minimalTime(vector <int> boardLength, vector <int> painterSpeed)
// 
// 
// NOTES
// -Painters do not have to be assigned to boards in any particular order.  For example, painter 2 can be assigned to boards 1 to 3, while painter 1 is assigned to boards 4 to 5, etc.
// -The returned value must be accurate to within a relative or absolute value of 1E-9.
// 
// 
// CONSTRAINTS
// -boardLength will contain between 1 and 50 elements, inclusive.
// -Each element of boardLength will be between 1 and 10000, inclusive.
// -painterSpeed will contain between 1 and 15 elements, inclusive.
// -Each element of painterSpeed will be between 1 and 10000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {5,3,2}
// {2,3,5}
// 
// Returns: 1.0
// 
// Assign painter 3 (1-indexed) to the board of length 5, painter 2 to the board of length 3, and painter 1 to the board of length 2.  Each painter will finish in exactly one second.
// 
// 1)
// {1,2,1,4,2,1,1}
// {1,2,3}
// 
// Returns: 2.0
// 
// Assign painter 2 (1-indexed) to the first three boards {1, 2, 1}, painter 3 to the next two boards {4, 2}, and painter 1 to the last two boards {1, 1}.  Each painter will finish in exactly 2 seconds.
// 
// 2)
// {40, 46, 82, 89, 33, 46, 3, 50, 95, 
// 81, 69, 40, 94, 93, 90, 98, 17, 34, 
// 45, 18, 93, 28, 43, 38, 35}
// {49, 51, 35, 27, 48, 36, 54, 10}
// 
// Returns: 4.686274509803922
// 
// 
// 
// 3)
// {3,3,20}
// {9,1}
// 
// Returns: 2.888888888888889
// 
// It's better to assign everything to the fast painter and not assign anything to the slow painter.
// 
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
