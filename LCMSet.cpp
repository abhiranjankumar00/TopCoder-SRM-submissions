#include <bits/stdc++.h>
using namespace std;

class LCMSet
{
public:
	string equal(vector <int> A, vector <int> B);
};

map <int, int> factorize(long long  N) {
    map <int, int> ret;
    ret.clear();
    for(long long p = 2; p*p <= N; p++) {
        while(N%p == 0) {
            ret[p]++;
            N/=p;
        }
    }
    if(N != 1)
        ret[N]++;
    return ret;
}

int lcm(int a, int b) {
    return a/__gcd(a, b)*b;
}
vector <int> solve(vector <int> &x) {
    vector <int> ret;
    sort(x.begin(), x.end());
    ret.push_back(x[0]);

    for(int i = (int)1; i < (int)x.size(); ++i) {
        int last = 1;
        for(int j = 0; j < (int)ret.size(); ++j) {
            if(x[i] % ret[j] == 0) {
                last = lcm(last, ret[j]);
            }
        }

        if(last != x[i])
            ret.push_back(x[i]);
    }
    return ret;
}

string LCMSet::equal (vector <int> A, vector <int> B)
{
    vector <int> ra = solve(A);
    vector <int> rb = solve(B);

    if(ra.size() != rb.size())
        return "Not equal";

    for(int i = 0; i < (int)ra.size(); ++i) {
        if(ra[i] != rb[i])
            return "Not equal";
    }

    return "Equal";
    int n = A.size(), m = B.size();
    vector <map <int, int> > a(n), b(m);
    for(int i = 0; i < (int)n; ++i) {
        a[i] = factorize(A[i]);
    }
    for(int i = 0; i < (int)m; ++i) {
        b[i] = factorize(B[i]);
    }

    for(int i = 0; i < (int)n; ++i) {
        const map <int, int> &mp = a[i];
        for(auto it = (mp).begin(); it != (mp).end(); ++it) {

            bool solve = false;

            for(int j = 0; j < (int)m; ++j) {
                if(A[i] % B[j] == 0 && it->second == b[j][it->first])
                    solve = true;
            }
            if(!solve)
                return "Not equal";
        }
    }

    for(int i = 0; i < (int)m; ++i) {
        const map <int, int> &mp = b[i];
        for(auto it = (mp).begin(); it != (mp).end(); ++it) {

            bool solve = false;

            for(int j = 0; j < (int)n; ++j) {
                if(B[i] % A[j] == 0 && it->second == a[j][it->first])
                    solve = true;
            }
            if(!solve)
                return "Not equal";
        }
    }

    return "Equal";
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	LCMSet *obj;
	string answer;
	obj = new LCMSet();
	clock_t startTime = clock();
	answer = obj->equal(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	vector <int> p0;
	vector <int> p1;
	string p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {2,3,4,12};
	p1 = {2,3,4,6};
	p2 = "Equal";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {4,9};
	p1 = {6,36};
	p2 = "Not equal";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {2,3,5,7,14,105};
	p1 = {2,3,5,6,7,30,35};
	p2 = "Equal";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {2,3,5,7,14,105};
	p1 = {2,3,5,6,7,30,36};
	p2 = "Not equal";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	p1 = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	p2 = "Equal";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {999999999,1953125,512,1000000000};
	p1 = {999999999,1953125,512};
	p2 = "Equal";
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 6 -----
	disabled = false;
	p0 = {999999998,999999999,1000000000};
	p1 = {999999999,1000000000};
	p2 = "Not equal";
	all_right = (disabled || KawigiEdit_RunTest(6, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 7 -----
	disabled = false;
	p0 = {40,25 };
	p1 = {200,5 };
	p2 = "Not equal";
	all_right = (disabled || KawigiEdit_RunTest(7, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// For any non-empty sequence of positive integers s1, s2, ..., sK their least common multiple is the smallest positive integer that is divisible by each of the given numbers.
// We will use "lcm" to denote the least common multiple.
// For example, lcm(3) = 3, lcm(4,6) = 12, and lcm(2,5,7) = 70.
// 
// 
// Given a sequence S, we now define the set LCM(S) as follows:
// LCM(S) = { lcm(s1, s2, ..., sk) | s1, s2, ..., sk belong to S, k > 0}.
// In words: LCM(S) is the set of all values that can be obtained by selecting some elements of S and computing their least common multiple.
// For example, for S={2,3,4} we have LCM(S)={2,3,4,6,12}.
// 
// 
// You are given two vector <int>s A and B.
// Return "Equal" if LCM(A) = LCM(B), and "Not equal" otherwise.
// 
// DEFINITION
// Class:LCMSet
// Method:equal
// Parameters:vector <int>, vector <int>
// Returns:string
// Method signature:string equal(vector <int> A, vector <int> B)
// 
// 
// CONSTRAINTS
// -A will contain between 1 and 50 elements, inclusive.
// -B will contain between 1 and 50 elements, inclusive.
// -Each element in A will be between 2 and 1,000,000,000, inclusive.
// -Each element in B will be between 2 and 1,000,000,000, inclusive.
// -Elements in A will be distinct.
// -Elements in B will be distinct.
// 
// 
// EXAMPLES
// 
// 0)
// {2,3,4,12}
// {2,3,4,6}
// 
// Returns: "Equal"
// 
// LCM(A) = LCM(B) = {2,3,4,6,12}
// 
// 1)
// {4,9}
// {6,36}
// 
// Returns: "Not equal"
// 
// LCM(A) = {4,9,36}, LCM(B) = {6,36}
// 
// 2)
// {2,3,5,7,14,105}
// {2,3,5,6,7,30,35}
// 
// Returns: "Equal"
// 
// 
// 
// 3)
// {2,3,5,7,14,105}
// {2,3,5,6,7,30,36}
// 
// Returns: "Not equal"
// 
// 
// 
// 4)
// {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}
// {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}
// 
// Returns: "Equal"
// 
// Note that some of the numbers in the sets LCM(A) and LCM(B) can be huge.
// In this case, the largest number in LCM(A) is 2305567963945518424753102147331756070.
// 
// 5)
// {999999999,1953125,512,1000000000}
// {999999999,1953125,512}
// 
// Returns: "Equal"
// 
// 
// 
// 6)
// {999999998,999999999,1000000000}
// {999999999,1000000000}
// 
// Returns: "Not equal"
// 
// 
// 
// END KAWIGIEDIT TESTING
