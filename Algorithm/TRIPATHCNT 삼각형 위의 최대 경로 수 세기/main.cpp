#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, path[100][100], path2[100][100], countCache[100][100];

int count(int x, int y) {
	int& ret = countCache[x][y];
	if (ret != -1) return countCache[x][y];
	if (x + 1 >= n)
		return ret = 1;

	ret = 0;
	if (path2[x + 1][y] >= path2[x + 1][y + 1])
		ret += count(x + 1, y);
	if (path2[x + 1][y] <= path2[x + 1][y + 1])
		ret += count(x + 1, y + 1);
	return ret;
}

int maxPath(int x, int y) {
	if (x >= n) return 0;
	int& ret = path2[x][y];
	if (ret != -1) return ret;

	return ret = max(maxPath(x + 1, y), maxPath(x + 1, y + 1)) + path[x][y];
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> path[i][j];
				path2[i][j] = -1;
				countCache[i][j] = -1;
			}
		}
		maxPath(0, 0);
		cout << count(0, 0) << endl;
	}

	return 0;
}