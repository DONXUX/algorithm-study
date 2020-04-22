#include <iostream>
using namespace std;

int k, n;
int lan[10000];

int solve() {
	long long lo = 0, hi = 4294967296;
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) 
			cnt += lan[i] / mid;

		if (cnt >= n) lo = mid;
		else hi = mid;
	}
	return lo;
}

void input() {
	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> lan[i];
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}