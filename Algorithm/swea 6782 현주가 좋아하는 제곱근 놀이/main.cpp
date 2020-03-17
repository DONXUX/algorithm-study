#include <iostream>
#include <cmath>
using namespace std;

int solve(long long n) {
	int cnt = 0;
	while (n != 2) {
		// 제곱근이 정수라면 제곱근을 취한다.
		if ((int)sqrt(n) == sqrt(n)) {
			n = sqrt(n);
			cnt += 1;
		}
		// 제곱근이 정수가 아니라면 다음 제곱 수 까지 1을 더하다가 만나면 제곱근을 취한다.
		else {
			long long next_squ = (long long)(sqrt(n) + 1);
			cnt += (next_squ * next_squ) - n + 1;
			n = next_squ;
		}
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		long long n;
		cin >> n;
		cout << "#" << tc + 1 << " " << solve(n) << "\n";
	}

	return 0;
}