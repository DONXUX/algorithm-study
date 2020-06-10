#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;

string brackets;

void input() {
	cin >> brackets;
}

string solve() {
	stack<char> s;
	int i = 0;
	for (char c : brackets) {
		if (c == ')') {
			if (!s.empty() && c - 1 == s.top()) s.pop();
			else break;
		}
		else if (c == '}' || c == ']') {
			if (!s.empty() && c - 2 == s.top()) s.pop();
			else break;
		}
		else  s.push(c);
		i++;
	}
	if (i == brackets.size() && s.empty()) return "YES";
	else return "NO";
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		input();
		cout << solve() << endl;
	}

	return 0;
}