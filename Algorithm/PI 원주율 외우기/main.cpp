#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define endl '\n'
using namespace std;
constexpr int INF = 999999999;

string n;
int cache[10002];

int classify(int a, int b) {
	string m = n.substr(a, b - a + 1);

	// 문자열 모두 같은지 확인
	if (m == string(m.size(), m[0])) return 1;

	// 등차수열인지 검사
	bool progressive = true;
	for (int i = 0; i < m.size() - 1; i++) 
		if (m[i + 1] - m[i] != m[1] - m[0]) progressive = false;

	// 등차수열이면 공차가 -1 or 1 인지 검사
	if (progressive && abs(m[1] - m[0]) == 1)
		return 2;

	// 두 수가 번갈아 등장하는지 확인
	bool alternating = true;
	for (int i = 0; i < m.size(); i++)
		if (m[i] != m[i % 2])
			alternating = false;

	if (alternating) return 4;
	if (progressive) return 5;
	return 10;
}

int minDifficulty(int begin) {
	if (begin == n.size()) return 0;
	int& ret = cache[begin];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 3; i <= 5; i++) 
		if (n.size() >= begin + i) 
			ret = min(ret, minDifficulty(begin + i) + classify(begin, begin + i - 1));
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < 10002; i++)
			cache[i] = -1;
		cout << minDifficulty(0) << endl;
	}

	return 0;
}