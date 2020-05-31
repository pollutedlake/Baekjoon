/*
���� : 1005 ACM Craft
�ۼ��� : �ڻ���
�ۼ��� :2020.06.01
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector <int>> buildGraph;		// �ǹ� ���� �Ǽ� ������ ��Ÿ���� �׷���
vector<int> building;		// �ǹ����� �Ǽ� �ð�
vector<bool> check;		// DFS�� �� �̹� Ž���� �� ������� Ȯ���ϴ� bool
vector<int> path;		// DFS Ž�� ���

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;		// �׽�Ʈ���̽�
	int buildingN, orderN;		// �ǹ� ��, ���� ��
	int winCond;		// �̱�� ���� �Ǽ��ؾ� �ϴ� �ǹ�
	int buildTime;		// �ǹ��� ���� ���� �ð�
	int x, y;		// �ǹ��� ���� ������ �Է¹ޱ� ���� ����
	cin >> testCase;		// �׽�Ʈ���̽� �Է¹���
	while (testCase--) {
		cin >> buildingN >> orderN;		// �ǹ� ��, ���� ���� �Է¹���
		while (buildingN--) {
			cin >> buildTime;		// �ǹ� ����ŭ �Ǽ� �ð��� �Է¹ް� building�� push, buildGraph�� vector push, check�� flase push
			building.push_back(buildTime);
			buildGraph.push_back(*(new vector<int>));
			check.push_back(false);
		}
		while (orderN--) {
			cin >> x >> y;		// ���� �� ��ŭ ������ �Է¹ް� �׷����� �����.
			buildGraph.at(y - 1).push_back(x);
		}
		cin >> winCond;		// winCond �Է¹���
		path.push_back(winCond);		// ��ο� winCond push�Ѵ�.
		int max, now;		// �Ǽ��ð��� �ִ�, ���� �ǹ� ����
		bool dfs;		// �ڽ� ����� dfs�� ������� pop�ϰ� ���ư������� ����
		while (!path.empty()) {		// path�� �� �� ���� �ݺ��Ѵ�.
			max = building.at((path.back() - 1));		// �Ǽ��ð� �ִ� ���� �ǹ��� �Ǽ� �ð����� �ʱ�ȭ
			now = path.back();		// ���� �ǹ��� DFS Ž�� ����� ������
			dfs = false;		// dfs �ʱ�ȭ
			for (int i = 0; i < buildGraph.at(now - 1).size(); i++) {	// ���� �ǹ��� �ڽ� ���� Ž��
				if (check.at(buildGraph.at(now - 1).at(i) - 1) == false) {	// ���� �ǹ��� �ڽ� ��带 Ž���� ���� ���ٸ�
					path.push_back(buildGraph.at(now - 1).at(i));		// ��ο� �ڽ� ��带 �ְ�
					dfs = true;		// �ڽ� ��忡�� dfs ����
					break;
				}
				if (max < building.at(now - 1) + building.at(buildGraph.at(now - 1).at(i) - 1)) {		// ���� ����� �Ǽ��ð��� �ڽĳ���� �Ǽ� �ð��� ���� �� �� �ִ��� ���Ѵ�.
					max = building.at(now - 1) + building.at(buildGraph.at(now - 1).at(i) - 1);
				}
			}
			if (!dfs) {		// ���� ����� dfs�� �����ٸ� ���� ����� �Ǽ��ð��� �ִ����� �ٲٰ� Ž���� �Ϸ��ߴٰ� check�ϰ� ��ο��� pop�Ͽ� �����Ѵ�.
				building.at(now - 1) = max;
				check.at(now - 1) = true;
				path.pop_back();
			}
		}
		cout << building.at(winCond - 1) << endl;
		buildGraph.clear();
		building.clear();
		path.clear();
		check.clear();
	}
}