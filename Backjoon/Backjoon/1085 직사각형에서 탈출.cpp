#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int x, y, w, h;		// �Ѽ��� x, y��ǥ, ���簢���� ������ �� ������ ��ǥ
	cin >> x >> y >> w >> h;
	cout << min(min(min(x, y), w - x), h - y) << endl;		// �Ѽ��� ��ġ���� ���� ����� �������� �Ÿ� ���
}