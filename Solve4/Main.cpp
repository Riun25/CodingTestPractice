#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arrN, qN;
	cin >> arrN >> qN;

	vector<vector<int>> arr(arrN + 1, vector<int>(arrN + 1, 0));
	vector<vector<int>> arrSum(arrN + 1, vector<int>(arrN + 1, 0));

	for (int i = 1; i <= arrN; i++)
	{
		for (int j = 1; j <= arrN; j++)
		{
			cin >> arr[i][j];
			arrSum[i][j] = arrSum[i][j - 1] + arrSum[i - 1][j] - arrSum[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 0; i < qN; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int result = arrSum[x2][y2] - arrSum[x1 - 1][y2] - arrSum[x2][y1 - 1] + arrSum[x1 - 1][y1 - 1];
		cout << result << "\n";
	}

	return 0;
}