#include<iostream>
#include<vector>
#include<cstring>
#include<math.h>
using namespace std;

int list[50];
int check[50];
vector<int> result;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int length;
	cin >> length;
	for (int i = 0; i < length; i++) {
		cin >> list[i];
		check[i] = -1;
	}
	for (int i = 1; i < length; i++) {
		int sum = list[i] + list[0];
		bool isPrime = false;
		for (int k = 2; k <= sqrt(sum); k++) {
			if (sum % k == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			result.push_back(list[i]);
			check[i] = 0;
			check[0] = 0;
			for (int j = 1; j < length - 1; j++) {
				if (check[j] == -1) {
					for (int k = j + 1; k < length; k++) {
						if (check[k] == -1) {
							sum = list[j] + list[k];
							for (int l = 2; 2 <= sqrt(sum); l++) {
								if (sum % l == 0) {
									isPrime = false;
									break;
								}
							}
							if (isPrime) {
								check[j] = 0;
								check[k] = 0;
								break;
							}
						}
					}
				}
			}
		}
	}
}