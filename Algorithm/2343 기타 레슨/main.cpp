#include <iostream>
using namespace std;
int n, m;
int music[100000];

int solve() {
	int lo = 0, hi = 1000000000;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2, sum = 0, cnt = 1;
		bool possible = true;
		for (int i = 0; i < n; i++) {
			if (music[i] > mid) { possible = false; break; }
			if (sum + music[i] > mid) cnt++, sum = 0;
			sum += music[i];
		}
		if (!possible || cnt > m) lo = mid;
		else hi = mid;
	}
	return hi;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> music[i];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}