#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<string> str;
int cache[101][101];
string W, S;

// w : W 시작위치, s : S 시작 위치
bool matchMemoized(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1) 
		return ret;

	while (w < W.size() && s < S.size() && (W[w] == S[s] || W[w] == '?'))
		return ret = matchMemoized(w + 1, s + 1);

	if (w == W.size()) return ret = (s == S.size());

	if (W[w] == '*') {
		if (matchMemoized(w + 1, s) || (s < S.size() && matchMemoized(w, s + 1)))
			return ret = 1;
	}

	return ret = 0;
}

bool match(const string &w, const string &s) {
	int pos = 0;
	// 두 문자열 중 하나라도 끝날 거나, 매칭이 안되거나, *을 만날 경우 break
	while (pos < w.size() && pos < s.size() && (w[pos] == s[pos] || w[pos]=='?')) 
		pos++;
	
	// w과 s가 모두 끝났다면 true, 아니면 매칭이 안됬으니 false
	if (pos >= w.size()) return pos == s.size();
	
	// *을 만나면 w는 * 다음 문자열과 s pos 다음 문자열 하나하나 살펴 매칭 시도
	if (w[pos] == '*') {
		for (int skip = pos; skip <= s.size(); skip++) {
			if (match(w.substr(pos + 1), s.substr(skip)))
				return true;
		}
	}

	return false;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		cin >> W;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			str.push_back(s);
		}

		sort(str.begin(), str.end());

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 101; j++)
				for (int k = 0; k < 101; k++)
					cache[j][k] = -1;
			S = str[i];
			if (matchMemoized(0, 0))
				cout << S << endl;
		}
		str.clear();
	}

	return 0;
}