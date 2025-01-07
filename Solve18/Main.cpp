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

	vector<int> S(N, 0);
	int sum = A[0];
	S[0] = A[0];

	for (int i = 1; i < N; i++)
	{
		S[i] = S[i - 1] + A[i];
		sum += S[i];
	}

	cout << sum;

	return 0;
}