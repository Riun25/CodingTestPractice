#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> A;
vector<vector<bool>> visited;
static int dirX[] = {1, 0, -1, 0};
static int dirY[] = { 0, 1, 0, -1 };
int N, M;

void BFS(int _row, int _col)
{
	queue<pair<int, int>> que;
	que.push(make_pair(_row, _col));

	while (!que.empty())
	{
		int now[2];
		now[0] = que.front().first;//r
		now[1] = que.front().second;//c
		que.pop();
		visited[_row][_col] = true;

		// 방향 추가해서 이제 이동
		for (int i = 0; i < 4; i++)
		{
			int x = now[1] + dirX[i];
			int y = now[0] + dirY[i];

			if (x >= 0 && y >= 0 && x < M && y < N)
			{
				if (A[y][x] != 0 && !visited[y][x])
				{
					visited[y][x] = true;
					A[y][x] = A[now[0]][now[1]] + 1; // 깊이값 추가
					que.push(make_pair(y, x));
				}
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	A.resize(N +1, vector<int>(M, 0));
	visited.resize(N +1, vector<bool>(M, false));

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			A[i][j] = str[j] - '0';
		}
	}

	BFS(0, 0);
	cout << A[N - 1][M - 1]; //목표 위치 값

	return 0;
}