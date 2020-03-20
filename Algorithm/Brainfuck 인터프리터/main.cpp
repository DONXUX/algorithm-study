#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

unsigned char memory[100001];
int stack[4097], loop[4097];
const int MAX = 50000000;
int m, c, i;
string sc, si;

// 점프 포인트를 생성합니다.
void setLoop() {
	int top = -1;
	for (int i = 0; i < c; i++) {
		if (sc[i] == '[') 
			stack[++top] = i;
		else if (sc[i] == ']') {
			stack[++top] = i;
			loop[stack[top]] = stack[top - 1];
			loop[stack[top - 1]] = i;
			top -= 2;
		}
	}
}

void input() {
	cin >> m >> c >> i;
	for (int a = 0; a < m; a++) memory[a] = 0;
	for (int a = 0; a < c; a++) loop[a] = 0;
	cin >> sc >> si;
}

string solve() {
	input();
	setLoop();
	bool flag = false;
	int cnt = 0, sp = 0, mp = 0, ip = 0, max_sp = 0;

	// 명령이 5천만번 이상 수행 된다면 무한루프로 간주합니다.
	for (cnt = 0; cnt < MAX; cnt++) {
		if (sp >= c) {
			flag = true;
			break;
		}

		switch (sc[sp]) {
		case '-': memory[mp] = (memory[mp] - 1 < 0 ? (int)pow(2, 8) : memory[mp]) - 1; break;
		case '+': memory[mp] = (memory[mp] + 1) % (int)pow(2, 8);  break;
		case '<': mp = (mp - 1 < 0 ? m : mp) - 1;  break;
		case '>': mp = (mp + 1) % m;  break;
		case '[': if (memory[mp] == 0) sp = loop[sp]; break;
		case ']': if (memory[mp] != 0) sp = loop[sp]; break;
		case ',': memory[mp] = ip >= i ? 255 : si[ip++]; break;
		}
		sp++;
		max_sp = max(max_sp, sp);
	}
	if(!flag) return "Loops " + to_string(loop[max_sp]) + " " + to_string(max_sp);
	else return "Terminates";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		cout << solve() << '\n';

	return 0;
}