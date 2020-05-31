/*
파일 : 1005 ACM Craft
작성자 : 박상현
작성일 :2020.06.01
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector <int>> buildGraph;		// 건물 간의 건설 순서를 나타내는 그래프
vector<int> building;		// 건물들의 건설 시간
vector<bool> check;		// DFS할 때 이미 탐색을 한 노드인지 확인하는 bool
vector<int> path;		// DFS 탐색 경로

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;		// 테스트케이스
	int buildingN, orderN;		// 건물 수, 순서 수
	int winCond;		// 이기기 위해 건설해야 하는 건물
	int buildTime;		// 건물을 짓기 위한 시간
	int x, y;		// 건물을 짓는 순서를 입력받기 위한 변수
	cin >> testCase;		// 테스트케이스 입력받음
	while (testCase--) {
		cin >> buildingN >> orderN;		// 건물 수, 순서 수를 입력받음
		while (buildingN--) {
			cin >> buildTime;		// 건물 수만큼 건설 시간을 입력받고 building에 push, buildGraph에 vector push, check에 flase push
			building.push_back(buildTime);
			buildGraph.push_back(*(new vector<int>));
			check.push_back(false);
		}
		while (orderN--) {
			cin >> x >> y;		// 순서 수 만큼 순서를 입력받고 그래프를 만든다.
			buildGraph.at(y - 1).push_back(x);
		}
		cin >> winCond;		// winCond 입력받음
		path.push_back(winCond);		// 경로에 winCond push한다.
		int max, now;		// 건설시간의 최댓값, 현재 건물 변수
		bool dfs;		// 자식 노드의 dfs를 실행시지 pop하고 돌아가야할지 여부
		while (!path.empty()) {		// path가 빌 때 까지 반복한다.
			max = building.at((path.back() - 1));		// 건설시간 최댓값 현재 건물의 건설 시간으로 초기화
			now = path.back();		// 현재 건물은 DFS 탐색 경로의 마지막
			dfs = false;		// dfs 초기화
			for (int i = 0; i < buildGraph.at(now - 1).size(); i++) {	// 현재 건물의 자식 노드들 탐색
				if (check.at(buildGraph.at(now - 1).at(i) - 1) == false) {	// 현재 건물의 자식 노드를 탐색한 적이 없다면
					path.push_back(buildGraph.at(now - 1).at(i));		// 경로에 자식 노드를 넣고
					dfs = true;		// 자식 노드에서 dfs 실행
					break;
				}
				if (max < building.at(now - 1) + building.at(buildGraph.at(now - 1).at(i) - 1)) {		// 현재 노드의 건설시간과 자식노드의 건설 시간을 합한 것 중 최댓값을 구한다.
					max = building.at(now - 1) + building.at(buildGraph.at(now - 1).at(i) - 1);
				}
			}
			if (!dfs) {		// 현재 노드의 dfs가 끝났다면 현재 노드의 건설시간을 최댓값으로 바꾸고 탐색을 완료했다고 check하고 경로에서 pop하여 삭제한다.
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