#include <iostream>
#include <vector>
using namespace std;
constexpr bool COL = true;
constexpr bool ROW = false;

struct pos { int x, y; };

int n;
int map[20][20];

int cut(pos s, pos e, int d) {
	// 보드 Check
	vector<pos> impurities, jewelry;
	for (int i = s.x; i <= e.x; i++) {
		for (int j = s.y; j <= e.y; j++) {
			if (map[i][j] == 1) impurities.push_back({ i, j });
			else if (map[i][j] == 2) jewelry.push_back({ i, j });
		}
	}

	// 불순문 여부의 판단으로 더이상 자를 수 있는가 없는가 판단
	if (impurities.size() == 0) {
		// 불순물이 없으나 보석 하나가 존재한다면 고가치 석판
		if (jewelry.size() == 1) return 1;
		else return 0;
	}
	
	// 불순물이 있으면 불순물을 기준으로 잘라본다
	int ret = 0;
	for (pos m : impurities) {
		if (d == COL) {
			// 자르는게 가능한지 여부
			bool impossibleCut = true;
			for (int i = s.y; i <= e.y; i++) {
				if (map[m.x][i] == 2) {
					impossibleCut = false;
					break;
				}
			}
			if (impossibleCut) ret += cut(s, { m.x - 1, e.y }, !d) * cut({ m.x + 1, s.y }, e, !d);
		}
		else {
			// 자르는게 가능한지 여부
			bool impossibleCut = true;
			for (int i = s.x; i <= e.x; i++) {
				if (map[i][m.y] == 2) {
					impossibleCut = false;
					break;
				}
			}
			if (impossibleCut) ret += cut(s, { e.x, m.y - 1 }, !d) * cut({ s.x, m.y + 1 }, e, !d);
		}
	}

	return ret;
}


int solve() {
	return cut({ 0, 0 }, { n - 1, n - 1 }, COL) + cut({ 0, 0 }, { n - 1, n - 1 }, ROW);
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> map[i][j];
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL);
	input();
	int ans = solve();
	if (ans == 0) ans = -1;
	cout << ans;

	return 0;
}