#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 10000 + 1;

vector<int> edge[MAX];

// 그래프 생성
void MakeGraph() {
	int floor = 1;
	edge[1].push_back(2);
	edge[1].push_back(3);
	int cnt = 0;
	for (int i = 2; i < MAX; i++) {
		if (floor < cnt) {
			floor++;
			cnt = 0;
		}

		if (cnt == 0) {
			edge[i].push_back(i - floor);
			edge[i].push_back(i + 1);
			edge[i].push_back(i + 1 + floor);
			edge[i].push_back(i + 1 + floor + 1);
		}
		else if (floor == cnt) {
			edge[i].push_back(i - floor - 1);
			edge[i].push_back(i - 1);
			edge[i].push_back(i + floor + 1);
			edge[i].push_back(i + floor + 2);
		}
		else {
			edge[i].push_back(i - floor - 1);
			edge[i].push_back(i - floor);
			edge[i].push_back(i - 1);
			edge[i].push_back(i + 1);
			edge[i].push_back(i + floor + 1);
			edge[i].push_back(i + floor + 2);
		}
		cnt++;
	}
}

// BFS로 경로 탐색
int Solve(int a, int b) {
	queue<pair<int, int>> q;
	bool visited[MAX];
	memset(visited, false, MAX);
	
	q.push({ a, 0 });
	visited[a] = true;
	while (!q.empty()) {
		int n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (n == b) 
			return cnt;

		for (int i = 0; i < edge[n].size(); i++) {
			int next = edge[n][i];
			if (next >= MAX || visited[next]) continue;
			visited[next] = true;
			q.push({ next, cnt + 1 });
		}
	}

	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	MakeGraph();
	for (int tc = 0; tc < t; tc++) {
		int a, b;
		cin >> a >> b;
		cout << "#" << tc + 1 << " " << Solve(a, b) << "\n";
	}

	return 0;
}