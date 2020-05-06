#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, pos;
int rating[2][100];

int solve() {
	pos = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		while ((rating[1][i] < rating[0][pos]) && (pos < n)) pos++;
		if (pos == n) break;
		pos++, cnt++;
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < 2; i++) 
			for (int j = 0; j < n; j++) 
				cin >> rating[i][j];
		sort(rating[0], rating[0] + n, greater<int>());
		sort(rating[1], rating[1] + n, greater<int>());
		cout << solve() << endl;
	}
	return 0;
}