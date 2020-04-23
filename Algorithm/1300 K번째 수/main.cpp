#include <iostream>
#include <algorithm>
using namespace std;

long long n, k;

long long getPrevCnt(long long x) {
	long long sum = 0;
	for (int i = 1; i <= n; i++) 
		sum += min(x / i, n);
	return sum;
}

long long solve() {
	long long lo = 0, hi = n * n;
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		long long cnt = getPrevCnt(mid);
		
		if (cnt > k) hi = mid;
		else lo = mid;
	}
	return hi;
}

void input() {
	cin >> n >> k;
	k--;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	input();
	cout << solve() << " ";

	return 0;
}