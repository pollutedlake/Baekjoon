/*
���� : 1004 �����
�ۼ��� : �ڻ���
�ۼ��� : 2020.05.25
*/
#include <iostream>
#include<math.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;		// �׽�Ʈ ���̽� ����
	double startX, startY;		// ������� x, y��ǥ
	double arrX, arrY;		// �������� x, y��ǥ
	int SysNum;		// �༺���� ����
	double x, y, r;		// �༺���� �߽� x, y��ǥ�� ������
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int result = 0;		// �༺�� ����/��Ż Ƚ��
		cin >> startX >> startY >> arrX >> arrY >> SysNum;
		for (int j = 0; j < SysNum; j++) {
			cin >> x >> y >> r;
			// ������� �������� ��� �Է¹��� �༺�� �ȿ� �ְų� �ۿ� �ִٸ� �༺�迡 ����/��Ż���� �ʴ´�. �׷��� �ϳ��� �ȿ� �ְ� �ϳ��� �ۿ� �ִٸ� �༺�迡 ����/��Ż �� �� �ϹǷ� Ƚ���� ������Ų��.
			if (sqrt(pow(startX - x, 2) + pow(startY - y, 2)) < r) {	
				if (sqrt(pow(arrX - x, 2) + pow(arrY - y, 2)) < r) {
					continue;
				}
				else {
					result++;
				}
			}
			else {
				if (sqrt(pow(arrX - x, 2) + pow(arrY - y, 2)) < r) {
					result++;
				}
				else {
					continue;
				}
			}
		}
		cout << result << endl;
	}
}