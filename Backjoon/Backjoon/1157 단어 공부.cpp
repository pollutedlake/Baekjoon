#include<iostream>
using namespace std;

int alphabet[26];		// 단어에 사용된 알파벳의 개수를 저장하는 배열

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string word;		// 입력받는 단어
	cin >> word;
	for (int i = 0; i < word.length(); i++) {		// 단어에 사용된 알파벳의 개수를 알파벳마다 조사한다.
		if (word.at(i) >= 97) {		// 소문자라면
			alphabet[word.at(i) - 97]++;

		}
		else {		// 대문자라면
			alphabet[word.at(i) - 65]++;
		}
	}
	int max = -1;		// 가장 많이 사용된 횟수
	int maxIdx = -1;		// 가장 많이 사용된 알파벳
	for (int i = 0; i < 26; i++) {		// 가장 많이 사용된 알파벳을 알아본다.
		if (alphabet[i] == 0) {		// 이 알파벳이 사용되지 않았다면 건너뛴다.
			continue;
		}
		if (max < alphabet[i]) {		// 최댓값인지 비교
			max = alphabet[i];
			maxIdx = i;
		}
		else if (max == alphabet[i]) {		// 사용된 횟수가 같다면 maxIdx를 -1로 초기화
			maxIdx = -1;
		}
	}
	if (maxIdx == -1) {		// maxIdx가 -1이라면 '?'출력
		cout << '?' << endl;
	}
	else {		// 가장 많이 사용된 알파벳 대문자로 출력
		cout << (char)(maxIdx + 65) << endl;
	}
}