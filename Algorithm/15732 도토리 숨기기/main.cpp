#include <iostream>
using namespace std;

struct rlue { int a, b, c; };

int n, k, d;
rlue r[10000];

long long getAcorns(long long x) {
	long long cnt = 0;
	for (int i = 0; i < k; i++) {
		if (x >= r[i].a) {
			if (x < r[i].b) cnt += ((x - r[i].a) / r[i].c) + 1;
			else cnt += ((r[i].b - r[i].a) / r[i].c) + 1;
		}
	}
	return cnt;
}

int solve() {
	long long lo = 0, hi = n;
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		long long ret = getAcorns(mid);
		if (ret >= d) hi = mid;
		else lo = mid;
	}
	return hi;
}

void input() {
	cin >> n >> k >> d;
	for (int i = 0; i < k; i++)
		cin >> r[i].a >> r[i].b >> r[i].c;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}