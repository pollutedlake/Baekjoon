#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int num;
	for (int i = r1; i <= r2; i++)
	{
		for (int j = c1; j <= c2; j++)
		{
			int swirl = max(abs(i), abs(j));
			if (i == swirl)
			{
				printf("%d ", (int)pow(swirl * 2 + 1, 2) - (swirl - j));
			}
			else if (i == -swirl)
			{
				printf("%d ", (int)pow(swirl * 2, 2) + 1 - (j - i));
			}
			else
			{
				if (j == swirl)
				{
					printf("%d ", (int)pow((swirl - 1) * 2 + 1, 2) + 1 + ((swirl - 1) - i));
				}
				else
				{
					printf("%d ", (int)pow(swirl * 2, 2) + 1 - (j - i));
				}
			}
		}
		cout << endl;
	}
	return 0;
}