#include <iostream>
#include <algorithm>
using namespace std;
 
int n, m;
int money[10000];

int solve() {
    int lo = 0, hi = m;

    int money_max = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += money[i];
        money_max = max(money_max, money[i]);
    }
    if (sum <= m) return money_max;

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (money[i] > mid) sum += mid;
            else sum += money[i];
        }
        if (sum <= m) lo = mid;
        else hi = mid;
    }

    return lo;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> money[i];
    cin >> m;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout << solve();

    return 0;
}