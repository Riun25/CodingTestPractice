#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> origine;

	int input;
	cin >> input;

	while (input > 0)
	{
		origine.push_back(input % 10);
		input /= 10;
	}

	sort(origine.begin(), origine.end(), std::greater<int>());

	for (auto e : origine)
	{
		cout << e;
	}

	return 0;
}