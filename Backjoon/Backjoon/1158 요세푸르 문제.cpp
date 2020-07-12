#include<iostream>
#include<vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> list;		// 원을 이루면서 앉아있는 사람들
	int personN, K;		// 사람의 수, 제거할 사람의 간격
	cin >> personN >> K;
	for (int i = 0; i < personN; i++) {		// 사람들이 원을 이루면서 앉는다.
		list.push_back(i + 1);
	}
	int index = 0;		// 제거할 사람의 인덱스
	cout << '<';
	while (!list.empty()) {
		index += K - 1;		// K만큼 건너뛴다.
		if (index > list.size() - 1) {		// 원을 이루면서 앉아있으므로 size를 넘어가면 나머지 연산으로 index계산
			index %= list.size();
		}
		cout << list[index];		// 제거하는 사람의 순서 출력
		if (list.size() != 1) {
			cout << ", ";
		}
		else {
			cout << '>' << endl;
		}
		list.erase(list.begin() + index);		// 제거
	}
}