//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

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
#define DEBUG(x)	cout << #x << " = " << x << "\n"
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
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

const int sz = 50;
const int mod = 1e5;

char G[sz][sz+1];
int power[sz];

int main()
{
	srand(19090);
	assert(sz >= 1 && sz <= 50);

	forn(i, sz)
		forn(j, sz)
			G[i][j] = 'N';

	forn(i, sz)
		power[i] = rand() % mod + 1;

	forn(i, sz) {
		if(i > 0)
			Pf(", ");
		write(power[i]);
		assert(power[i] >= 1 && power[i] <= mod);
	}
	cout << endl << endl;

	forn(i, 25) {
		forab(j, i+1, i+25)
			G[i][j] = G[j][i] = 'Y';
	}
	forn(i, sz)
		assert(strlen(G[i]) == sz);

	forn(i, sz) {
		forn(j, sz) {
			if(i == j)
				assert(G[i][j] == 'N');
			assert(G[i][j] == G[j][i]);
		}
	}
	forn(i, sz) {
		if(i > 0)
			cout << ", ";
		cout << G[i]  ;
	}


	return 0;
}

