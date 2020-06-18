#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int x, y, w, h;		// 한수의 x, y좌표, 직사각형의 오른쪽 위 꼭짓점 좌표
	cin >> x >> y >> w >> h;
	cout << min(min(min(x, y), w - x), h - y) << endl;		// 한수의 위치에서 가장 가까운 변까지의 거리 출력
}