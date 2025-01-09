#include <iostream>
#include <vector>
using namespace std;

static int M = 0;
vector<vector<int>> A;
vector<bool> visited;
static bool isAlreadyFive = false;

void DFS(int _num, int _depth)
{
	if (_depth == 5 || isAlreadyFive == true)
	{
		isAlreadyFive = true;
		return;
	}

	visited[_num] = true;

	for (auto e : A[_num])
	{
		if (visited[e] == false)
		{
			DFS(e, _depth + 1);
		}
	}

	visited[_num] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N >> M; // 사람, 관계

	A.resize(N);
	visited = vector<bool>(N, 0);

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	for (int i = 0; i < N; i++)
	{
		DFS(i, 1);
		if (isAlreadyFive == true)
		{
			break;
		}
	}

	cout << isAlreadyFive;
	return 0;
}