#include <bits/stdc++.h>
using namespace std;

class PairGame
{
public:
	int maxSum(int a, int b, int c, int d);
};

void update(int m, int n, map <pair<int, int> , int> &cnt) {
    while(m != n) {
        cnt[make_pair(m, n)]++;
        if(n > m)
            n-=m;
        else
            m-=n;
    }
    cnt[make_pair(m, n)]++;
}

int PairGame::maxSum (int a, int b, int c, int d)
{
	int ret = -1;
    map <pair <int, int>, int> cnt;
    cnt.clear();
    update(a, b, cnt);
    update(c, d, cnt);
    for(auto it = (cnt).begin(); it != (cnt).end(); ++it) {
        if(it->second == 2) {
            ret = max(ret, it->first.first+ it->first.second);
        }
        //printf("(%d, %d): %d\n", it->first.first, it->first.second, it->second);
    }
	return ret;
}

<%:testing-code%
>
