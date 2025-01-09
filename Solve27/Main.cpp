#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> map;
	vector<vector<bool>> visited;
	map.resize(N);

	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}







	return 0;
}