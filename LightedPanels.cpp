#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;
/*
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
#define endl		("\n")
#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define PI		M_PI
#define E 		M_E
#define	eps		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	cl(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

#if (0)
	#define debug 
#else 
	#define debug(x)	cout << #x << " = " << x << "\n"
#endif

class LightedPanels
{
public:
	int minTouch(vector <string> board);
};

int LightedPanels::minTouch (vector <string> board) 
{
	int ret;
	
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	LightedPanels *obj;
	int answer;
	obj = new LightedPanels();
	clock_t startTime = clock();
	answer = obj->minTouch(p0);
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
		res = answer == p1;
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"*****","*...*","*...*","*...*","*****"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {".*"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = -1;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"**.","**.","..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"*...","**..","..**","...*"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
// You are given a rectangular board consisting of several light panels.  Character j of element i of board represents the panel in row i, column j. '*' means the panel is on, and '.' means it's off.  When you touch a panel, its state will be toggled.  In other words, if you touch a panel that's on, it will turn off, and if you touch a panel that's off, it will turn on.  Because the panels are so sensitive, when you touch a panel, all of its horizontally, vertically, and diagonally adjacent panels will also toggle their states.
// 
// 
// Your goal is to have all the light panels in the board be on at the same time.  Return the minimum number of touches required to achieve this goal, or return -1 if it is impossible.
// 
// 
// DEFINITION
// Class:LightedPanels
// Method:minTouch
// Parameters:vector <string>
// Returns:int
// Method signature:int minTouch(vector <string> board)
// 
// 
// CONSTRAINTS
// -board will contain between 1 and 8 elements, inclusive.
// -Each element of board will contain between 1 and 8 characters, inclusive.
// -Each element of board will contain the same number of characters.
// -board will contain only the characters '*' and '.'.
// 
// 
// EXAMPLES
// 
// 0)
// {"*****",
//  "*...*",
//  "*...*",
//  "*...*",
//  "*****"}
// 
// Returns: 1
// 
// Just touch the panel in the center of the board.
// 
// 1)
// {".*"}
// 
// Returns: -1
// 
// Here touching any panel makes both panels toggle its state. So it's impossible to light both panels at the same time.
// 
// 2)
// {"**.",
//  "**.",
//  "..."}
// 
// Returns: 2
// 
// First touch the panel in row 0, column 0 to turn all the panels off, and then touch the panel in row 1, column 1.
// 
// 3)
// {"*...",
//  "**..",
//  "..**",
//  "...*"}
// 
// Returns: 10
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
