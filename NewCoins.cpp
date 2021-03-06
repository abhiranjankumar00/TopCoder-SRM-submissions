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

class NewCoins
{
public:
	int minCoins(vector <int> price);
};


int lcm(int a, int b) {
	return a / __gcd(a, b) * b;
}
const int mx = 1e5 +11;
vi coins, price;
int ways[mx];

void countWays() {
	cl(ways, -1);
	ways[0] = 0;
	int M = coins.size();

	forn(i, mx) {
		forn(j, M)	if(i - coins[j] >= 0 && ways[i-coins[j]] != -1) {
			if(ways[i] == -1 || ways[i] > ways[i-coins[j]] + 1)
				ways[i] = ways[i-coins[j]]+1;
		}
	}
}

int NewCoins::minCoins (vector <int> _price) 
{
	price = _price;
	sort(all(price));

	coins.clear();
	coins.pb(1);
	int val = 2, mul = 2;
	val = mul = 2;

	while(val < mx) {
		coins.pb(val);
		val  *= mul;
	}

	tr(it, coins)
		write(*it);
	cout << endl;

	countWays();

	tr(it, price)
		write(*it);
	cout << endl;

	tr(it, price)
		Pf("(%d, %d) ", *it, ways[*it]);
	cout << endl;

	int ret = 0;

	tr(it, price)
		ret += ways[*it];

	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	NewCoins *obj;
	int answer;
	obj = new NewCoins();
	clock_t startTime = clock();
	answer = obj->minCoins(p0);
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
	
	vector <int> p0;
	int p1;
	
	{
	// ----- test 0 -----
	int t0[] = {28,569,587,256,15,87,927,4,589,73,98,87,597,163,6,498};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 62;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
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
// As a finance minister, Bob decided to make new denominations of coins. If the values of the coins are x1, x2, x3, ... in ascending order then x1 must be 1 and xb must be an integer multiple of xa for all b > a.
// 
// 
// He has a list of products sold in his country. The price of the i-th product is price[i]. He wants to minimize the number of coins required to buy each product exactly once. Each product must be purchased separately using coins that total to exactly the value of the product. Using multiple coins of the same denomination is allowed. See example 0 for further clarification.
// 
// 
// Return the minimal number of coins required to buy each product exactly once.
// 
// DEFINITION
// Class:NewCoins
// Method:minCoins
// Parameters:vector <int>
// Returns:int
// Method signature:int minCoins(vector <int> price)
// 
// 
// CONSTRAINTS
// -price will contain between 1 and 50 elements, inclusive.
// -Each element in price will be between 1 and 100,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {25, 102}
// 
// Returns: 4
// 
// Bob can use {1, 25, 100} as the new set of coins. Then, a single coin of value 25 can be used to buy the first product. To buy the second product, one coin of value 100 and two coins of value 1 is sufficient. So, in total, 4 coins can be used to buy all products using the new set of coins.
// 
// 1)
// {58}
// 
// Returns: 1
// 
// One possible set of coins is {1, 58}.
// 
// 2)
// {1, 4, 5, 9, 16}
// 
// Returns: 7
// 
// One possible set of coins is {1, 2, 4, 8, 16}.
// 
// 3)
// {1, 1, 1, 1, 1}
// 
// Returns: 5
// 
// Different products may have the same price.
// 
// 4)
// {28, 569, 587, 256, 15, 87, 927, 4, 589, 73, 98, 87, 597, 163, 6, 498}
// 
// Returns: 62
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
