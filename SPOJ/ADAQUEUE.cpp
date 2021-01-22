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
using namespace std;
 
#define NEWLINE cout << '\n'
#define loop(n) for(int i = 0; i < n; i++)
#define INF 1000000000 // One billion
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
 
#define T 0
#if T
#include <fstream>
#define cout fout
ofstream fout("a.txt");
#endif
 
deque<int> q;
bool reversed = false;
void back() {
	if (q.empty()) {
		cout << "No job for Ada?\n";
		return;
	}
	if (!reversed) {
		cout << q.back() << '\n';
		q.pop_back();
	}
	else {
		cout << q.front() << '\n';
		q.pop_front();
	}
}
void front() {
	if (q.empty()) {
		cout << "No job for Ada?\n";
		return;
	}
	if (!reversed) {
		cout << q.front() << '\n';
		q.pop_front();
	}
	else {
		cout << q.back() << '\n';
		q.pop_back();
	}
}
void reverse() {
	reversed = !reversed;
}
void toFront(ll n) {
#define _ 1
#if _
	if (!reversed) {
#endif
		q.push_front(n);
#if _
	}
	else {
		q.push_back(n);
	}
#endif
}
void push_back(ll n) {
#if _
	if (!reversed) {
#endif
		q.push_back(n);
#if _
	}
	else {
		q.push_front(n);
	}
#endif
}
 
 
int main()
{
	std::cin.tie(0);
	std::cin.sync_with_stdio(0);
 
	ll t; cin >> t;
	string command;
	while (t--) {
 
		cin >> command;
		if (command == "back") {
			back();
		}
		else if (command == "front") {
			front();
		}
		else if (command == "reverse") {
			reverse();
		}
		else if (command == "push_back") {
			ll n; cin >> n;
			push_back(n);
		}
		else if (command == "toFront") {
			ll n; cin >> n;
			toFront(n);
		}
	}
#if T
	fout.close();
	system("a.txt");
#endif
}
