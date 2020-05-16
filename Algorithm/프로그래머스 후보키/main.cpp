#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
vector<string> combination;
int column = 0;

//string ���Լ� ���̷� ���� �������ϰ� ������ ū������� �����Ѵ�
bool compare(string& a, string& b) {
    if (a.length() != b.length())     return a.length() < b.length();
    return a < b;
}

//��� ������ ����� �Լ�
void Combination(int k = 0, string temp = "") {
    for (int i = k; i < column; i++) {
        temp += to_string(i);
        combination.push_back(temp);
        Combination(i + 1, temp);
        temp = temp.substr(0, temp.length() - 1);
    }
}

//���տ����� �ĺ�Ű �Ǵ� �Լ�
bool subset(vector<vector<string>>& relation, string com) {
    map<string, int> candidateCheck;
    for (int i = 0; i < relation.size(); i++) {
        //�ĺ�Ű ���տ� ���� string ��ħ
        string temp = "";
        for (int k = 0; k < com.length(); k++) {
            int number = com[k] - '0';
            temp += relation[i][number] + " ";
        }
        //�ڿ� �� ���� ����(���ص� ������)
        temp = temp.substr(0, temp.length() - 1);
        //���� �̹� �־��ٸ� �ĺ�Ű�� �ɼ����ٰ� ��ȯ
        if (candidateCheck[temp])    return false;
        //map�� ��ģ string���� �߰�
        candidateCheck[temp]++;
    }
    //������ �ߺ��� �����ٸ� �ּҼ��� ���ϼ��� �������״�. true ����
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    //Į�� ���� �߰�
    column = relation[0].size();
    //������ ���ռ� ��������
    Combination();
    //������ ���ռ� �����ϱ�(���� ���պ��� �ϱ�����)-> �̰� ���ؼ� �ѵ��� �����
    sort(combination.begin(), combination.end(), compare);
    //���ռ���ŭ �ݺ�
    for (int i = 0; i < combination.size(); i++) {
        //�ĺ�Ű���
        if (subset(relation, combination[i])) {
            //�ĺ�Ű�� �ӽú����� �ִ´�.
            string temp = combination[i];
            //�ĺ�Ű�� �� ��ġ�� ������ �� ���ش�. 13�����̸� 1�� 3�̵����� ���ã�Ƽ� ����
            for (int j = combination.size() - 1; j >= i; j--) {
                bool check = true;
                for (auto t : temp) {
                    if (combination[j].find(t) == string::npos) {
                        check = false;
                        break;
                    }
                }
                //�ϳ��� �������� �н��� ���� ���ǹ�
                if (check)    combination.erase(combination.begin() + j);
            }
            //���Ÿ� �����Ƿ� i�� �����ϰ� �ĺ�Ű�����Ƿ� answer����
            i--;    answer++;
        }
    }
    return answer;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<string>> relation(n);
	for (int i = 0; i < n; i++) {
		relation[i].resize(m);
		for (int j = 0; j < m; j++) 
			cin >> relation[i][j];
	}
	cout << solution(relation);

	return 0;
}