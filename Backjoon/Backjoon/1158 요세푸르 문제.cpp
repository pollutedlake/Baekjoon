#include<iostream>
#include<vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> list;		// ���� �̷�鼭 �ɾ��ִ� �����
	int personN, K;		// ����� ��, ������ ����� ����
	cin >> personN >> K;
	for (int i = 0; i < personN; i++) {		// ������� ���� �̷�鼭 �ɴ´�.
		list.push_back(i + 1);
	}
	int index = 0;		// ������ ����� �ε���
	cout << '<';
	while (!list.empty()) {
		index += K - 1;		// K��ŭ �ǳʶڴ�.
		if (index > list.size() - 1) {		// ���� �̷�鼭 �ɾ������Ƿ� size�� �Ѿ�� ������ �������� index���
			index %= list.size();
		}
		cout << list[index];		// �����ϴ� ����� ���� ���
		if (list.size() != 1) {
			cout << ", ";
		}
		else {
			cout << '>' << endl;
		}
		list.erase(list.begin() + index);		// ����
	}
}