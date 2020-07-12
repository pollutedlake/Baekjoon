#include<iostream>
#include<algorithm>
using namespace std;

int square[50][50];		// ���簢�� �迭

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;		// ���簢���� ��� �� ũ��
	cin >> N >> M;
	string s;		// �� ���� ���ڵ�
	for (int i = 0; i < N; i++) {		// ���簢�� �Է� �ޱ�
		cin >> s;
		for (int j = 0; j < M; j++) {
			square[i][j] = int(s.at(j));
		}
	}
	for (int i = min(N, M) - 1; i > 0; i--) {		// ���� �� �ִ� ���簢���� �ִ� ���̰� min(N, M)�̴�.
		for (int j = 0; j < N - i; j++) {
			for (int k = 0; k < M - i; k++) {
				if ((square[j][k] == square[j][k + i]) && (square[j][k] == square[j + i][k]) && (square[j][k] == square[j + i][k + i])) { // �� �������� ���� ���� ���簢���� ã���� �� ���簢���� �ִ� ũ���̴�.
					cout << (i + 1) * (i + 1) << endl;
					return 0;
				}
			}
		}
	}
	cout << 1 << endl;
}