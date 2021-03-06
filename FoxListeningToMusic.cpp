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

#define	ep	1e-300
#define PI M_PI
#define E M_E

#define	CL(a, b)	memset(a, b, sizeof(a))
#define	mp	make_pair

#define	pb	push_back
#define	SZ(a)	int((a).size())

#define	all(c)	(c).begin(), (c).end()
#define	tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())		//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define	forn(i, n)	for(int i = 0; i < n; i++)
#define	forab(i, a, b)	for(int i = a; i <= b; i++)
#define	rep(i, a, b)	for(int i = a; i>=b; i--)

double dp[80010][51];

class FoxListeningToMusic
{
public:
	vector <double> getProbabilities(vector <int> length, int T)
	{
		int N = length.size();
		vector <double> ret(N, 0.0);
		CL(dp, 0);

		double m = 1.0/N;

		forn(i, N)	dp[0][i] = m;

		forn(t, T+5) {
				forn(j, N) if(dp[t][j] >= ep){
					if(t <=T && t + length[j] > T)
							ret[j] += dp[t][j];
					forn(k, N)	 if(t + length[k] < 80005)
							dp[t + length[k] ] [j] += dp[t][j]*m;
				}
		}
		
		return ret;
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, vector <double> p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	FoxListeningToMusic *obj;
	vector <double> answer;
	obj = new FoxListeningToMusic();
	clock_t startTime = clock();
	answer = obj->getProbabilities(p0, p1);
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
				if (answer[i] != answer[i] || fabs(p2[i] - answer[i]) > 1e-9 * max(1.0, fabs(p2[i]))) {
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
	
	vector <int> p0;
	int p1;
	vector <double> p2;
	
	{
	// ----- test 0 -----
	int t0[] = {1,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	double t2[] = {0.25,0.75};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {1,10,100,1000,10000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	double t2[] = {0.2,0.2,0.2,0.2,0.2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {5,8,4,7};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10;
	double t2[] = {0.1875,0.3125,0.1875,0.3125};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {10,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 9;
	double t2[] = {0.9990234375,9.765625E-4};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {58,47,36,25,14,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 100;
	double t2[] = {0.32895835374381194,0.26291497538241776,0.18463894970453887,0.1312301113062895,0.07518634032025856,0.017071269542683242};
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
// Fox Jiro is going to listen to some music. He has N songs, numbered 0 to N-1, inclusive. The lengths of the songs are given in the vector <int> length, where the i-th element is the length in seconds of song i.
// 
// The music player he uses has a shuffle feature. Using this feature, he can listen to the songs in random order. More precisely, first the player chooses one song among all songs with equal probability and plays it. When the song ends, the player chooses the next song in the same fashion and plays it immediately. Note that the player may choose the same song more than once in a row.
// 
// You are given an int T. Return a double[] P, where P[i] indicates the probability that the player is playing the i-th song T+0.5 seconds after Jiro starts listening to the music in shuffle mode.
// 
// DEFINITION
// Class:FoxListeningToMusic
// Method:getProbabilities
// Parameters:vector <int>, int
// Returns:vector <double>
// Method signature:vector <double> getProbabilities(vector <int> length, int T)
// 
// 
// NOTES
// -Each element of the returned array must have an absolute or relative error less than 1e-9.
// 
// 
// CONSTRAINTS
// -length will contain 1 and 50 elements, inclusive.
// -Each element of length will be between 1 and 80,001, inclusive.
// -T will be between 0 and 80,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1, 2}
// 1
// 
// Returns: {0.25, 0.75 }
// 
// There are three possible scenarios that lead up to time 1.5:
// 
// song 0 -> song 0 (with probability 1/4)
// song 0 -> song 1 (with probability 1/4)
// song 1 (with probability 1/2)
// 
// 
// 
// 1)
// {1, 10, 100, 1000, 10000}
// 0
// 
// Returns: {0.2, 0.2, 0.2, 0.2, 0.2 }
// 
// 
// 
// 2)
// {5, 8, 4, 7}
// 10
// 
// Returns: {0.1875, 0.3125, 0.1875, 0.3125 }
// 
// 
// 
// 3)
// {10, 1}
// 9
// 
// Returns: {0.9990234375, 9.765625E-4 }
// 
// 
// 
// 4)
// {58, 47, 36, 25, 14, 3}
// 100
// 
// Returns: {0.32895835374381194, 0.26291497538241776, 0.18463894970453887, 0.1312301113062895, 0.07518634032025856, 0.017071269542683242 }
// 
// 
// 
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
