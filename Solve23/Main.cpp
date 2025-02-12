#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;

void DFS(int _v)
{
	if (visited[_v])
	{
		return;
	}

	visited[_v] = true;

	for (int e : A[_v])
	{
		if (visited[e] == false)
		{
			DFS(e);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	A.resize(N + 1);
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	int count = 0;

	for (int i = 1; i < N + 1; i++)
	{
		if (!visited[i])
		{
			count++;
			DFS(i);
		}
	}

	cout << count;
	return 0;
}