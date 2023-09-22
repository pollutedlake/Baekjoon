#include <iostream>
#include <algorithm>
#include "string.h"
#include <cmath>
#pragma warning (disable : 4996)
using namespace std;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int maxLen;
	char charN[10];
	int maxSwirl = max({ abs(r1), abs(r2), abs(c1), abs(c2) });
	sprintf(charN, "%d", (long long)pow(maxSwirl * 2 + 1, 2));
	maxLen = strlen(charN);
	for (int i = r1; i <= r2; i++)
	{
		for (int j = c1; j <= c2; j++)
		{
			int swirl = max(abs(i), abs(j));
			long long n;
			if (i == swirl)
			{
				n = (long long)pow(swirl * 2 + 1, 2) - (swirl - j);
			}
			else if (i == -swirl)
			{
				n = (long long)pow(swirl * 2, 2) + 1 - (j - i);
			}
			else
			{
				if (j == swirl)
				{
					n = (long long)pow((swirl - 1) * 2 + 1, 2) + 1 + ((swirl - 1) - i);
				}
				else
				{
					n = (long long)pow(swirl * 2, 2) + 1 - (j - i);
				}
			}
			sprintf(charN, "%d", n);
			for (int i = 0; i < maxLen - strlen(charN); i++)
			{
				cout << " ";
			}
			printf("%d", n);
		}
		cout << endl;
	}
	return 0;
}