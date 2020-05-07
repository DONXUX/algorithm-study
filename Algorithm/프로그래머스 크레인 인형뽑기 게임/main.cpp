#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> bucket;

	for (int move : moves) {
		int top = 0;

		while ((top < board[0].size()) && (board[top][move - 1] == 0))
			top++;

		if (top == board[0].size()) continue;
		if ((!bucket.empty()) && (bucket.back() == board[top][move - 1])) 
			answer += 2, bucket.pop_back();
		else bucket.push_back(board[top][move - 1]);
		board[top][move - 1] = 0;
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int n, m, tmp;
	cin >> n >> m;
	vector<vector<int>> board(n);
	vector<int> moves(m);

	for (int i = 0; i < n; i++) {
		board[i].resize(n);
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}
	for (int i = 0; i < m; i++)
		cin >> moves[i];

	cout << solution(board, moves);
	return 0;
}