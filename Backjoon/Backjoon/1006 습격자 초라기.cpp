/*
파일 : 1005 ACM Craft
작성자 : 박상현
작성일 :2020.06.01
*/
#include <iostream>]
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;
	int areaN, platoon;
	vector<int> enemy;
	int result = 99999;
	cin >> testCase;
	while (testCase--) {
		int result = 0;
		cin >> areaN >> platoon;
		for (int i = 0; i < areaN * 2; i++) {
			int temp;
			cin >> temp;
			enemy.push_back(temp);
		}
		for (int i = 0; i < areaN; i++) {
			if (enemy[i] + enemy[i - 1] <= platoon) {

			}
			else {

			}
		}
	}
}