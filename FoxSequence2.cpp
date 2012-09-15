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

#define	SZ(a)	int((a).size())

#define	all(c)	(c).begin(), (c).end()

#define	forab(i, a, b)	for(int i = a; i <= b; i++)

class FoxSequence
{
public:
	string isValid(vector <int> s)
	{
		string yes = "YES", no = "NO";
		bool  ac , bc , cc, dc , ec ;

		ac = bc = cc = dc = ec = false;

		int d, dd;

		d = s[1] - s[0];

		if(d <= 0 || SZ(s) < 5)	return no;

		cout << "#1\n";

		forab(i, 2, SZ(s) -1)
		{
			dd = s[i] - s[i-1];	

			if(!ac)
			{
				cout << "#2\n";
				if(dd < 0)
				{
					ac = true;
					d = dd;
				}
				else if( dd != d )	return no;
			}
			else if(!bc)
			{
				cout << "#3\n";
				if(dd == 0)
				{
					bc  = true;
					d  =  0;
				}
				else if(dd > 0)
				{
					bc = cc = true;
					d = dd;
				}
				else if(dd != d)	return no;
			}
			else if(!cc)
			{
				cout << "#4\n";
				if(dd < 0)	return no;
				if(dd > 0)
				{
					cc = true;
					d = dd;
				}
			}
			else if(!dc)
			{
				cout << "#5\n";
				if(dd < 0)
				{
					d = dd;
					dc = true;
					ec = true;
				}
				if(dd != d)	return no;
			}
			else
			{
				cout << "#6 ->" << s[i] << "-" << s[i-1] << " = "<< dd << " \n";

				if(dd != d || dd >= 0)	return no;
			}

		}

		if(!ac || !bc || !cc || !dc || !ec)	return no;

		return yes;
	}
};
