#include <bits/stdc++.h>
using namespace std;

class CrazyBot
{
public:
	double getProbability(int n, int east, int west, int south, int north);
};

bool vis[50][50];
double ret;
double east, west, south, north;
int N;

void dfs(int x, int y, int n, double p) {
	if(vis[x][y])
		return;
	if(n == N) {
		ret += p;
		return;
	}
	vis[x][y] = true;
	dfs(x-1, y, n+1, p*east);
	dfs(x+1, y, n+1, p*west);
	dfs(x, y-1, n+1, p*south);
	dfs(x, y+1, n+1, p*north);
	vis[x][y] = false;
}

double CrazyBot::getProbability (int n, int _east, int _west, int _south, int _north) 
{
	memset(vis, 0, sizeof(vis));
	east = _east/100.0; west=_west/100.0; north=_north/100.0; south = _south/100.0;
	N = n;
	ret = 0;

	dfs(25, 25, 0, 1.0);
	
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, bool hasAnswer, double p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	CrazyBot *obj;
	double answer;
	obj = new CrazyBot();
	clock_t startTime = clock();
	answer = obj->getProbability(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == answer && fabs(p5 - answer) <= 1e-9 * max(1.0, fabs(p5));
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
	double p5;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 25;
	p2 = 25;
	p3 = 25;
	p4 = 25;
	p5 = 1.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 25;
	p2 = 25;
	p3 = 25;
	p4 = 25;
	p5 = 0.75;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 7;
	p1 = 50;
	p2 = 0;
	p3 = 0;
	p4 = 50;
	p5 = 1.0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 14;
	p1 = 50;
	p2 = 50;
	p3 = 0;
	p4 = 0;
	p5 = 1.220703125E-4;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 14;
	p1 = 25;
	p2 = 25;
	p3 = 25;
	p4 = 25;
	p5 = 0.008845493197441101;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
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
// An out-of-control robot is placed on a plane, and it takes n random steps.  At each step, the robot chooses one of four directions randomly and moves one unit in that direction. The probabilities of the robot choosing north, south, east or west are north, south, east and west percent, respectively.
// 
// The robot's path is considered simple if it never visits the same point more than once.  (The robot's starting point is always the first visited point.)  Return a double containing the probability that the robot's path is simple.  For example, "EENE" and "ENW" are simple, but "ENWS" and "WWWWSNE" are not ('E', 'W', 'N' and 'S' represent east, west, north and south, respectively).
// 
// DEFINITION
// Class:CrazyBot
// Method:getProbability
// Parameters:int, int, int, int, int
// Returns:double
// Method signature:double getProbability(int n, int east, int west, int south, int north)
// 
// 
// NOTES
// -Your return must have relative or absolute error less than 1E-9.
// 
// 
// CONSTRAINTS
// -n will be between 1 and 14, inclusive.
// -east will be between 0 and 100, inclusive.
// -west will be between 0 and 100, inclusive.
// -south will be between 0 and 100, inclusive.
// -north will be between 0 and 100, inclusive.
// -The sum of east, west, south and north will be 100.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 25
// 25
// 25
// 25
// 
// Returns: 1.0
// 
// The robot only takes one step, so it never visits a point more than once.
// 
// 1)
// 2
// 25
// 25
// 25
// 25
// 
// Returns: 0.75
// 
// The robot will visit its starting point twice only if the two moves are in opposite directions.
// 
// 2)
// 7
// 50
// 0
// 0
// 50
// 
// Returns: 1.0
// 
// Here, the only possible directions are north and east, so the robot will never visit the same point twice.
// 
// 3)
// 14
// 50
// 50
// 0
// 0
// 
// Returns: 1.220703125E-4
// 
// Here, the only possible directions are east and west. The only two available paths are "EEEEEEEEEEEEEE" and "WWWWWWWWWWWWWW". The probability is equal to 2 / (2^14).
// 
// 4)
// 14
// 25
// 25
// 25
// 25
// 
// Returns: 0.008845493197441101
// 
// The probability is quite small for n=14.
// 
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
