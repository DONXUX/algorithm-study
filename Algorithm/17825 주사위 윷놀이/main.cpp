#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct info { int cnt, score; };
struct piece { int route, pos; };

int board[4][20] = {
	{2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40},
	{10,13,16,19,25,30,35,40},
	{20,22,24,25,30,35,40},
	{30,28,27,26,25,30,35,40},
};
int dice[10];

void bfs() {
	vector<piece> tmp = { {0,0}, {0,0}, {0,0}, {0,0} };
	queue<pair<vector<piece>, info>> q;
	q.push({ tmp, {0, 0} });
	while (!q.empty()) {
		vector<piece> p = q.front().first;
		info in = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			vector<piece> np = p;
			np[i].pos[] += dice[in.cnt];
		}
	}

}

void solve() {
	
}

void input() {
	for (int i = 0; i < 10; i++)
		cin >> dice[i];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();

	return 0;
}