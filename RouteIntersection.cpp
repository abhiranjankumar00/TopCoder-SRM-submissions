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

class RouteIntersection
{
public:
	string isValid(int N, vector <int> coords, string moves);
};

string RouteIntersection::isValid (int N, vector <int> coords, string moves) 
{
	string ret;
	
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, string p2, bool hasAnswer, string p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "\"" << p2 << "\"";
	cout << "]" << endl;
	RouteIntersection *obj;
	string answer;
	obj = new RouteIntersection();
	clock_t startTime = clock();
	answer = obj->isValid(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p3 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	vector <int> p1;
	string p2;
	string p3;
	
	{
	// ----- test 0 -----
	p0 = 1;
	int t1[] = {1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "+";
	p3 = "VALID";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	int t1[] = {1,2,1,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "++--";
	p3 = "NOT VALID";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 3;
	int t1[] = {1,2,3,1,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "+++--";
	p3 = "VALID";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 344447;
	int t1[] = {132,51717,628,344447,628,51717,344447,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "+-++-+--";
	p3 = "NOT VALID";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 1;
	int t1[] = {1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "+-";
	p3 = "NOT VALID";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 990630;
	int t1[] = {833196,524568,361663,108056,28026,824639,269315,440977,440977,765458,988451,242440,948414,130873,773990,765458,130873,28026,853121,553636,581069,82254,735536,833196,898562,898562,940783,988451,540613,317306,623194,940783,571384,988451,108056,514374,97664};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "--+---+-+++-+-+---++-++-+---+-+--+-++";
	p3 = "NOT VALID";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
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
// Little Dazdraperma likes to travel a lot. One day she made a route in an N-dimensional space. In this space each point is represented by N coordinates. The coordinates are indexed from 1 to N, inclusive. She started from the origin, i.e., a point where each coordinate is 0. Then she did several moves of the following type:
// 
//  First she chose a coordinate index, i.e., a number between 1 and N, inclusive.
//  Then she jumped to a point where the coordinate with the chosen index is either increased or decreased by 1 and all other coordinates remain the same.
// 
// Now Dazdraperma wonders whether she has ever visited the same point twice. You will be given a vector <int> coords and a string moves representing her route. The i-th element of coords is the coordinate index she has chosen during her i-th move. If the coordinate with this index was increased during the i-th move, the i-th character of moves will be '+', and it will be '-' if this coordinate was decreased.
// 
// 
// Return "VALID" if all points of her route were unique, including the first and the last points, and return "NOT VALID" otherwise. Two points A and B in N-dimensional space are different if there's an index i such that A's coordinate with index i and B's coordinate with index i are different.
// 
// DEFINITION
// Class:RouteIntersection
// Method:isValid
// Parameters:int, vector <int>, string
// Returns:string
// Method signature:string isValid(int N, vector <int> coords, string moves)
// 
// 
// CONSTRAINTS
// -N will be between 1 and 1000000000 (109), inclusive.
// -coords will contain between 1 and 50 elements, inclusive.
// -Each element of coords will be between 1 and N, inclusive.
// -moves will contain the same number of characters as the number of elements in coords.
// -Each character in moves will be either '+' or '-'.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// {1}
// "+"
// 
// Returns: "VALID"
// 
// Dazdraperma starts at (0) and then jumps to (1). The answer is "VALID".
// 
// 1)
// 2
// {1,2,1,2}
// "++--"
// 
// Returns: "NOT VALID"
// 
// The route goes through 5 points:
// (0,0) -> (1,0) -> (1,1) -> (0,1) -> (0,0). The point (0,0) was visited twice.
// 
// 2)
// 3
// {1,2,3,1,2}
// "+++--"
// 
// Returns: "VALID"
// 
// (0,0,0) -> (1,0,0) -> (1,1,0) -> (1,1,1) -> (0,1,1) -> (0,0,1).
// 
// 3)
// 344447
// {132,51717,628,344447,628,51717,344447,2}
// "+-++-+--"
// 
// Returns: "NOT VALID"
// 
// The repeated point doesn't have to be the first or the last point in the route.
// 
// 4)
// 1
// {1,1}
// "+-"
// 
// Returns: "NOT VALID"
// 
// 
// 
// 5)
// 990630
// {833196,524568,361663,108056,28026,824639,269315,440977,440977,765458,
// 988451,242440,948414,130873,773990,765458,130873,28026,853121,553636,
// 581069,82254,735536,833196,898562,898562,940783,988451,540613,317306,
// 623194,940783,571384,988451,108056,514374,97664}
// "--+---+-+++-+-+---++-++-+---+-+--+-++"
// 
// Returns: "NOT VALID"
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
