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

#define endl 		("\n")
#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define Pf		printf
#define	Sf		scanf

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

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

class TheDivisionGame
{
public:
	long long countWinningIntervals(int L, int R);
};


long long TheDivisionGame::countWinningIntervals (int L, int R) 
{
	long long ret;
	
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	TheDivisionGame *obj;
	long long answer;
	obj = new TheDivisionGame();
	clock_t startTime = clock();
	answer = obj->countWinningIntervals(p0, p1);
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
	
	int p0;
	int p1;
	long long p2;
	
	{
	// ----- test 0 -----
	p0 = 9;
	p1 = 10;
	p2 = 2ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 5;
	p2 = 9ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 2;
	p1 = 6;
	p2 = 13ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 2;
	p1 = 100;
	p2 = 4345ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 12566125;
	p1 = 12567777;
	p2 = 1313432ll;
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
// Manao likes to play the Division Game with his friends. This two-player game is played with some collection of natural numbers S. Manao plays first and the players alternate in making a move. A move is choosing some number X from S and a natural number Y &gt 1 such that Y divides X. Then, X is replaced by X / Y in the collection. Note that at any moment the collection may contain multiple copies of the same number. The game proceeds until no more moves can be made. The player who managed to make the last move is declared the winner.
// 
// Since hot debates arise on what numbers should be in S, the friends decided to regularize their choice. They always choose a contiguous interval of numbers [A, B] to be the initial collection S. That is, at the beginning of the game, the collection S contains each of the integers A through B, inclusive, exactly once. Manao knows that A and B will satisfy the condition L &le A &le B &le R. You are given the ints L and R. Count the number of such intervals for which Manao will win the Division Game given that both players play optimally.
// 
// DEFINITION
// Class:TheDivisionGame
// Method:countWinningIntervals
// Parameters:int, int
// Returns:long long
// Method signature:long long countWinningIntervals(int L, int R)
// 
// 
// NOTES
// -Only one number from the collection changes in each move. For example, if the collection contains three copies of the number 8, and the player chooses X=8 and Y=4, only one of the 8s in the collection will change to a 2.
// 
// 
// CONSTRAINTS
// -L will be between 2 and 1,000,000,000, inclusive.
// -R will be between L and L + 1,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 9
// 10
// 
// Returns: 2
// 
// If the chosen interval is [9,9] or [10,10], the collection S contains only one number. In these two situations Manao can win the game in a single move. On the other hand, if the chosen interval is [9,10], Manao will lose to an optimally playing opponent.
// 
// 
// 1)
// 2
// 5
// 
// Returns: 9
// 
// The only case where Manao loses is if the game starts with the interval [2,3]. Note that if the starting interval is [2,5], Manao can choose X=4 and Y=2 in his first move. After that move, the collection will contain the values 2, 2, 3, and 5.
// 
// 2)
// 2
// 6
// 
// Returns: 13
// 
// Manao will also lose the game if the starting interval is [3,6].
// 
// 3)
// 2
// 100
// 
// Returns: 4345
// 
// 
// 
// 4)
// 12566125
// 12567777
// 
// Returns: 1313432
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!