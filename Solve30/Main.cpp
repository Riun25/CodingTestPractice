#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> A(N, 0);

	int sum = 0;
	for (auto e : A)
	{
		cin >> e;
		sum += e;
	}

	int minSize = sum / M; // 최소 idx
	// 가장 최소 일 확률
	if (sum % M != 0)
	{
		minSize++;
	}

	


	return 0;
}