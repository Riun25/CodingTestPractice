#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> A(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	int count = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (K >= A[i])
		{
			count += K / A[i];
			K %= A[i];
			if (K == 0)
			{
				break;
			}
		}
	}

	cout << count;
}