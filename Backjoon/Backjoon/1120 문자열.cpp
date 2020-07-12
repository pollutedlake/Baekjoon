#include<iostream>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string a, b;		// 문자열 A, B
	cin >> a >> b;
	int min = 999999;		// A, B의 차이의 최솟값
	for (int i = 0; i <= b.size() - a.size(); i++) {
		int difference = 0;		// A, B의 차이
		for (int j = 0; j < a.size(); j++) {		// A[0]를 B[i]에 놓고 A[j]와 B[i + j]를 비교해서 다르다면 difference증가
			if (a.at(j) != b.at(i + j)) {
				difference++;
			}
		}
		if (min > difference) {		// 차이가 가장 최소일 때 구하기
			min = difference;
		}
	}
	cout << min << endl;
}