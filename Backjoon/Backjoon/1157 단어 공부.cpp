#include<iostream>
using namespace std;

int alphabet[26];		// �ܾ ���� ���ĺ��� ������ �����ϴ� �迭

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string word;		// �Է¹޴� �ܾ�
	cin >> word;
	for (int i = 0; i < word.length(); i++) {		// �ܾ ���� ���ĺ��� ������ ���ĺ����� �����Ѵ�.
		if (word.at(i) >= 97) {		// �ҹ��ڶ��
			alphabet[word.at(i) - 97]++;

		}
		else {		// �빮�ڶ��
			alphabet[word.at(i) - 65]++;
		}
	}
	int max = -1;		// ���� ���� ���� Ƚ��
	int maxIdx = -1;		// ���� ���� ���� ���ĺ�
	for (int i = 0; i < 26; i++) {		// ���� ���� ���� ���ĺ��� �˾ƺ���.
		if (alphabet[i] == 0) {		// �� ���ĺ��� ������ �ʾҴٸ� �ǳʶڴ�.
			continue;
		}
		if (max < alphabet[i]) {		// �ִ����� ��
			max = alphabet[i];
			maxIdx = i;
		}
		else if (max == alphabet[i]) {		// ���� Ƚ���� ���ٸ� maxIdx�� -1�� �ʱ�ȭ
			maxIdx = -1;
		}
	}
	if (maxIdx == -1) {		// maxIdx�� -1�̶�� '?'���
		cout << '?' << endl;
	}
	else {		// ���� ���� ���� ���ĺ� �빮�ڷ� ���
		cout << (char)(maxIdx + 65) << endl;
	}
}