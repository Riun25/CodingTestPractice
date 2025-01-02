#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M = 1;// N 수열 M 나눌 수
	cin >> N >> M;

	vector<long> S(N, 0);// S 합배열 D 나머지 배열
	vector<long> D(M, 0);

	long count = 0;
	cin >> S[0];

	for (int i = 1; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		S[i] = S[i - 1] + temp;
	}
	for (int i = 0; i < N; i++)
	{
		int extra = S[i] % M;
		if (extra == 0)
		{
			count++;
		}
		D[extra]++;
	}

	// 나머지 배열이 같은 것에서 조합 수를 뽑음
	for (int i = 0; i < M; i++)
	{
		if (D[i] > 1)
		{
			count += D[i] * (D[i] - 1) / 2;
		}
	}

	std::cout << count << "\n";

	return 0;
}