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
#include <functional>	// Don't know why it is here.
#include <numeric>		// +1
#include <cassert>
#include <utility>		// +1
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;

const long long mod = 1e9 + 7;

long long getN(long long cnt) {
	if(cnt == 1)
		return 2;
	else if(cnt == 0)
		return 1;
	else {
		long long tmp = cnt/2;
		long long res1 = getN(tmp);
		long long t = (res1*res1) % mod;
		if(cnt % 2 == 1)
			t = (t*2)%mod;
		return t;
	}
}
 
int main()
{
	int N;
	long long tmp = 333333336ll;
	N = 1000000;
	N--;
	cout << "N = " << N << "\n";

	long long res = 0;
	N -= 2;
	if(N % 2 == 0) {
		long long t = N/2+1;
		res = getN(t*2);
		res = ((((res-1+mod)%mod * 2)%mod*tmp)%mod+1)%mod;
	}
	else {
		long long t = (N+1)/2;
		res = getN(t*2);
		res = (res-1+mod)% mod;
		res = (res*tmp)%mod;;
		res = (res+1)%mod;
	}
	cout << res;


	return 0;
}

