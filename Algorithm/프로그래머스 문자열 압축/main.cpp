#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int solution(string s) {
	int answer = 99999999;
	vector<string> tokens;
	for (int len = 1; len <= s.size() / 2 + 1; len++) {
		tokens.clear();
		string tmp = "";
		// 토큰 생성
		for (int i = 0; i <= s.size(); i++) {
			if ((i != 0) && (i % len == 0)) 
				tokens.push_back(tmp), tmp = "";
			if(i < s.size()) tmp += s[i];
		}
		if (!tmp.empty()) tokens.push_back(tmp);

		string token = tokens[0], tmp_result = "";
		int overlap_cnt = 1;
		for (int i = 1; i < tokens.size(); i++) {
			if (tokens[i] == token) overlap_cnt++;
			else {
				if (overlap_cnt > 1) tmp_result += to_string(overlap_cnt);
				tmp_result += tokens[i - 1];
				overlap_cnt = 1;
				token = tokens[i];
			}
		}
		if (overlap_cnt > 1) tmp_result += to_string(overlap_cnt);
		tmp_result += tokens[tokens.size() - 1];
		answer = min(answer, (int)tmp_result.size());

	}
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	string s;
	cin >> s;
	cout << solution(s);

	return 0;
}