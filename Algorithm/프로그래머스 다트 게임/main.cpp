#include <iostream>
#include <vector>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	vector<int> score;
	for (int i = 0; i < dartResult.size(); i++) {
		if (dartResult[i] == 'S') continue;
		else if (dartResult[i] == 'D') score.back() = score.back() * score.back();
		else if (dartResult[i] == 'T') score.back() = score.back() * score.back() * score.back();
		else if (dartResult[i] == '*') {
			score.back() *= 2;
			if (score.size() > 1) score[score.size() - 2] *= 2;
		}
		else if (dartResult[i] == '#') score.back() *= -1;
		else {
			if (dartResult[i] == '1' && dartResult[i + 1] == '0') score.push_back(10), i++;
			else score.push_back(dartResult[i] - '0');
		}
	}
	for (int s : score) 
		answer += s;
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	string s;
	cin >> s;
	cout << solution(s);

	return 0;
}