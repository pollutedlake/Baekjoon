#include<iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;
	cin >> testCase;
	while (testCase--) {
		char seatState[10][10];
		int seat[10][10];
		memset(seat, 0, sizeof(seat));
		int row, col;
		cin >> row >> col;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> seatState[i][j];
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (seatState[i][j] != '.') {
					seat[i][j] = -1;
					continue;
				}
				if (j != 0) {
					if (seatState[i][j - 1] == '.') {
						seat[i][j]++;
					}
					if (i != 0) {
						if (seatState[i - 1][j - 1] == '.') {
							seat[i][j]++;
						}
					}
				}
				if (j != col - 1) {
					if (seatState[i][j + 1] == '.') {
						seat[i][j]++;
					}
					if (i != 0) {
						if (seatState[i - 1][j + 1] == '.') {
							seat[i][j]++;
						}
					}
				}
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << seat[i][j];
			}
			cout << endl;
		}
		
	}
}

// https://m.blog.naver.com/kelle111/221537563173