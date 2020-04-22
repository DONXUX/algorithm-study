#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int pos[200000];

int solve() {
	sort(pos, pos + n);
	int lo = 0, hi = 1000000000;
	
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2, start = pos[0], cnt = 1;
		for (int i = 0; i < n; i++) 
			if (pos[i] - start > mid) start = pos[i], cnt++;

		if (cnt >= c) lo = mid;
		else hi = mid;
	}
	return hi;
}

void input() {
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> pos[i];
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}