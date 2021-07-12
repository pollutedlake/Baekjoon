/*
파일 : 1006 습격자 초라기
작성자 : 박상현
작성일 :2021.07.12
*/
#include <iostream>
#include<algorithm>
#define INF 987654321
using namespace std;

int dp[10000][3];
int enemy[2][20000];

void solve(int areaN, int platoon) {
	for (int i = 1; i < areaN; i++) {
		int down = enemy[0][i] + enemy[0][i - 1] <= platoon ? 1 : 2;
		int up = enemy[1][i] + enemy[1][i - 1] <= platoon ? 1 : 2;
		int vertical = enemy[0][i] + enemy[1][i] <= platoon ? 1 : 2;

		dp[i][0] = min({ dp[i - 1][0] + vertical, dp[i - 2][0] + up + down, dp[i - 1][1] + up + 1, dp[i - 1][2] + down + 1 });		// 위아래를 모두 고려하는 경우
		dp[i][1] = min(dp[i - 1][2] + down, dp[i - 1][0] + 1);		// 밑에만 고려하는 경우
		dp[i][2] = min(dp[i - 1][1] + up, dp[i - 1][0] + 1);		// 위에만 고려하는 경우
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;
	int areaN, platoon;		// 구역의 개수/2, 특수 소대원의 수
	cin >> testCase;
	while (testCase--) {
		cin >> areaN >> platoon;
		for (int i = 0; i < areaN; i++) {
			cin >> enemy[1][i];
		}
		for (int i = 0; i < areaN; i++) {
			cin >> enemy[0][i];
		}
		int ans = INF;
		int up = enemy[1][0];
		int down = enemy[0][0];
		// 처음과 끝이 연결되는 환형형태이므로 4가지 경우가 있다
		// 아무것도 연결되지 않은 경우
		dp[0][0] = enemy[0][0] + enemy[1][0] <= platoon ? 1 : 2;
		dp[0][1] = dp[0][2] = 1;
		solve(areaN, platoon);
		ans = min(ans, dp[areaN-1][0]);
		// 밑에만 연결된 경우
		if (enemy[0][0] + enemy[0][areaN - 1] <= platoon) {
			dp[0][0] = 2;
			dp[0][1] = dp[0][2] = 1;
			enemy[0][0] = INF;
			solve(areaN, platoon);
			ans = min(ans, dp[areaN - 1][2]);
			enemy[0][0] = down;
		}
		// 위에만 연결된 경우
		if (enemy[1][0] + enemy[1][areaN - 1] <= platoon) {
			dp[0][0] = 2;
			dp[0][1] = dp[0][2] = 1;
			enemy[1][0] = INF;
			solve(areaN, platoon);
			ans = min(ans, dp[areaN - 1][1]);
			enemy[1][0] = up;
		}
		// 위아래 모두 연결된 경우
		if ((enemy[0][0] + enemy[0][areaN - 1] <= platoon) && (enemy[1][0] + enemy[1][areaN - 1] <= platoon)) {
			dp[0][0] = 2;
			dp[0][1] = dp[0][2] = 1;
			enemy[0][0] = enemy[1][0] = INF;
			solve(areaN, platoon);
			ans = min(ans, dp[areaN - 2][0]);
			enemy[0][0] = down;
			enemy[1][0] = up;
		}
		if (areaN == 1) {
			ans = enemy[0][0] + enemy[1][0] <= platoon ? 1 : 2;
		}
		cout << ans << endl;
	}
}

// 참고 : https://kibbomi.tistory.com/128