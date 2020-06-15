/*
���� : 1021 ȸ���ϴ� ť
�ۼ��� : �ڻ���
�ۼ��� :2020.06.15
*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> queue;		// ����� ��ȯ ť
	int queueSize;		// ť�� ũ��
	int selectN;		// ���� ���� ����
	int minCalc = 0;		// �ּ����� ���� Ƚ��
	cin >> queueSize >> selectN;
	for (int i = 1; i <= queueSize; i++) {		// ����� ��ȯ ť�� 1���� ť�� ũ����� �ִ´�.
		queue.push_back(i);
	}
	for (int i = 0; i < selectN; i++) {
		int select;		// ���� ����
		int at;		// ���� ���Ұ� �ִ� ��ġ
		bool right = true;		// ���������� �̵���ų�� bool ����
		cin >> select;
		while (queue.front() != select) {		// ť�� ù ��° ���Ұ� ���� ���Ұ� �ɶ����� �ݺ�
			for (int j = 0; j < queue.size(); j++) {		// ���� ���Ұ� �ִ� ��ġ �˾Ƴ���
				if (queue.at(j) == select) {
					at = j;
				}
			}
			if (at < queue.size() - at + 1) {		// ���� ���Ұ� ��� ������ �̵����Ѿ� ������ �˻��ϰ� �̵� ���� ����
				right = false;
			}
			if (right) {		// �������� �����ٸ� ���������� �̵�
				queue.insert(queue.begin(), queue.back());
				queue.pop_back();
			}
			else {		// ������ �����ٸ� �������� �̵�
				queue.push_back(queue.front());
				queue.erase(queue.begin());
			}
			minCalc++;		// ���� Ƚ�� ����
		}
		queue.erase(queue.begin());		// �̴´�.
	}
	cout << minCalc << endl;		// �ּ� ���� Ƚ�� ���
}