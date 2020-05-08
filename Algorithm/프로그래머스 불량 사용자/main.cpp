#include <string>
#include <vector>
#include<iostream>
#include<set>
#include<algorithm>
#define SIZE 10
using namespace std;

bool visited[SIZE];
set<string> _set;

bool compare(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    else {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == '*') continue;
            else if (s1[i] != s2[i]) return false;
        }
    }
    return true;
}

void dfs(const vector<string>& user_id, const vector<string>& banned_id, int b_idx) {
    int u_size = user_id.size(), b_size = banned_id.size();
    
    // ±âÀú »ç·Ê
    if (b_idx == b_size) {
        string s = "";
        for (int i = 0; i < u_size; i++) {
            if (visited[i])
                s += i;
        }
        _set.insert(s);
        return;
    }

    for (int i = 0; i < u_size; i++) {
        if (!compare(banned_id[b_idx], user_id[i]) || visited[i]) continue;
        
        visited[i] = true;
        dfs(user_id, banned_id, b_idx + 1);
        visited[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    dfs(user_id, banned_id, 0);
    answer = _set.size();
    return answer;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> user_id, banned_id;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        user_id.push_back(s);
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        banned_id.push_back(s);
    }

    cout << solution(user_id, banned_id);

	return 0;
}