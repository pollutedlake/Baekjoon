#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;

int cabbage[50][50];		// 양배추 밭 배열

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;		// 테스트 케이스
	cin >> testCase;
	int earthwormN;		// 지렁이 수
	vector<pair<int, int>> bfs;		// bfs를 하기 위한 vector
	while (testCase--) {
		earthwormN = 0;
		int m, n;		// 가로길이와 세로길이
		cin >> m >> n;
		for (int i = 0; i < n; i++) {
			memset(cabbage[i], 0, m);		// 양배추 밭 초기화
		}
		int k;		// 양배추의 수
		cin >> k;
		for (int i = 0; i < k; i++) {
			int x, y;		// 양배추가 심어진 위치 열과 행
			cin >> x >> y;
			cabbage[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cabbage[i][j] == 1) {		// 양배추가 심어져 있다면 bfs로 인근에 양배추가 심어진 위치 계속 탐색
					earthwormN++;
					int tempX = j;
					int tempY = i;
					cabbage[tempY][tempX] = -1;		// 양배추가 심어져있다는 것을 -1를 대입하는 것으로 확인표시
					bfs.push_back(make_pair(tempY, tempX));
					while (!bfs.empty()) {		// bfs vector가 비어있지 않을 떄까지 반복
						if (tempY != 0) {		// 밭을 벗어나지 않기 위해
							if (cabbage[tempY - 1][tempX] == 1) {
								bfs.push_back(make_pair(tempY - 1, tempX));
								cabbage[tempY - 1][tempX] = -1;
							}
						}
						if (tempX != m - 1) {
							if (cabbage[tempY][tempX + 1] == 1) {
								bfs.push_back(make_pair(tempY, tempX + 1));
								cabbage[tempY][tempX + 1] = -1;
							}
						}
						if (tempY != n - 1) {
							if (cabbage[tempY + 1][tempX] == 1) {
								bfs.push_back(make_pair(tempY + 1, tempX));
								cabbage[tempY + 1][tempX] = -1;
							}
						}
						if (tempX != 0) {
							if (cabbage[tempY][tempX - 1] == 1) {
								bfs.push_back(make_pair(tempY, tempX - 1));
								cabbage[tempY][tempX - 1] = -1;
							}
						}
						tempY = bfs.back().first;
						tempX = bfs.back().second;
						bfs.pop_back();
					}
				}
			}
		}
		cout << earthwormN << endl;
	}
}