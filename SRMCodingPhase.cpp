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
#define	tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())		//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0, loop_ends_here = (int)n; i < loop_ends_here; i++)
#define forab(i, a, b)	for(int i = a, loop_ends_here = (int) b; i <= loop_ends_here; i++)
#define rep(i, a, b)	for(int i = a, loop_ends_here = (int)b; i>=loop_ends_here; i--)

#define forN(i, n)	for(i = 0; i < n; i++)

class SRMCodingPhase
{
public:
	int ret;
	vi pts, time;

	void hahaha(int idx, int curPts, int luck, int timeConsumed) {

		if(timeConsumed > 75)	return;

		if(idx == 3) {
			ret = max(ret, curPts);
			return;
		}

		hahaha(idx+1, curPts, luck, timeConsumed);

		forn(luckUsed, luck+1) {
			int t = max(1, time[idx] - luckUsed);
			int pt = curPts + pts[idx] - (2 << idx)*t;
			
			hahaha(idx+1, pt, luck - luckUsed, timeConsumed + t);
		}
	}

	int countScore(vector <int> _pts, vector <int> _time, int luckPts)
	{
		ret = 0;
		pts.clear(),	time.clear();
		pts = _pts, time = _time;
		hahaha(0, 0, luckPts, 0);
		return ret;
/*
		int ret = 0, ans, totalTime, luck[3], timeUsed[3];

		forN(luck[0], luckPts+1)	forN(luck[1], luckPts + 1)	if( (luck[2] = luckPts - luck[0] - luck[1]) >= 0 ) {

			forn(i, 3) 		timeUsed[i] = max(time[i] - luck[i], 1);
		
			forab(i, 1, (1<<3) - 1) {
				ans = totalTime = 0;

				forn(j, 3)	if( i & (1<<j)) 
					totalTime += timeUsed[j], 	ans += pts[j] - (2<<j) * timeUsed[j];

				ret = totalTime <= 75 ? max(ret, ans) : ret;
			}
		}
		
		return ret;
*/
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, int p3) {
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
	cout << "}" << "," << p2;
	cout << "]" << endl;
	SRMCodingPhase *obj;
	int answer;
	obj = new SRMCodingPhase();
	clock_t startTime = clock();
	answer = obj->countScore(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	int t0[] = {250,500,1000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {10,25,40};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	p3 = 1310;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {300,600,900};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {30,65,90};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 25;
	p3 = 680;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {250,550,950};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {10,25,40};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 75;
	p3 = 1736;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {256,512,1024};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {35,30,25};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	p3 = 1216;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {300,600,1100};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {80,90,100};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	p3 = 0;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
// Mr. Dengklek introduced you to an online programming contest called SRM (Special Round Match)!
// 
// You are now in the coding phase of the contest. There are 3 problems in the contest. You have practiced a lot before in practice rooms, so you are sure that you can solve the first problem in skills[0] minutes, the second problem in skills[1] minutes and the third problem is skills[2] minutes.
// 
// You have exactly 75 minutes to solve the problems. Before submitting a solution to a problem, you must first open the problem. If you submit a solution to a problem t minutes after you open the problem, you will receive:
// 
// (points[0] - 2t) points for the first problem, or
// (points[1] - 4t) points for the second problem, or
// (points[2] - 8t) points for the third problem.
// 
// 
// In your strategy, you only submit a solution to a problem after you solve the problem. If you don't submit a solution to a problem, you will receive zero points for the problem.
// 
// It is well-known that luck plays an important role in a contest. A fortune-teller told you that you have luck points of luck. You may use these points to decrease the amount of time you need to solve the problems, in minutes. Of course, you don't have to use all the points. Each point is worth one minute per problem. So, if you initially can solve a problem in t minutes, by using x points of luck (where x is a positive integer and 0 < x < t), you can solve the problem in (t - x) minutes (it is impossible to use t or more points of luck on the problem).
// 
// Arrange your strategy in this coding phase. Return the maximum total score you can achieve in this coding phase.
// 
// DEFINITION
// Class:SRMCodingPhase
// Method:countScore
// Parameters:vector <int>, vector <int>, int
// Returns:int
// Method signature:int countScore(vector <int> points, vector <int> skills, int luck)
// 
// 
// CONSTRAINTS
// -points will contain exactly 3 elements.
// -points[0] will be between 250 and 300, inclusive.
// -points[1] will be between 450 and 600, inclusive.
// -points[2] will be between 900 and 1100, inclusive.
// -skills will contain exactly 3 elements.
// -Each element of skills will be between 1 and 100, inclusive.
// -luck will be between 0 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {250, 500, 1000}
// {10, 25, 40}
// 0
// 
// Returns: 1310
// 
// You don't have any luck points. However, you can solve all the problems in exactly 75 minutes.
// 
// 1)
// {300, 600, 900}
// {30, 65, 90}
// 25
// 
// Returns: 680
// 
// Use 25 luck points on the 600-point problem, and then solve the 300- and 600-point problems.
// 
// 2)
// {250, 550, 950}
// {10, 25, 40}
// 75
// 
// Returns: 1736
// 
// Using the large amount of luck points, solve each problem in only 1 minute.
// 
// 3)
// {256, 512, 1024}
// {35, 30, 25}
// 0
// 
// Returns: 1216
// 
// 
// 
// 4)
// {300, 600, 1100}
// {80, 90, 100}
// 4
// 
// Returns: 0
// 
// 
// 
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
