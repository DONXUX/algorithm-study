#include <iostream>
#define endl '\n'
using namespace std;
constexpr int MOD = 10000000;
int n, cache[100][100];

int poly(int first, int cnt) {
	if (cnt == n) return 1;

	int& ret = cache[first][cnt];
	if (ret != -1) return cache[first][cnt];
	ret = 0;
	for (int next = 1; next + cnt <= n; next++) {
		int add = first + next - 1;
		ret += (add * poly(next, next + cnt)) % MOD;
		ret %= MOD;
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		int ret = 0;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				cache[i][j] = -1;

		for (int i = 1; i <= n; i++) 
			ret = (ret + poly(i, i)) % MOD;
		cout << ret << endl;
	}
	return 0;
}