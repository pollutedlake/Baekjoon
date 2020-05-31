#include<stdio.h>
#include <string.h>

int main() {
	int sudoku[9][9];
	bool check[9];
	memset(check, false, 9);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf_s("%d", &sudoku[i][j]);
		}
	}
	for (int i = 0; i < 9; i++) {
		memset(check, false, 9);
		for (int j = 0; j < 9; j++) {
			if (check[sudoku[i][j]-1] == true) {
				printf("%s", "false");
				return 0;
			}
			check[sudoku[i][j]-1] = true;
		}
	}
	for (int j = 0; j < 9; j++) {
		memset(check, false, 9);
		for (int i = 0; i < 9; i++) {
			if (check[sudoku[i][j]-1] == true) {
				printf("%s", "false");
				return 0;
			}
			check[sudoku[i][j]-1] = true;
		}
	}
	for (int k = 0; k < 9; k++) {
		memset(check, false, 9);
		for (int i = (k / 3) * 3; i < (k / 3) * 3 + 3; i++) {
			for (int j = (k % 3) * 3; j < (k % 3) * 3 + 3; j++) {
				if (check[sudoku[i][j]-1] == true) {
					printf("%s", "false");
					return 0;
				}
				check[sudoku[i][j]-1] = true;
			}
		}
	}
	printf("%s\n", "true");
}