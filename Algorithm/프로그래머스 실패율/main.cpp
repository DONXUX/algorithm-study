#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer(N), challenger(N + 1, 0), all(N + 1, 0);
	vector<double> failed(N + 1, 0);

	sort(stages.begin(), stages.end());

	for (int i = 0; i < stages.size(); i++) {
		if (stages[i] > N) break;
		challenger[stages[i]]++;
	}
	int cnt = 0;
	for (int stage = 1; stage <= N; stage++) {
		for (; cnt < stages.size(); cnt++) {
			if (stage <= stages[cnt]) {
				all[stage] = stages.size() - cnt;
				break;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (all[i] == 0) break;
		failed[i] = (double)challenger[i] / all[i];
	}

	for (int i = 0; i < N; i++) {
		double ret = -1;
		int idx = 0;
		for (int j = 1; j <= N; j++) {
			if (ret < failed[j]) {
				ret = failed[j];
				idx = j;
			}
		}
		failed[idx] = -1;
		answer[i] = idx;
	}
	
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int N, m;
	cin >> N >> m;
	vector<int> stages(m), result;
	for (int i = 0; i < m; i++) 
		cin >> stages[i];
	
	result = solution(N, stages);
	for (int r : result) 
		cout << r << " ";
	
	return 0;
}