#include<iostream>
#include<cstring>
using namespace std;

string words[50];
int alphabet[26];
int check[26];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int wordN, teachN;
	cin >> wordN >> teachN;
	for (int i = 0; i < wordN; i++) {
		memset(check, 0, sizeof(int) * 26);
		cin >> words[i];
		for (int j = 0; j < words[i].length(); j++) {
			if (check[words[i][j] - 97] == 0) {
				alphabet[words[i][j] - 97]++;
				check[words[i][j] - 97] = 1;
			}
		}
	}
	for (int i = 0; i < teachN; i++) {
		int max = -1;
		int maxIdx = -1;
		for (int j = 0; j < 26; j++) {
			if (alphabet[j] > max) {
				max = alphabet[j];
				maxIdx = j;
			}
		}
		alphabet[maxIdx] = -1;
	}
	int readable = 0;
	for (int i = 0; i < wordN; i++) {
		for (int j = 0; j < words[i].length(); j++) {
			if (alphabet[words[i][j] - 97] != -1) {
				readable--;
				break;
			}
		}
		readable++;
	}
	cout << readable << endl;
}