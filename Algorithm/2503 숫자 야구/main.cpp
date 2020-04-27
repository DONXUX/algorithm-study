#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[100][5]; 
int question[1000][3];

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = 0; j < 3; j++) {
			arr[i][j] = a % 10;
			a /= 10;
		}
		arr[i][3] = b, arr[i][4] = c;
	}

	for (int i = 111; i < 999; i++) {
		for (int j = 0; j < 3; j++) {
			question[i][j] = i % 10;
			a /= 10;
		}
	}

	do {
		bool answer = true;
		for (int i = 0; i < n; i++) {
			int s = 0, b = 0;
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (question[j] == arr[i][k]) {
						if (j == k) s++;
						else b++;
					}
				}
			}
			if (s != arr[i][3] || b != arr[i][4]) {
				answer = false;
				break;
			}
		}
		if (answer) cnt++;
	} while (next_permutation(question, question + 3));


	cout << cnt;
	return 0;
}