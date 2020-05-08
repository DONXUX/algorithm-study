#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool visited[100001];

bool compare(const vector<int>& a, const vector<int>& b) {
	return a.size() < b.size();
}

vector<int> solution(string s) {
	vector<int> answer;
	vector<vector<int>> number;
	string num = "";
	vector<int> tmp;
	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			num += s[i];
		else if (s[i] == ',') {
			tmp.push_back(stoi(num));
			num = "";
		}
		else if (s[i] == '}') {
			tmp.push_back(stoi(num));
			number.push_back(tmp);
			tmp.clear();
			num = "";
			i++;
		}
	}

	sort(number.begin(), number.end(), compare);
	for (vector<int> v : number) {
		for (int n : v) {
			if (visited[n]) continue;
			visited[n] = true;
			answer.push_back(n);
			break;
		}
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	string s;
	cin >> s;
	vector<int> answer = solution(s);

	return 0;
}