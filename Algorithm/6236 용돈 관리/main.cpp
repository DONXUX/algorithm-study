#include <iostream>
using namespace std;

int n, m;
int day[100000];

int solve() {
	int lo = 0, hi = 10000 * n;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int sum = 0, cnt = 1;
		bool possible = true;
		for (int i = 0; i < n; i++) {
			if (day[i] > mid) { possible = false; break; }
			if (day[i] + sum > mid) sum = 0, cnt++;
			sum += day[i];
		}

		if (!possible || cnt > m) lo = mid;
		else hi = mid;
	}
	return hi;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> day[i];
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}