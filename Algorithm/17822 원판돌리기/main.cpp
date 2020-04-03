#include <iostream>
#include <vector>
#define endl '\n';
using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

struct oper { int x, d, k; };

int n, m, t;
int map[50][50];
vector<oper> rotateOperation;

int sum(void) {
	int result = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			result += map[i][j];

	return result;
}

void del(void) {
	int tmp_map[50][50];
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			tmp_map[i][j] = map[i][j];
		
	bool b_exist_adj_num = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) continue;
			bool b_del = false;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = (j + dy[k]) % m;
				if (ny < 0) ny = m - 1;
				if (nx < n && nx >= 0 && (map[i][j] == map[nx][ny]) && map[nx][ny] != 0) {
					tmp_map[nx][ny] = 0;
					b_del = true;
					b_exist_adj_num = true;
				}
			}
			if (b_del) tmp_map[i][j] = 0;
		}
	}

	if (!b_exist_adj_num) {
		int sum_num = 0; double average = 0; int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sum_num += tmp_map[i][j];
				if (tmp_map[i][j] != 0) cnt++;
			}
		}
		average = (double)sum_num / (double)cnt;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tmp_map[i][j] == 0) continue;
				if (tmp_map[i][j] < average) tmp_map[i][j]++;
				else if(tmp_map[i][j] > average) tmp_map[i][j]--;
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			map[i][j] = tmp_map[i][j];
}

void move(int x, int d, int k) {
	int tmp_vector[50];
	if (d == 0) {
		for (int i = 0; i < m; i++)
			tmp_vector[(i + k) % m] = map[x][i];
	}
	else {
		for (int i = 0; i < m; i++)
			tmp_vector[(i + (m - k)) % m] = map[x][i];
	}
		
	for (int i = 0; i < m; i++) 
		map[x][i] = tmp_vector[i];
}

void rotate(int x, int d, int k) {
	int cnt = 1, i = x;
	do {
		move(i - 1, d, k);
		i = x * (++cnt);
	} while (i <= n);
}

int solve(void) {
	for (oper op : rotateOperation) {
		rotate(op.x, op.d, op.k);
		del();
	}
	return sum();
}

void input(void) {
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			cin >> map[i][j];
		
	for (int i = 0; i < t; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		rotateOperation.push_back({ x, d, k });
	}
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	cout << solve() << endl;
	return 0;
}