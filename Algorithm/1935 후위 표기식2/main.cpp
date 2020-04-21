#include <iostream>
#include <stack>
using namespace std;

string str;
int n;
double alpha[26];
stack<double> s;

double solve() {
	for (char c : str) {
		if (c >= 'A' && c <= 'Z')
			s.push(alpha[c - 'A']);
		else {
			double p2 = s.top(); s.pop();
			double p1 = s.top(); s.pop();
			if (c == '+') s.push(p1 + p2);
			if (c == '-') s.push(p1 - p2);
			if (c == '*') s.push(p1 * p2);
			if (c == '/') s.push(p1 / p2);
		}
	}
	return s.top();
}

void input() {
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++)
		cin >> alpha[i];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	cout << fixed;
	cout.precision(2);
	cout << solve();

	return 0;
}