//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
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
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater than 199711L.
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
#define	CL(a, b)	memset(a, b, sizeof(a))
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

#if (0 or defined ONLINE_JUDGE)
	#define debug 
#else 
	#define debug(x)	cout << #x << " = " << x << "\n"
#endif

string concat(char s, char t) {
	string ret = "";
	ret += s;
	ret += t;
	return ret;
}

string solve(string s, string t) {
/*
	cout << endl;
	cout << s.size() << ": " << s << endl;
	cout << t.size() << ": " << t << endl;
	cout << endl;
*/
	assert(s.size() == t.size());
	int N = s.size();
	string ret = concat(s[N-1], t[N-1]);
	
//	debug(ret);
	rep(i, N-2, 0) {
		string orig_ret = ret;
		string tmp1 = concat(s[i], t[i]);

		string tmp = "";
		int M = ret.size()/2;
		string a = (tmp + s[i]) + ret.substr(0, M);
		string b = (tmp + t[i]) + ret.substr(M);
		string tmp2  = a + b;

		ret = max(ret, tmp1);
		ret = max(ret, tmp2);

//		debug(a);
//		debug(b);
//		Pf("i = %d, orig_ret = %s, tmp1 = %s, tmp2 = %s, ret = %s\n", i, orig_ret.c_str(), tmp1.c_str(), tmp2.c_str(), ret.c_str());

	}

	return ret;
}

string solve1(string s, string t) {
	return "";
}

int main()
{
	string s = "abcd";
	string t = "pqrs";
/*
	s = "abbabbabbababaaaabbababab";
	t = "bababbaabbbababbbbababaab";

	s = "abacaba";
	t = "zzzaaaa";

	s = "ddddddddddddddddddddddddddddddddddddddddddddddd";
	t = "ttttttttttttttttttttttttttttttttttttttttttttttt";
*/	

	s = "ededd";
	t = "edade";

	s = "abaababbcacbccbbaabaacabbcbbbcacbbcbbbaabcbbaba";

	t = "cacacccaacacccaacaccbbcbacbccbccabcbbbabbbcbbba";

	string r = solve(s, t);
	debug(s);
	debug(t);
	cout << endl;
	debug(r);
	cout << endl;

	string p = solve1(s, t);
	debug(p);
	return 0;
}

