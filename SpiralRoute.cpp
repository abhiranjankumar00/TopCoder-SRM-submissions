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

class SpiralRoute
{
public:
	vector <int> thronePosition(int width, int length);
};

const int mx = 5001;
bool vis[mx][mx];
int N, M;

bool valid(int x, int y) {
	return x >= 0 && x < M && y >= 0 && y < N && vis[x][y] == false;
}

int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};

vector <int> SpiralRoute::thronePosition (int width, int length) 
{
	cl(vis, 0);
	N = length, M = width;
//	swap(N, M);
	int id = 0;
	int x = 0, y = 0;
	vis[x][y] = true;
	debug(N);
	debug(M);

	while(true) {
		if(!valid(x + X[id], y + Y[id])) {
			id = (id + 1)% 4;
		}
		if(!valid(x + X[id], y + Y[id])) {
			break;
		}
//		Pf("(%d, %d) -> ", x, y);
		x += X[id]; y += Y[id];
		vis[x][y] = true;
	}
	cout << endl;

	vector <int> ret;
	ret.pb(x);
	ret.pb(y);
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, vector <int> p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	SpiralRoute *obj;
	vector <int> answer;
	obj = new SpiralRoute();
	clock_t startTime = clock();
	answer = obj->thronePosition(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p2.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p2[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p2.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p2[i]) {
					res = false;
				}
			}
		}
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
	vector <int> p2;
	
	{
	// ----- test 0 -----
	p0 = 6;
	p1 = 4;
	int t2[] = {1,2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 6;
	p1 = 5;
	int t2[] = {3,2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 11;
	int t2[] = {0,10};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 12;
	p1 = 50;
	int t2[] = {5,6};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 5000;
	p1 = 5000;
	int t2[] = {2499,2500};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
// The King of Elbonia lives in a palace that is width meters by length meters. Since he makes his subjects live in mud, he is not very popular. He wants the palace partitioned so that visitors have to walk a long way to reach him. His security advisors have settled on a spiral. A visitor enters the palace at the South-West corner and starts walking East. Every time the visitor reaches an outer wall or his own path, he turns left. The corridors in the spiral are 1 meter wide. The diagram below shows an example of a spiral path: the visitor moves from a (the South-West corner) through the alphabet to x, the throne.
// 
// nmlkji
// oxwvuh
// pqrstg
// abcdef
// 
// The King wants to have his throne correctly placed before all the partitioning is done, so he needs to know where the spiral will end. Write a class SpiralRoute with a method thronePosition that returns two integers, indicating the coordinates of the throne. The South-West corner is (0, 0), the South-East corner is (width - 1, 0) and the North-East corner is (width - 1, length - 1).
// 
// 
// DEFINITION
// Class:SpiralRoute
// Method:thronePosition
// Parameters:int, int
// Returns:vector <int>
// Method signature:vector <int> thronePosition(int width, int length)
// 
// 
// CONSTRAINTS
// -width and length will both be between 1 and 5000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 6
// 4
// 
// Returns: {1, 2 }
// 
// This is the example above.
// 
// 1)
// 6
// 5
// 
// Returns: {3, 2 }
// 
// 
// 
// 2)
// 1
// 11
// 
// Returns: {0, 10 }
// 
// 
// 
// 3)
// 12
// 50
// 
// Returns: {5, 6 }
// 
// 
// 
// 4)
// 5000
// 5000
// 
// Returns: {2499, 2500 }
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
