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

class ShoutterDiv1
{
public:
	int count(vector <string> s1000, vector <string> s100, vector <string> s10, vector <string> s1, vector <string> t1000, vector <string> t100, vector <string> t10, vector <string> t1);
};

bool G[55][55], vis[55];
int N;
int dist[55][55];
const int oo = 1e7;

bool in(int s1, int t1, int s2, int t2) {
	return s1 >= s2 && t1 <= t2;
}
bool cross(int s1, int t1, int s2, int t2) {
	return (s1 <= s2 && t1 >= s2) || (s1 <= t2 && t1 >= t2);
}

bool overlap(int s1, int t1, int s2, int t2) {
	return in(s1, t1, s2, t2) || in(s2, t2, s1, t1) || cross(s1, t1, s2, t2) || cross(s2, t2, s1, t1);
}

void dfs(int u) {
	if(vis[u])
		return;
	vis[u] = true;
	for(int i = 0; i < N; i++) {
		if(G[u][i])
			dfs(i);
	}
}

int ShoutterDiv1::count (vector <string> _s1000, vector <string> _s100, vector <string> _s10, vector <string> _s1, vector <string> _t1000, vector <string> _t100, vector <string> _t10, vector <string> _t1) 
{
	string s1000 = "", s100 = "", s10 = "", s1 = "";
	string t1000 = "", t100 = "", t10 = "", t1 = "";
	for(__typeof((_s1000).begin()) it = (_s1000).begin(); it != (_s1000).end(); it++) 
		s1000 += *it;
	for(__typeof((_s1000).begin()) it = (_s100).begin(); it != (_s100).end(); it++) 
		s100 += *it;
	for(__typeof((_s1000).begin()) it = (_s10).begin(); it != (_s10).end(); it++) 
		s10 += *it;
	for(__typeof((_s1000).begin()) it = (_s1).begin(); it != (_s1).end(); it++) 
		s1 += *it;

	for(__typeof((_s1000).begin()) it = (_t1000).begin(); it != (_t1000).end(); it++) 
		t1000 += *it;
	for(__typeof((_s1000).begin()) it = (_t100).begin(); it != (_t100).end(); it++) 
		t100 += *it;
	for(__typeof((_s1000).begin()) it = (_t10).begin(); it != (_t10).end(); it++) 
		t10 += *it;
	for(__typeof((_s1000).begin()) it = (_t1).begin(); it != (_t1).end(); it++) 
		t1 += *it;
/*
	cout << "s1000 = " << s1000 << "\n"; 
	cout << "s100  = " << s100 << "\n"; 
	cout << "s10   = " << s10 << "\n"; 
	cout << "s1    = " << s1 << "\n"; 
	cout << "\n";

	cout << "t1000 = " << t1000 << "\n"; 
	cout << "t100  = " << t100 << "\n"; 
	cout << "t10   = " << t10 << "\n"; 
	cout << "t1    = " << t1 << "\n"; 
	cout << "\n";
*/
	N = s1.size();
	vector <int>  enter(s1.size(), 0);
	vector <int> exit (s1.size(), 0);

	memset(vis, 0, sizeof(vis));
	memset(G, 0, sizeof(G));
	for(int i = 0; i < 55; i++) {
		for(int j = 0; j < 55; j++) {
			dist[i][j] = oo;
		}
		dist[i][i] = 0;
	}

	for(int i = 0; i < N; i++) {
		enter[i] = (s1000[i] - '0')*1000 + (s100[i] - '0')*100 + (s10[i] - '0')*10 + (s1[i] - '0');
		exit[i] = (t1000[i] - '0')*1000 + (t100[i] - '0')*100 + (t10[i] - '0')*10 + (t1[i] - '0');
	}

	for(int i = 0; i < N; i++) {
		printf("%d: [%d - %d] \n", i, enter[i], exit[i]);
	}
	cout << "\n";

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(overlap(enter[i], exit[i], enter[j], exit[j])) {
				G[i][j] = true;
			}
		}
	}

	cout << "N = " << N << "\n"; 
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(i != j && G[i][j])
				dist[i][j] = dist[j][i] = 1;
			cout << (G[i][j] ? 1 : 0) << " ";
		}
		cout << endl;
	}


	for(int k = 0; k < N; k++) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%2d ", dist[i][j]);
		}
		cout << "\n";
	}

	dfs(0);
	for(int i = 0; i < N; i++) {
		if(vis[i] == false) {
			return -1;
		}
	}
	int ret = 0;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) if(i != j){
			ret += dist[i][j] -1;
		}
	}
	
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, vector <string> p2, vector <string> p3, vector <string> p4, vector <string> p5, vector <string> p6, vector <string> p7, bool hasAnswer, int p8) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p2[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p3[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p4.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p4[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p5.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p5[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p6.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p6[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p7.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p7[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	ShoutterDiv1 *obj;
	int answer;
	obj = new ShoutterDiv1();
	clock_t startTime = clock();
	answer = obj->count(p0, p1, p2, p3, p4, p5, p6, p7);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p8 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p8;
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
	vector <string> p1;
	vector <string> p2;
	vector <string> p3;
	vector <string> p4;
	vector <string> p5;
	vector <string> p6;
	vector <string> p7;
	int p8;
	
	{
	// ----- test 0 -----
	string t0[] = {"22","2"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"00","0"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"11","1"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"21","4"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"22","2"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	string t5[] = {"00","0"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	string t6[] = {"11","1"};
			p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
	string t7[] = {"43","6"};
			p7.assign(t7, t7 + sizeof(t7) / sizeof(t7[0]));
	p8 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"00"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"00"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"00"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"13"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"00"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	string t5[] = {"00"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	string t6[] = {"00"};
			p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
	string t7[] = {"24"};
			p7.assign(t7, t7 + sizeof(t7) / sizeof(t7[0]));
	p8 = -1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"0000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0000"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"0000"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"1234"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"0000"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	string t5[] = {"0000"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	string t6[] = {"0000"};
			p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
	string t7[] = {"2345"};
			p7.assign(t7, t7 + sizeof(t7) / sizeof(t7[0]));
	p8 = 6;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"0000000000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0000000000"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"0000000000"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"7626463146"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"0000000000"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	string t5[] = {"0000000000"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	string t6[] = {"0000000000"};
			p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
	string t7[] = {"9927686479"};
			p7.assign(t7, t7 + sizeof(t7) / sizeof(t7[0]));
	p8 = 18;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
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
// A group of freshman rabbits has recently joined the Eel club.
// No two of the rabbits knew each other.
// Yesterday, each of the rabbits went to the club for the first time.
// For each i, rabbit number i entered the club at the time s[i] and left the club at the time t[i].
// 
// 
// Each pair of rabbits that was in the club at the same time got to know each other, and they became friends on the social network service Shoutter.
// This is also the case for rabbits who just met for a single moment (i.e., one of them entered the club exactly at the time when the other one was leaving).
// 
// 
// In Shoutter, each user can post a short message at any time.
// The message can be read by the user's friends.
// The friends can also repost the message, making it visible to their friends that are not friends with the original poster.
// In turn, those friends can then repost the message again, and so on.
// Each message can be reposted in this way arbitrarily many times. 
// If a rabbit wants to repost multiple messages, he must repost each of them separately.
// 
// 
// Today, each of the rabbits posted a self-introduction to Shoutter.
// Each rabbit would now like to read the self-introductions of all other rabbits (including those that are currently not his friends).
// Compute and return the minimal number of reposts necessary to reach this goal.
// If it is impossible to reach the goal, return -1 instead.
// 
// 
// As the number of rabbits can be greater than what the TopCoder arena supports, you are given the times s[i] and t[i] encoded in the following form:
// You are given vector <string>s s1000, s100, s10, and s1.
// Concatenate all elements of s1000 to obtain a string S1000.
// In the same way obtain the strings S100, S10, and S1.
// Character i of each of these strings corresponds to the rabbit number i.
// More precisely, these characters are the digits of s[i]:
// we obtain s[i] by converting the string S1000[i]+S100[i]+S10[i]+S1[i] to an integer.
// For example, if S1000[4]='0', S100[4]='1', S10[4]='4', and S1[4]='7', then s[4]=to_integer("0147")=147.
// You are also given vector <string>s t1000, t100, t10, and t1.
// These encode the times t[i] in the same way.
// 
// 
// DEFINITION
// Class:ShoutterDiv1
// Method:count
// Parameters:vector <string>, vector <string>, vector <string>, vector <string>, vector <string>, vector <string>, vector <string>, vector <string>
// Returns:int
// Method signature:int count(vector <string> s1000, vector <string> s100, vector <string> s10, vector <string> s1, vector <string> t1000, vector <string> t100, vector <string> t10, vector <string> t1)
// 
// 
// CONSTRAINTS
// -s1000, s100, s10, s1, t1000, t100, t10 and t1 will each contain between 1 and 50 elements, inclusive.
// -s1000, s100, s10, s1, t1000, t100, t10 and t1 will contain the same number of elements.
// -Each element of s1000, s100, s10, s1, t1000, t100, t10 and t1 will contain between 1 and 50 characters, inclusive.
// -For each i, the i-th elements of all input variables will all contain the same number of characters.
// -Each character in the input variables will be a digit ('0'-'9').
// -For each i, t[i] will be greater than or equal to s[i].
// 
// 
// EXAMPLES
// 
// 0)
// {"22", "2"}
// {"00", "0"}
// {"11", "1"}
// {"21", "4"}
// {"22", "2"}
// {"00", "0"}
// {"11", "1"}
// {"43", "6"}
// 
// Returns: 2
// 
// After parsing the input, you will get the following information: Rabbit 0 will enter the room at 2012 and leave the room at 2014. Rabbit 1 will enter the room at 2011 and leave the room at 2013. Rabbit 2 will enter the room at 2014 and leave the room at 2016. Therefore, Rabbit 0 and Rabbit 1 will be friends, and Rabbit 0 and Rabbit 2 will be friends too, but Rabbit 1 and Rabbit 2 won't be friends.
// 
// 
// Rabbit 0 can already see the self-introductions of all rabbits, but rabbits 1 and 2 cannot see each other's self-introduction.
// Two actions are needed: First, Rabbit 0 reposts the self-introduction of Rabbit 1, and then Rabbit 0 reposts the self-introduction of Rabbit 2.
// Now everybody can read everything.
// 
// 1)
// {"00"}
// {"00"}
// {"00"}
// {"13"}
// {"00"}
// {"00"}
// {"00"}
// {"24"}
// 
// Returns: -1
// 
// If it is impossible to achieve the goal, return -1.
// 
// 2)
// {"0000"}
// {"0000"}
// {"0000"}
// {"1234"}
// {"0000"}
// {"0000"}
// {"0000"}
// {"2345"}
// 
// Returns: 6
// 
// The following pairs will be friends: Rabbit 0 and 1, 1 and 2, and 2 and 3. One of the optimal strategies is as follows:
// 
// Rabbit 1 shares introductions of Rabbit 0 and 2.
// Rabbit 2 shares introductions of Rabbit 1 and 3.
// Rabbit 1 shares introduction of Rabbit 3 (this is possible because now Rabbit 3's introduction is shared by Rabbit 2, who is a Rabbit 1's friend).
// Rabbit 2 shares introduction of Rabbit 0 (this is possible because now Rabbit 0's introduction is shared by Rabbit 1, who is a Rabbit 2's friend).
// 
// 
// 3)
// {"0000000000"}
// {"0000000000"}
// {"0000000000"}
// {"7626463146"}
// {"0000000000"}
// {"0000000000"}
// {"0000000000"}
// {"9927686479"}
// 
// Returns: 18
// 
// 
// 
// 4)
// {"00000000000000000000000000000000000000000000000000"}
// {"00000000000000000000000000000000000000000000000000"}
// {"50353624751857130208544645495168271486083954769538"}
// {"85748487990028258641117783760944852941545064635928"}
// {"00000000000000000000000000000000000000000000000000"}
// {"00000000000000000000000000000000000000000000000000"}
// {"61465744851859252308555855596388482696094965779649"}
// {"37620749792666153778227385275518278477865684777411"}
// 
// Returns: 333
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
