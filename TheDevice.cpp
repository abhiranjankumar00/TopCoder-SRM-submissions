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
#include <iterator>
#include <fstream>
using namespace std;

typedef long long  int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector <int> > vvi;
typedef pair<int,int> ii;
typedef vector <string> vs;

#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define endl 		("\n")

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

#define Pf		printf
#define	Sf		scanf

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

class TheDevice
{
public:
	int minimumAdditional(vector <string> plates);
};

int TheDevice::minimumAdditional (vector <string> plates) 
{
	vi cntZero(plates[0].size()), cntOne(plates[0].size());
	forn(i, plates.size())	forn(j, plates[i].size())
		if(plates[i][j] == '1')
			cntOne[j]++;
		else
			cntZero[j]++;
	int ret = 0;

/*
	tr(it, cntOne)
		write(*it);
	cout << endl;
	tr(it, cntZero)
		write(*it);
	cout << endl;
*/
	forn(i, cntOne.size()) {
		int tmp = 0;
		if(cntOne[i] == 0)
			tmp+=2;
		else if(cntOne[i] == 1)
			tmp++;
		if(cntZero[i] == 0)
			tmp++;
//		Pf("%d: %d\n", i, tmp);
		ret = max(ret, tmp);
	}

	
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
	TheDevice *obj;
	int answer;
	obj = new TheDevice();
	clock_t startTime = clock();
	answer = obj->minimumAdditional(p0);
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
	string t0[] = {"010","011","101"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"0","1","0","1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"01010101","10101010"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"10010101011","00010101001","00100010111","00101010101","01010111101"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"1101001011010","0010000010101","1010101011110","1101010100111","1011111110111"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
// Manao works at a laboratory on a highly classified project. From time to time, he is given a special device and has to determine its exact structure. Every such device operates on special plates. There are M bits written on each of the plates from left to right. The device has two inputs and a screen. Each input requires a plate. When two plates are connected to the device, M bits of output appear on the screen. Each bit of output is either a binary OR, AND or XOR of the corresponding bits of the input plates. Manao's task is to determine what operation is carried out for each of the bits.
// 
// Manao has N plates. He is going to test the device on each possible pair of these plates and determine its structure by the outputs on the screen. It might be that the plates Manao has are not enough to uniquely identify every possible device. You are given vector <string> plates, where each element describes a plate Manao has. Return the minimum number of additional plates Manao needs to be able to determine the structure of any device.
// 
// DEFINITION
// Class:TheDevice
// Method:minimumAdditional
// Parameters:vector <string>
// Returns:int
// Method signature:int minimumAdditional(vector <string> plates)
// 
// 
// CONSTRAINTS
// -plates will contain between 1 and 50 elements, inclusive.
// -Each element of plates will be between 1 and 50 characters long, inclusive.
// -All elements of plates will be of equal length.
// -Each element of plates will contain characters from the set {'0', '1'} only.
// 
// 
// EXAMPLES
// 
// 0)
// {"010",
//  "011",
//  "101"}
// 
// Returns: 1
// 
// It is possible to find two different devices such that no pair of Manao's plates will distinguish between them. To fix this it is sufficient to add one more plate. An example of such a plate is "101". There are also other plates that would work in its place.
// 
// 
// 1)
// {"0",
//  "1",
//  "0",
//  "1"}
// 
// Returns: 0
// 
// With these plates, Manao can test the output for every possible pair of bits, which allows him to distinguish between AND, OR and XOR.
// 
// 2)
// {"01010101",
//  "10101010"}
// 
// Returns: 1
// 
// 
// 
// 3)
// {"10010101011",
//  "00010101001",
//  "00100010111",
//  "00101010101",
//  "01010111101"}
// 
// Returns: 1
// 
// 
// 
// 4)
// {"1101001011010",
//  "0010000010101",
//  "1010101011110",
//  "1101010100111",
//  "1011111110111"}
// 
// Returns: 0
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
