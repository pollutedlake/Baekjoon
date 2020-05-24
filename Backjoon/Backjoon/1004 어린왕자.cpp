/*
파일 : 1004 어린왕자
작성자 : 박상현
작성일 : 2020.05.25
*/
#include <iostream>
#include<math.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;		// 테스트 케이스 개수
	double startX, startY;		// 출발점의 x, y좌표
	double arrX, arrY;		// 도착점의 x, y좌표
	int SysNum;		// 행성계의 개수
	double x, y, r;		// 행성계의 중심 x, y좌표와 반지름
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int result = 0;		// 행성계 진입/이탈 횟수
		cin >> startX >> startY >> arrX >> arrY >> SysNum;
		for (int j = 0; j < SysNum; j++) {
			cin >> x >> y >> r;
			// 출발점과 도착점이 모두 입력받은 행성계 안에 있거나 밖에 있다면 행성계에 진입/이탈하지 않는다. 그러나 하나만 안에 있고 하나는 밖에 있다면 행성계에 진입/이탈 한 번 하므로 횟수를 증가시킨다.
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