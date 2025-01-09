#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> A;
vector<bool> visited;

void DFS(int n)
{
	cout << n << " ";
	visited[n] = true;

	for (auto e : A[n])
	{
		if (visited[e] == false)
		{
			DFS(e);
		}
	}
}

void BFS(int n)
{
	queue<int> que;
	que.push(n);
	visited[n] = true;

	while (!que.empty())
	{
		int now = que.front();
		que.pop();
		cout << now << " ";
		for (auto e : A[now])
		{
			if (visited[e] == false)
			{
				visited[e] = true;
				que.push(e);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, S;
	cin >> N >> M >> S;

	A.resize(N + 1);
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(A[i].begin(), A[i].end());
	}

	DFS(S);
	cout << "\n";
	fill(visited.begin(), visited.end(), false);
	BFS(S);

	return 0;
}