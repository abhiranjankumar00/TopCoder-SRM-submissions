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
typedef vector< vector <int> > vvi;
typedef pair<int,int> ii;
typedef string ST;
typedef stringstream SS;

#define Pf	printf
#define	Sf	scanf

#define	ep	1e-9
#define	PI	3.141592653589793
#define	E	2.718281828459045

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

#define Max 1000000

bool pr[Max];

void PreProcess()
{
	CL(pr, -1);
	pr[0] = pr[1]  = false;

	for(int i = 2; i*i <= Max; i++)	if(pr[i])
		for(int j = i+i; j<Max; j+= i)
			pr[j] = false;
}

bool cc (const vi & a, const vi &b ) {
	return a[0]*a[1]*a[2] < b[0]*b[1]*b[2];
}

class PrimeAnagrams
{
public:
	vector <int> primes(string anagram)
	{
		PreProcess();

		vector <int> ret;
		vvi tmp;
		sort(all(anagram));
		bool f = true;

		while(f || next_permutation(all(anagram)))
		{
			f = false;
			forn(i, anagram.length()-1)	forab(j, i+1, anagram.length()-1)
			{
				ST aa = anagram.substr(0, i+1),
				   bb = anagram.substr(i+1, j-i),
				   cc = anagram.substr(j+1);
				
				if(aa.length() == 0 || bb.length() == 0 || cc.length() == 0 || aa[0] == '0' || bb[0] == '0' || cc[0] == '0')	continue;

				int a = atoi(aa.c_str());
				int b = atoi(bb.c_str());
				int c = atoi(cc.c_str());

				if(pr[a] && pr[b] && pr[c])
				{
					vi t(3);
					t[0] = a, t[1] = b, t[2] = c;
					tmp.pb(t);
				}
			}
		}

		sort(all(tmp), cc);
/*
		tr(it, tmp)
			Pf("%d %d %d\n", (*it)[0], (*it)[1], (*it)[2]);
*/
		if(SZ(tmp) > 0)
		{
			sort(all(tmp[0]));
			return tmp[0];
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
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	PrimeAnagrams *obj;
	vector <int> answer;
	obj = new PrimeAnagrams();
	clock_t startTime = clock();
	answer = obj->primes(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p1[i];
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
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
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
	
	string p0;
	vector <int> p1;
	
	{
	// ----- test 0 -----
	p0 = "39151";
	int t1[] = {5,13,19};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "921179";
	int t1[] = {2,17,199};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "01123";
	int t1[] = {2,3,101};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "0707070";
	p1.clear() /*{}*/;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "222";
	int t1[] = {2,2,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "123";
	p1.clear() /*{}*/;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
// You will be given a string of digits that supposedly come from three prime numbers.
// The digits will be given in a random order.
// Your task is to find the three prime numbers, if they exist.
// If there are three such primes, return them sorted least to greatest.
// If there is more than one possible set of three primes, return the set with the smallest product.
// If there is no such set, return { }.
// 
// 
// 
// For example, the five digits of the primes 5, 13, and 19 could be given to you as "39151".
// There are several other sets of prime numbers that could also be rearranged to give this input,
// for example { 5, 31, 19 } and { 3, 11, 59 }.
// The set with the smallest product is { 5, 13, 19 },
// so those are the three primes your method should return.
// 
// 
// 
// Each digit of each prime will be present in the input.  For example, if the input contains exactly two occurrences of the digit "1" (as in the example above), you must use the digit "1" exactly twice.
// 
// 
// 
// Any zeros in the input may not be used as leading zeros in any of the three primes.
// 
// 
// 
// DEFINITION
// Class:PrimeAnagrams
// Method:primes
// Parameters:string
// Returns:vector <int>
// Method signature:vector <int> primes(string anagram)
// 
// 
// NOTES
// -If you find two sets of primes with the same product, you have made a startling discovery!
// 
// 
// CONSTRAINTS
// -anagram will contain between 3 and 8 characters, inclusive.
// -Each character of anagram will be a digit.
// 
// 
// EXAMPLES
// 
// 0)
// "39151"
// 
// Returns: { 5,  13,  19 }
// 
// This is the example from the problem statement.
// 
// 1)
// "921179"
// 
// Returns: { 2,  17,  199 }
// 
// 2)
// "01123"
// 
// Returns: { 2,  3,  101 }
// 
// The input may have a leading zero, but the primes may not.  {2, 3, 011} is not a valid answer.
// 
// 3)
// "0707070"
// 
// Returns: { }
// 
// 4)
// "222"
// 
// Returns: { 2,  2,  2 }
// 
// 5)
// "123"
// 
// Returns: { }
// 
// 1 is not prime.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
