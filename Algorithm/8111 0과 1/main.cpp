
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
#include <map>
#define FAIL "BARK"
#define MAX 20001

using namespace std;
//�ڷ� ���� ����
map<int, char> numByRemain;
bool visited[MAX];
int parents[MAX];
int n;

//Ž�� ����
void bfs() {
    queue<int> q;
    q.push(1);
    parents[1] = -1;
    visited[1] = true;
    numByRemain[1] = '1';
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        int newNums[2];
        //�ĺ� ����
        newNums[0] = (current * 10) % n;
        newNums[1] = (current * 10 + 1) % n;
        for (int i = 0; i < 2; i++) {
            int newNum = newNums[i];
            if (visited[newNum])
                continue;
            //�������� ���� ������ �� �󺧸�
            numByRemain[newNum] = i + '0';
            //�θ� ���� ����
            parents[newNum] = current;

            if (newNum == 0)
                return;


            visited[newNum] = true;
            q.push(newNum);
        }

    }
}
//����� ���� ���̿켱 Ž��
void print(int num) {
    if (num == -1) {
        return;
    }
    print(parents[num]);
    cout << numByRemain[num];
}


int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        memset(visited, false, sizeof(visited));
        bfs();
        print(0);
        cout << endl;
    }

    return 0;
}