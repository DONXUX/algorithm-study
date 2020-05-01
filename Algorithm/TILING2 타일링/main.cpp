#include <iostream>
#define endl '\n'
using namespace std;
constexpr int MOD = 1000000007;

int cache[101];

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	cache[1] = 1, cache[2] = 2;
	for (int i = 3; i < 101; i++) 
		cache[i] = (cache[i - 2] % MOD) + (cache[i - 1] % MOD);
	
	while (c--) {
		int n;
		cin >> n;
		cout << cache[n] % MOD << endl;
	}

	return 0;
}