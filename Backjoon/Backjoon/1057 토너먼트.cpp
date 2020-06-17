#include<iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, kjm, ihs;		// �������� ��, �����ΰ� ���Ѽ��� 1���忡 �޴� ��ȣ
	cin >> n >> kjm >> ihs;
	int round = 1;		// �����ΰ� ���Ѽ��� ������ ���� ��
	while ((kjm + 1) / 2 != (ihs + 1) / 2) {		// �����ΰ� ���Ѽ��� ���� ������
		if (n == 1) {		// ���� �������� ���� 1�� �ɶ����� �ݺ��ȴٸ� ������ �ʴ´�.
			cout << -1 << endl;
			return 0;
		}
		kjm = (kjm + 1) / 2;		// �������� ���� ���忡 ���� ��ȣ
		ihs = (ihs + 1) / 2;		// ���Ѽ��� ���� ���忡 ���� ��ȣ
		if (n % 2 == 0) {		// �������� ���� ¦�� �� �� ���� ���忡 ������ ��
			n /= 2;
		}
		else {		// �������� ���� Ȧ �� �� �� �������忡 ������ ��
			n = n / 2 + 1;
		}
		round++;
	}
	cout << round << endl;
}