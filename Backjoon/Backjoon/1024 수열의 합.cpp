#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	long long N;
	int L;
	cin >> N >> L;

	long long a1 = -1;
	int sequenceN = 0;
	for (long long i = L; (float)(i * (i - 1)) / 2.0f <= N; i++)
	{
		a1 = ((N * 2 / i - (i - 1)) / 2);
		if (i * (2 * a1 + (i - 1)) / 2 == N)
		{
			sequenceN = i;
			break;
		}
	}
	if (sequenceN == 0)
	{
		cout << -1;
	}
	for (int i = 0; i < sequenceN; i++)
	{
		cout << (long long)(a1 + i) << " ";
	}
	return 0;
}