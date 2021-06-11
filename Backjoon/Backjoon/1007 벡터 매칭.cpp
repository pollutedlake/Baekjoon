/*
파일 : 1007 벡터 매칭.cpp
작성자 : 박상현
작성일 : 2021.06.11
*/
#include<iostream>
#include<utility>
#include<cmath>
#include<deque>
using namespace std;
#pragma warning(disable:4996)

/*
 벡터의 합은 v1 + v2 + v3 + ... + vN/2 = (x2+x4+x6+...+xN -x1-x3-x5...-xN-1,y2+y4+y6+...+yN -y1-y3-y5...-yN-1)이므로 뺄 점들의 조합을 구해 계산한다.
  nCn/2
*/
double FindMinLen(int tot_x, int tot_y, int x_sum, int y_sum, deque<pair<int, int>> points, int start, int n) {		// 가능한 모든 벡터의 합의 최소길이를 구하는 함수
	if (n == points.size()/2) {
		return sqrt(pow(tot_x - 2 * x_sum, 2) + pow(tot_y - 2 * y_sum, 2));
	}
	double minLen = 99999999;
	for (int i = start; i < points.size(); i++) {
		if (i == 0 && i > points.size() / 2) {		// N/2개까지만 선택하니까 맨 처음은 0번부터 N/2까지만 계산한다.
			break;
		}
		double temp = FindMinLen(tot_x, tot_y, x_sum + points.at(i).first, y_sum + points.at(i).second, points, i + 1, n + 1);
		if (temp < minLen) {
			minLen = temp;
		}
	}
	return minLen;
}

deque<pair<int, int>> points;		// 점들의 집합

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int pointN;		// 점들의 개수
		cin >> pointN;
		points.clear();
		int x, y;
		int x_sum = 0;
		int y_sum = 0;
		for (int i = 0; i < pointN; i++) {		// 점들을 입력받으면서 x좌표와 y좌표의 총합을 계산
			cin >> x >> y;
			x_sum += x;
			y_sum += y;
			points.push_back(make_pair(x, y));
		}
		cout << fixed;
		cout.precision(12);
		cout << FindMinLen(x_sum, y_sum, 0, 0, points, 0, 0) << endl;
	}
}