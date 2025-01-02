#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N;
	cin >> M;
	vector<int> C(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> C[i];
	}
	sort(C.begin(), C.end());

	int count = 0, s = 0, e = N-1;

	while (s < e)
	{
		if (C[s] + C[e] > M)
		{
			e--;
		}
		else if (C[s] + C[e] < M)
		{
			s++;
		}
		else
		{
			s++;
			e--;
			count++;
		}
	}

	cout << count << "\n";

	return 0;
}