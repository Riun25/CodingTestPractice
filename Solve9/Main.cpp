#include <iostream>
using namespace std;

int checkArr[4] = {}; // 체크용
int myArr[4] = {}; // 현재값
string A; // 입력되는 값
int matchNum = 0;

void Add(char c)
{
	switch (c)
	{
	case 'A':
		myArr[0]++; // 문자를 처음에 넣어주는 행위이기에 if 문보다 먼저 선언
		if (myArr[0] == checkArr[0])
		{
			matchNum++;
		}
		break;
	case 'C':
		myArr[1]++; // 문자열이라 포인터 배열임
		if (myArr[1] == checkArr[1])
		{
			matchNum++;
		}
		break;
	case 'G':
		myArr[2]++; // 문자열이라 포인터 배열임
		if (myArr[2] == checkArr[2])
		{
			matchNum++;
		}
		break;
	case 'T':
		myArr[3]++; // 문자열이라 포인터 배열임
		if (myArr[3] == checkArr[3])
		{
			matchNum++;
		}
		break;
	default:
		break;
	}
}

void Remove(char c)
{
	switch (c)
	{
	case 'A':
		if (myArr[0] == checkArr[0])
		{
			matchNum--;
		}
		myArr[0]--; // 문자열이라 포인터 배열임
		break;
	case 'C':
		if (myArr[1] == checkArr[1])
		{
			matchNum--;
		}
		myArr[1]--; // 문자열이라 포인터 배열임
		break;
	case 'G':
		if (myArr[2] == checkArr[2])
		{
			matchNum--;
		}
		myArr[2]--; // 문자열이라 포인터 배열임
		break;
	case 'T':
		if (myArr[3] == checkArr[3])
		{
			matchNum--;
		}
		myArr[3]--; // 문자열이라 포인터 배열임
		break;
	default:
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S, P;
	cin >> S >> P;
	cin >> A;

	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> checkArr[i];
		if (checkArr[i] == 0) // 0일 땐 무조건 오케이
		{
			matchNum++;
		}
	}

	for (int i = 0; i < P; i++)
	{
		Add(A[i]);
	}

	if (matchNum == 4)
	{
		count++;
	}

	for (int i = P; i < S; i++)
	{
		int j = i - P;
		Add(A[i]); // p번째 추가
		Remove(A[j]); // 가장 앞에 문자 삭제
		if (matchNum == 4)
		{
			count++;
		}
	}
	cout << count << "\n";

	return 0;
}