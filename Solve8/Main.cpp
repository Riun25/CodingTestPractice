#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> A(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	int idx = 0, count = 0;
	int s = 0, e = N-1;

	for (idx = 0; idx < N; idx++)
	{
		s = 0;
		e = N - 1;

		while (s < e)
		{
			if (A[s] + A[e] > A[idx])
			{
				e--;
			}
			else if (A[s] + A[e] < A[idx])
			{
				s++;
			}
			else
			{
				if (s != idx && e != idx) // 숫자가 고유의 수가 아니라서 같은 수가 들어갈 수도 있다.
				{
					count++;
					break;
				}
				else if (s == idx)
				{
					s++;
				}
				else if (e == idx)
				{
					e--;
				}
			}
		}
	}

	std::cout << count << "\n";

	return 0;
}