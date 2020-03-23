#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int map[1000][1000];
int n, m;
int maxSquare;

void input() {
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++)
			map[i][j] = s[j] - '0';
	}
}

int solve() {	
	input();
	for (int i = 0; i < n; i++)
		maxSquare = max(maxSquare, map[i][0]);
	for (int j = 0; j < n; j++)
		maxSquare = max(maxSquare, map[0][j]);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (map[i][j] != 0) {
				map[i][j] = min(min(map[i - 1][j], map[i][j - 1]), map[i - 1][j - 1]) + 1;
				maxSquare = max(maxSquare, map[i][j]);
			}
		}
	}
	return maxSquare;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << pow(solve(), 2);
	
	return 0;
}