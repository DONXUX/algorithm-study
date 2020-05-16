#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace	std;
constexpr int INF = 99999999;

int n, k, m, l, ap[12], open[10]; 
int cache[10][1 << 12];

int bitCount(int x) {
	if (x == 0) return 0;
	return x % 2 + bitCount(x / 2);
}


int graduate(int semester, int taken) {
	if (bitCount(taken) >= k) return 0;
	if (semester >= m) return INF;

	int& ret = cache[semester][taken];
	if (ret != -1)return ret;
	ret = INF;

	int canTake = (open[semester] & ~taken);
	for (int i = 0; i < n; i++) {
		if (!(canTake & (1 << i))) continue;
		if ((taken & ap[i]) != ap[i]) canTake &= ~(1 << i);
	}

	for (int take = canTake; take; take = ((take - 1) & canTake)) {
		if (bitCount(take) > l) continue;
		ret = min(ret, 1 + graduate(semester + 1, taken | take));
	}
	ret = min(ret, graduate(semester + 1, taken));
	return ret;
}

int input() {
	memset(open, 0, sizeof(open));
	memset(ap, 0, sizeof(ap));
	memset(cache, -1, sizeof(cache));
	
	cin >> n >> k >> m >> l;
	for (int i = 0; i < n; i++) {
		int r, tmp;
		cin >> r;
		for (int j = 0; j < r; j++) {
			cin >> tmp;
			ap[i] |= (1 << tmp);
		}

	}
	for (int i = 0; i < m; i++) {
		int c, tmp;
		cin >> c;
		for (int j = 0; j < c; j++) {
			cin >> tmp;
			open[i] |= (1 << tmp);
		}
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		input();
		int result = graduate(0, 0);
		if (result >= INF) cout << "IMPOSSIBLE" << endl;
		else cout << result << endl;
	}

	return 0;
}