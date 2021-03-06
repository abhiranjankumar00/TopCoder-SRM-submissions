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

class SRMRoomAssignmentPhase
{
public:
	int countCompetitors(vector <int> r, int K)
	{
		int you = r[0];
		sort(all(r));
		reverse(all(r));
		vvi room(K);
		int idx =0;

		forn(i, r.size()) {
			if(r[i] == you)
				return room[idx].size();
			room[idx].pb(r[i]);
			idx = (idx + 1) % K;
		}

	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	SRMRoomAssignmentPhase *obj;
	int answer;
	obj = new SRMRoomAssignmentPhase();
	clock_t startTime = clock();
	answer = obj->countCompetitors(p0, p1);
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
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	int t0[] = {491,981,1199,763,994,879,888};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {1024,1000,600};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {505,679,900,1022};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 1;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {716,58,1000,1004,912,822,453,1100,558};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 1;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {422,623,1023,941,882,776,852,495,803,622,618,532,751,500};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	p2 = 3;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {1197,1198,1196,1195,1199};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 2;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
// There are N coders in the contest, including you. Each coder has a skill measurement called rating. This information is given in ratings, where ratings[0] is your rating and ratings[1] through ratings[N-1] are the ratings of the other coders. Ratings of all coders are pairwise distinct.
// 
// You are now in the room assignment phase of the contest. There are K available rooms. Each coder will be assigned to exactly one room in the following way: the coders, in descending order of their ratings, are assigned one-by-one to rooms 1, 2, ..., K, 1, 2, ..., K, ... and so on in that order. See the examples for further clarification.
// 
// You wish to win your room, so you wonder how many stronger competitors you have. Return the number of coders in your room who have higher ratings than yours.
// 
// DEFINITION
// Class:SRMRoomAssignmentPhase
// Method:countCompetitors
// Parameters:vector <int>, int
// Returns:int
// Method signature:int countCompetitors(vector <int> ratings, int K)
// 
// 
// CONSTRAINTS
// -ratings will contain between 2 and 50 elements, inclusive.
// -Each element of ratings will be between 0 and 1199, inclusive.
// -All elements of ratings will be distinct.
// -K will be between 1 and the number of elements in ratings, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {491, 981, 1199, 763, 994, 879, 888}
// 3
// 
// Returns: 2
// 
// Here is the room assignment for all coders.
// 
// Room 1 coders' ratings:
// 
// 1199
// 888
// 491
// 
// 
// Room 2 coders' ratings:
// 
// 994
// 879
// 
// 
// Room 3 coders' ratings:
// 
// 981
// 763
// 
// 
// You are in Room 1, and there are 2 coders with greater ratings than yours.
// 
// 
// 
// 1)
// {1024, 1000, 600}
// 1
// 
// Returns: 0
// 
// You are the highest rated coder in Room 1.
// 
// 2)
// {505, 679, 900, 1022}
// 2
// 
// Returns: 1
// 
// You are the lowest rated coder in Room 2.
// 
// 3)
// {716, 58, 1000, 1004, 912, 822, 453, 1100, 558}
// 3
// 
// Returns: 1
// 
// You are the second highest rated coder in Room 3.
// 
// 4)
// {422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500}
// 4
// 
// Returns: 3
// 
// 
// 
// 5)
// {1197, 1198, 1196, 1195, 1199}
// 1
// 
// Returns: 2
// 
// 
// 
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
