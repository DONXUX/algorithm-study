#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<string> str;
int cache[101][101];
string W, S;

// w : W ������ġ, s : S ���� ��ġ
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
	// �� ���ڿ� �� �ϳ��� ���� �ų�, ��Ī�� �ȵǰų�, *�� ���� ��� break
	while (pos < w.size() && pos < s.size() && (w[pos] == s[pos] || w[pos]=='?')) 
		pos++;
	
	// w�� s�� ��� �����ٸ� true, �ƴϸ� ��Ī�� �ȉ����� false
	if (pos >= w.size()) return pos == s.size();
	
	// *�� ������ w�� * ���� ���ڿ��� s pos ���� ���ڿ� �ϳ��ϳ� ���� ��Ī �õ�
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