//http://codeforces.com/problemset/problem/429/B
/*题目：
给n*m的矩阵，每个格子有个数，A从(1,1)出发只能向下或右走，终点为(n,m)，B从(n,1)出发只能向上或右走，终点为(1,m)。两个人的速度不一样，走到的格子可以获的该格子的数，两人相遇的格子上的数两个人都不能拿。求A和B能拿到的数的总和的最大值。*/
/*解题思路：
某点坐标为(i,j)，需要得到（1,1）到(i,j)最大值；（i,j)到(n,m)最大值；（n,1)到(i,j)最大值；(i,j)到(1,m)最大值。然后比较。注意两者相遇一次。*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string.h>

using namespace std;

int a[1010][1010];

int dp[4][1010][1010];
long long ans=0;

int main()
{
	int m, n;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]) + a[i][j];
		}
		for (int j = m; j >= 1; j--)
		{
			dp[2][i][j] = max(dp[2][i - 1][j], dp[2][i][j + 1])+a[i][j];
		}
	}

	for (int i = n; i >= 1;i--)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[1][i][j] = max(dp[1][i + 1][j], dp[1][i][j - 1]) + a[i][j];
		}
		for (int j = m; j >= 1; j--)
		{
			dp[3][i][j] = max(dp[3][i + 1][j], dp[3][i][j + 1]) + a[i][j];
		}
	}

	long long tmp = 0;

	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j < m; j++)
		{
			tmp = dp[0][i - 1][j] + dp[1][i][j - 1] + dp[2][i][j + 1] + dp[3][i + 1][j];
			ans = max(ans, tmp);
			tmp = dp[0][i][j - 1] + dp[1][i + 1][j] + dp[2][i - 1][j] + dp[3][i][j + 1];
			ans = max(ans,tmp);
		}
	}
	printf("%ld", ans);
	return 0;
}


