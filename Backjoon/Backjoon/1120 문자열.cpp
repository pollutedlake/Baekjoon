#include<iostream>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string a, b;		// ���ڿ� A, B
	cin >> a >> b;
	int min = 999999;		// A, B�� ������ �ּڰ�
	for (int i = 0; i <= b.size() - a.size(); i++) {
		int difference = 0;		// A, B�� ����
		for (int j = 0; j < a.size(); j++) {		// A[0]�� B[i]�� ���� A[j]�� B[i + j]�� ���ؼ� �ٸ��ٸ� difference����
			if (a.at(j) != b.at(i + j)) {
				difference++;
			}
		}
		if (min > difference) {		// ���̰� ���� �ּ��� �� ���ϱ�
			min = difference;
		}
	}
	cout << min << endl;
}