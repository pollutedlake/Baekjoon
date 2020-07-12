#include<iostream>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;		// �׽�Ʈ ���̽�
	cin >> testCase;
	while (testCase--) {
		string spread;		// ���ĸ� ǥ���ϴ� ���ڿ�
		cin >> spread;
		bool pattern = true;		// ���İ� ������ ���������� ���� bool ����
		int i, j;		// �ݺ� �ε���
		for (i = 0; i < spread.size(); i++) {		// ���ڿ��� ũ�⸸ŭ �ݺ�
			if (spread.at(i) == '0') {		// i��° ���ڰ� 0�̸�
				if (i == spread.size() - 1) {		// i�� ������ ���ڶ��
					pattern = false;		// NO [ex) 010, 0, ...]
					break;
				}
				if (spread.at(i + 1) != '1') {		// 0 ���� ���ڰ� 1�� �ƴ϶��
					if (i >= 2) {
						if (spread.at(i - 1) == '1' && spread.at(i - 2) == '1') {		// i-1��°�� i-2��°�� 1�̶�� [ex)10011001]
							i -= 2;	// �ٷ� �� ��ġ���� �˻�
							continue;
						}
					}
					pattern = false;		// i�� 2���� �۴ٸ� NO [ex) 00]
					break;
				}
				i = i + 1;		// 01������ �м��Ǹ� �ٴ�����ġ���� �˻�
			}
			else {		// i��° ���ڰ� 1�̶��
				if (4 > spread.size() - i) {		// i��° ��ġ���� 1001�� �� �ڸ��� ���ٸ� NO [ex) 1, 10, 100, 11, ...]
					pattern = false;
					break;
				}
				if (spread.at(i + 1) != '0' || spread.at(i + 2) != '0') {		// ������ġ�� �ٴ��� ��ġ�� 0�̾ƴ϶�� NO [ex) 1111, 1011, 1101, ...]
					pattern = false;
					break;
				}
				for (j = i + 3; j < spread.size(); j++) {		// i ���� ����° ��ġ���� 0�̾ƴ� ��ġ ã�� j�� ����
					if (spread.at(j) != '0') {
						break;
					}
					if (j == spread.size() - 1) {	// ������ 0�� ��� NO [ex) 1000, 10000, ...]
						pattern = false;
						break;
					}
				}
				if (j == spread.size() - 1) {		// j�� ������ ��ġ��� YES [ex) ...1001, ...10001, ...]
					break;
				}
				for (j = j + 1; j < spread.size(); j++) {		// 1�� �ƴ� ���ڰ� ���ö����� �˻�
					if (spread.at(j) != '1') {
						break;
					}
				}
				i = j - 1;		// 1�� �ƴ� ���ڰ� ���� ��ġ���� �ٽ� �˻�
			}
		}
		if (pattern) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}