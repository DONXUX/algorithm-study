#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;

string solve() {
	string str;
	cin >> str;
	stack<int> s;
	for (char c : str) {
		switch (c) {
		case '(': s.push(0);  break;
		case ')': if (s.empty()) return "NO";  s.pop();
		}
	}
	if (s.empty()) return "YES";
	else return "NO";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) 
		cout << solve() << endl;
	

	return 0;
}