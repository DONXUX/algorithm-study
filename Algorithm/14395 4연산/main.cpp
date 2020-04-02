#include <iostream>
#include <string>
#include <queue>
#include <set>
#define endl '\n';
using namespace std;

char dr[] = { '*', '+', '-','/' };

int s, t;
set<int> visited;

long long calculation(long long n, char oper) {
	switch(oper) {
	case '*': return n * n;
	case '+': return n + n;
	case '-': return n - n;
	case '/': return n / n;
	}
}

string bfs(void) {
	queue<pair<int, string>> q;
	q.push({ s,"" });
	visited.insert(s);
	if (s == t) return "0";
	while (!q.empty()) {
		int n = q.front().first;
		string route = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			if (n == 0 && i == 3) continue;
			long long nn = calculation(n, dr[i]);
			if (visited.find(nn) != visited.end() || nn > t) continue;
			if (nn == t) return route + dr[i];
			visited.insert(nn);
			q.push({ nn, route + dr[i] });
		}
	}
	return "-1";
}

void input(void) {
	cin >> s >> t;
}

string solve(void) {
	return bfs();
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	cout << solve();

	return 0;
}