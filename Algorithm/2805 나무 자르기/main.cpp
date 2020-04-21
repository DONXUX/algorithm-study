#include <iostream>
using namespace std;

int n, m;
int height[1000000];

int solve() {
	int lo = 0, hi = 1000000000;

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++)
			if (height[i] > mid) sum += height[i] - mid;

		if (sum >= m) lo = mid;
		else hi = mid;
	}
	return lo;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> height[i];
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}