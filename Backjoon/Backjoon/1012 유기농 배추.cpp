#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;

int cabbage[50][50];		// ����� �� �迭

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;		// �׽�Ʈ ���̽�
	cin >> testCase;
	int earthwormN;		// ������ ��
	vector<pair<int, int>> bfs;		// bfs�� �ϱ� ���� vector
	while (testCase--) {
		earthwormN = 0;
		int m, n;		// ���α��̿� ���α���
		cin >> m >> n;
		for (int i = 0; i < n; i++) {
			memset(cabbage[i], 0, m);		// ����� �� �ʱ�ȭ
		}
		int k;		// ������� ��
		cin >> k;
		for (int i = 0; i < k; i++) {
			int x, y;		// ����߰� �ɾ��� ��ġ ���� ��
			cin >> x >> y;
			cabbage[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cabbage[i][j] == 1) {		// ����߰� �ɾ��� �ִٸ� bfs�� �αٿ� ����߰� �ɾ��� ��ġ ��� Ž��
					earthwormN++;
					int tempX = j;
					int tempY = i;
					cabbage[tempY][tempX] = -1;		// ����߰� �ɾ����ִٴ� ���� -1�� �����ϴ� ������ Ȯ��ǥ��
					bfs.push_back(make_pair(tempY, tempX));
					while (!bfs.empty()) {		// bfs vector�� ������� ���� ������ �ݺ�
						if (tempY != 0) {		// ���� ����� �ʱ� ����
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