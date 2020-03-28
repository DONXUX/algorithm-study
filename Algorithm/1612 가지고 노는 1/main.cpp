#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, one = 0, cnt = 1;
    cin >> n;
    if (!(n % 2) || !(n % 5)) cnt = -1;
    while(cnt != -1) {
        one = (one * 10 + 1) % n;
        if (!one) break;
        cnt++;
    }
    cout << cnt;
    return 0;
}