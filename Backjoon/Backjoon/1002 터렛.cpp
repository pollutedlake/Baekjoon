/*
파일 : 1002 터렛.cpp
작성자 : 박상현
작성일 : 2020.05.22
*/
#include <iostream>
#include<math.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testCase, x1, x2, y1, y2, r1, r2;	// 테스트 케이스의 개수, x1, y1, r1, x2, y2, r2
	double dist;	// 두 터렛사이의 거리
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));		// 두 터렛사이의 거리 계산
		if (dist == 0 && r1 == r2) {	// 두 터렛의 위치가 같고 각각 목표와의 거리도 같은 경우 목표가 존재할 수 있는 위치의 개수는 무한대이다.(두 원이 동일하다.)
			cout << -1 << endl;
			continue;
		}
		if (dist == 0 && r1 != r2) {	// 두 터렛의 위치가 같으나 각각 목표와의 거리가 다르면 목표가 존재할 수 없다.(두 원이 만나지 않는다.)
			cout << 0 << endl;
			continue;
		}
		if (dist < abs(r1 - r2)) {	// 두 터렛의 위치가 다르고 각각 목표화의 거리의 차이가 두 터렛사이의 거리보다 크다면 존재할 수 없다.(한 원이 다른 원을 접점없이 포함하는 형태)
			cout << 0 << endl;
			continue;
		}
		if (dist == abs(r1 - r2)) {	// 두 터렛의 위치가 다르고 각각 목표와의 거리의 차이가 두 터렛사이의 거리와 같다면 한 지점에서만 존재한다.(한 원이 다른 원을 내접하고 있는 형태) 
			cout << 1 << endl;
			continue;
		}
		if (r1 + r2 < dist) {	// 두 터렛의 위치가 다르고 각각 목표와의 거리의 합이 두 터렛사이의 거리보다 작다면 존재할 수 없다.(두 원이 만나지 않는다.)
			cout << 0 << endl;
		}
		else if (r1 + r2 == dist) {	//  두 터렛의 위치가 다르고 각각 목표와의 거리의 합이 두 터렛사이의 거리와 같다면 한 지점에서만 존재할 수 있다.(두 원이 외접한다.)
			cout << 1 << endl;
		}
		else {	//  두 터렛의 위치가 다르고 각각 목표와의 거리의 합이 두 터렛사이의 거리보다 크다면 두 지점에서 존재할 수 있다.(두 원이 두 지점에서 만난다.)
			cout << 2 << endl;
		}
	}

	return 0;
}