#include <iostream>
#include <queue>
using namespace std;

long long a, b;

int bfs(void) {
	queue<pair<long long, int>> q;
	q.push({ a, 1 });
	while (!q.empty()) {
		long long n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (n == b) return cnt;

		long long n2 = n * 2, n3 = (n * 10) + 1;
		if (n2 <= b) { q.push({ n2, cnt + 1 }); }
		if (n3 <= b) { q.push({ n3, cnt + 1 }); }
	}

	return -1;
}

int solve(void) {
	return bfs();
}

void input(void) {
	cin >> a >> b;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}