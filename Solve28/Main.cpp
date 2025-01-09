#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> A;
vector<bool> visited;
vector<int> myDistance;

void BFS(int _node)
{
	queue<int> que;
	que.push(_node);
	visited[_node] = true;
	while (!que.empty())
	{
		int now = que.front();
		que.pop();
		for (auto e : A[now])
		{
			if (visited[e.first] == false)
			{
				visited[e.first] = true;
				que.push(e.first);
				myDistance[e.first] = myDistance[now] + e.second;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V;
	cin >> V;

	A.resize(V + 1);
	visited = vector<bool>(V + 1, false);
	myDistance = vector<int>(V + 1, 0);

	for (int i = 0; i < V; i++)
	{
		int idx;
		cin >> idx;

		while (true)
		{
			int s, e;
			cin >> s;
			if (s == -1)
			{
				break;
			}
			cin >> e;
			A[idx].push_back(edge(s, e));
		}
	}

	BFS(1); // 1부터 시작
	int max = 1;
	for (int i = 2; i <= V; i++)
	{
		if (myDistance[max] < myDistance[i])
		{
			max = i;
		}
	}

	fill(myDistance.begin(), myDistance.end(), 0);
	fill(visited.begin(), visited.end(), false);

	BFS(max);
	sort(myDistance.begin(), myDistance.end());
	std::cout << myDistance[V];

	return 0;
}