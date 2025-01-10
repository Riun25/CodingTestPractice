#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool changed = false;

	int N;
	cin >> N;

	vector<pair<int, int>> A(N); // data, idx

	for (int i = 0; i < N; i++)
	{
		cin >> A[i].first;
		A[i].second = i;
	}

	sort(A.begin(), A.end());
	int max = 0;

	for (int i = 0; i < N; i++)
	{
		if (max < A[i].second - i)
		{
			max = A[i].second - i;
		}
	}

	cout << max + 1;
	return 0;
}