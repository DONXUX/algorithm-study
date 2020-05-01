#include <iostream>
#define endl '\n'
using namespace std;
constexpr int MOD = 1000000007;

int n;
int cache[100];

int tiling(int s) {
	if (s == n) return 1;
	if (s > n) return 0;
	int& ret = cache[s];
	if (ret != -1) return ret;

	return ret = ((tiling(s + 1) % MOD) + (tiling(s + 2) % MOD)) % MOD;
}

int asymmetric() {
	if (n % 2 == 1) return (tiling(0) - tiling(n / 2 + 1) + MOD) % MOD;
	int ret = tiling(0);
	ret = (ret - tiling(n / 2) + MOD) % MOD;
	ret = (ret - tiling(n / 2 + 1) + MOD) % MOD;
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < n; i++) 
			cache[i] = -1;
		cout << asymmetric() << endl;
	}

	return 0;
}