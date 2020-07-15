#include<iostream>
#include<math.h>
#include<sstream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	cin >> str;
	int lineN = 0;
	stringstream ssInt(str);
	int second;
	ssInt >> second;
	for (int i = 0; i < (int)str.length(); i++) {
		switch (str[i]) {
		case '1':
			lineN += 2;
			break;
		case '2':
		case '3':
		case '5':
		case '9':
			lineN += 5;
			break;
		case '6':
		case '0':
			lineN += 6;
			break;
		case '4':
			lineN += 4;
			break;
		case '8':
			lineN += 7;
			break;
		case '7':
			lineN += 3;
			break;
		}
	}
	int count = 0;
	int lineN2 = 0;
	while (lineN != lineN2) {
		second++;
		if (second > pow(10, str.length()) - 1) {
			second = 0;
		}
		int temp = second;
		for (int i = str.length() - 1; i >= 0; i--) {
			str[i] = (char)((temp % 10) + 48);
			temp /= 10;
		}
		lineN2 = 0;
		for (int i = 0; i < (int)str.length(); i++) {
			switch (str[i]) {
			case '1':
				lineN2 += 2;
				break;
			case '2':
			case '3':
			case '5':
			case '9':
				lineN2 += 5;
				break;
			case '6':
			case '0':
				lineN2 += 6;
				break;
			case '4':
				lineN2 += 4;
				break;
			case '8':
				lineN2 += 7;
				break;
			case '7':
				lineN2 += 3;
				break;
			}
		}
		count++;
	}
	cout << count << endl;
}