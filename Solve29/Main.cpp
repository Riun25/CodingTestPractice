#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> A(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	int num;
	cin >> num;


	for (int i = 0; i < num; i++)
	{
		int temp;
		cin >> temp;
		bool isFind = false;

		int s = 0;
		int e = A.size() - 1;

		while (s <= e)
		{
			int mid = (s + e) / 2;
			int midValue = A[mid];

			if (midValue > temp)
			{
				e = mid - 1;
			}
			else if (midValue < temp)
			{
				s = mid + 1;
			}
			else
			{
				isFind = true;
				break;
			}
		}
		std::cout << isFind << "\n";
	}
	return 0;
}