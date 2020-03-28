#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int n;

string solve(void) {
	if (n == 1) return "1";
	queue<int> q;
	vector<pair<int, int>> chk(20000, { -1, -1 });
	q.push(1); chk[1] = { 1, -1 };

	while (!q.empty()) {
		int num = q.front(); q.pop();
		
		int newNum[2] = { (num * 10) % n, (num * 10 + 1) % n };
		for (int i = 0; i < 2; i++) 
			if (chk[newNum[i]].first == -1) chk[newNum[i]] = { i, num }, q.push(newNum[i]);
		if (!newNum[0] || !newNum[1]) break;
	}

	stack<int> s;
	for (int i = 0; i != -1; i = chk[i].second)
		s.push(chk[i].first);
	string str;
	if ((int)s.size() > 100) str = "BRAK";
	else while (s.size()) 
		str.push_back(s.top() + '0'), s.pop();
	return str;
}

void input(void) {
	cin >> n;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		input();
		cout << solve() << '\n';
	}

	return 0;
}