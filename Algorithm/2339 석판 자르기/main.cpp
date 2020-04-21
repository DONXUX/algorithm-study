#include <iostream>
#include <vector>
using namespace std;
constexpr bool COL = true;
constexpr bool ROW = false;

struct pos { int x, y; };

int n;
int map[20][20];

int cut(pos s, pos e, int d) {
	// ���� Check
	vector<pos> impurities, jewelry;
	for (int i = s.x; i <= e.x; i++) {
		for (int j = s.y; j <= e.y; j++) {
			if (map[i][j] == 1) impurities.push_back({ i, j });
			else if (map[i][j] == 2) jewelry.push_back({ i, j });
		}
	}

	// �Ҽ��� ������ �Ǵ����� ���̻� �ڸ� �� �ִ°� ���°� �Ǵ�
	if (impurities.size() == 0) {
		// �Ҽ����� ������ ���� �ϳ��� �����Ѵٸ� ��ġ ����
		if (jewelry.size() == 1) return 1;
		else return 0;
	}
	
	// �Ҽ����� ������ �Ҽ����� �������� �߶󺻴�
	int ret = 0;
	for (pos m : impurities) {
		if (d == COL) {
			// �ڸ��°� �������� ����
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
			// �ڸ��°� �������� ����
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