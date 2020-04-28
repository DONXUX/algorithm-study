#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, board[100][100];
int cache[100][100];

int pathSum(int x, int y) {
	if (x >= n) return 0;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	return ret = board[x][y] + max(pathSum(x + 1, y), pathSum(x + 1, y + 1));
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> board[i][j];
				cache[i][j] = -1;
			}
		}
		cout << pathSum(0, 0) << endl;
	}

	return 0;
}