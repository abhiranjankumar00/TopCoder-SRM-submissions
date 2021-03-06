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

class SafeRemoval
{
public:
	int removeThem(vector <int> seq, int k);
};

vvi sum(4);
int dp[55][55][55][55];

int solve(int id0, int id1, int id2, int id3) {
	int &ret = dp[id0][id1][id2][id3];

	if(ret != -2)
		return ret ;

	ret = -1;

	int add = sum[0][id0] + sum[1][id1] + sum[2][id2] + sum[3][id3];

	if( add % 4 != 0 && id0 + 1 < sum[0].size() && solve(id0+1, id1, id2, id3) != -1)
		ret = max(ret, solve(id0+1, id1, id2, id3));

	if( add % 4 != 1 && id1 + 1 < sum[1].size() && solve(id0, id1+1, id2, id3) != -1)
		ret = max(ret, solve(id0+1, id1, id2, id3));

	if( add % 4 != 2 && id2 + 1 < sum[2].size() && solve(id0, id1, id2+1, id3) != -1)
		ret = max(ret, solve(id0+1, id1, id2, id3));

	if( add % 4 != 3 && id3 + 1 < sum[3].size() && solve(id0, id1, id2, id3+1) != -1)
		ret = max(ret, solve(id0+1, id1, id2, id3));

	return ret;
}

int SafeRemoval::removeThem (vector <int> seq, int k) 
{
	sort(all(seq));
	reverse(all(seq));

	forn(i, 4)	sum[i].clear();
	forn(i, 4)	sum[i].pb(0);
	forn(i1, 55)	forn(i2, 55)
		forn(i3, 55)	forn(i4, 55)
			dp[i1][i2][i3][i4] = -2;

	tr(it, seq)
		sum[*it % 4].pb(*it + *sum[*it % 4].rbegin());
	
	dp [sum[0].size()-1] [sum[1].size()-1] [sum[2].size()-1] [sum[3].size()-1] = accumulate(all(seq), 0);

	forn(i, 4) {
		cout << i << ": ";
		tr(it, sum[i])
			cout << *it << " ";
		cout << endl;
	}

	int ret = -1;

	forn(i0, sum[0].size())		forn(i1, sum[1].size())	
		forn(i2, sum[2].size())		forn(i3, sum[3].size())
			if(i0 + i1 + i2 + i3 == seq.size()-k)
				ret = max(ret, solve(i0, i1, i2, i3));

	return ret;
	return -1;
}

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
	SafeRemoval *obj;
	int answer;
	obj = new SafeRemoval();
	clock_t startTime = clock();
	answer = obj->removeThem(p0, p1);
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
	int t0[] = {3,8,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 11;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {1,1,1,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = -1;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,6,1,10,1,2,7,11};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 6;
	p2 = 21;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,1,1,1,1,1,1,1,7};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 6;
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
// Did you know that platypuses can be very superstitious? A certain platypus was on a mission to remove exactly k numbers from a sequence in such a way that the sum of the remaining numbers is as large as possible. This task would have been very simple, were it not the case that our platypus wants to avoid some unlucky situations.
// 
// More precisely, our platypus thinks that the number 4 is unlucky, and so are all its multiples.
// Fortunately, the sum of the original sequence of numbers is not a multiple of 4. The platypus wants to keep it that way. It will only consider removing a number from the sequence if after the removal the sum of the remaining elements is not a multiple of 4. We will call such a removal safe.
// 
// You are given vector <int> seq and int k. If it is possible to perform exactly k safe removals (one element at a time), return the maximum possible sum of the elements remaining after the k removals. In case it is not possible to perform k safe removals, return -1.
// 
// DEFINITION
// Class:SafeRemoval
// Method:removeThem
// Parameters:vector <int>, int
// Returns:int
// Method signature:int removeThem(vector <int> seq, int k)
// 
// 
// CONSTRAINTS
// -seq will contain between 2 and 50 elements, inclusive.
// -Each element of seq will be between 1 and 1000, inclusive.
// -k will be at least 1. 
// -k will be less than the number of elements in seq.
// -The sum of all elements of seq will not be a multiple of 4.
// 
// 
// EXAMPLES
// 
// 0)
// {3, 8, 4}
// 1
// 
// Returns: 11
// 
// The best move for the platypus is to remove 4.
// The platypus cannot remove 3, because the remaining elements would add up to 4+8 = 12, a multiple of 4.
// Removing 8 is safe, but the total sum of the remaining elements, 3+4=7 is smaller than 11.
// 
// 1)
// {1,1,1,1,1,1}
// 3
// 
// Returns: -1
// 
// The initial sum is 6. After removing any of the elements, the sum becomes 5. At that point it becomes impossible to remove any of the remaining elements without making the sum a multiple of 4.
// 
// 2)
// {1,6,1,10,1,2,7,11}
// 6
// 
// Returns: 21
// 
// 
// 
// 3)
// {1,1,1,1,1,1,1,1,7}
// 3
// 
// Returns: 6
// 
// One of the three removed elements has to be the 7. The platypus has to remove the elements either in the order 1,7,1, or in the order 1,1,7.
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
