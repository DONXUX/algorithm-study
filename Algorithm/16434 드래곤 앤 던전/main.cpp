#include <iostream>
using namespace std;

struct room { int t, a, h; };

int n, k;
room rooms[123456];

bool isClear(long long max) {
	long long cur = max, atk = k;
	for (int i = 0; i < n; i++) {
		switch (rooms[i].t) {
		case 1: 
			cur -= (rooms[i].h / atk) * rooms[i].a;
			if (rooms[i].h % atk == 0) cur += rooms[i].a;
			break;
		case 2:
			cur += rooms[i].h, atk += rooms[i].a;
			if (cur > max) cur = max;
			break;
		}

		if (cur <= 0) return false;
	}
	return true;
}

long long solve() {
	long long lo = 0, hi = 0x0fffffffffffffff;
	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		int ret = isClear(mid);
		if (ret) hi = mid;
		else lo = mid;
	}
	return hi;
}

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		room r;
		cin >> r.t >> r.a >> r.h;
		rooms[i] = r;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	cout << solve();

	return 0;
}