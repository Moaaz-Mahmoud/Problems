#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define NEWLINE cout << '\n'
#define loop(n) for(int i = 0; i < n; i++)
#define INF 1000000000 // One billion
 
#define EXTERNAL_FILES 0
#if EXTERNAL_FILES
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
 
#define EXTERNAL_OUT 0
#if EXTERNAL_OUT 
ofstream fout("output.txt");
#define cout fout
#endif
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
 
inline void freqSort(vi& A) {
	vi F(3e7 + 9);
	loop(A.size()) F[A[i]]++;
	int j = 0;
	for (int i = 0; i < F.size(); i++) {
		while (F[i]--) {
			A[j++] = i;
		}
	}
}
 
int priority(char c) {
	switch (c) {
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '^': return 3;
	default: return 0;
	}
}
 
string toPost(string in) {
	stack<char> s;
	string post;
	for (char c : in) {
		if (isalnum(c))
			post += c;
		else if (c == '(')
			s.push(c);
		else if (c == ')') {
			while (s.top() != '(') {
				post += s.top();
				s.pop();
			}
			s.pop();
		}
		else { //operator
			if (!s.empty())
				while (priority(s.top() >= priority(c))) {
					post += s.top();
					s.pop();
				}
			s.push(c);
		}
	}
	while (!s.empty()) {
		post += s.top();
		s.pop();
	}
	return post;
}
 
int main()
{
	IOS;
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		cout << toPost(s) << '\n';
	}
 
}
