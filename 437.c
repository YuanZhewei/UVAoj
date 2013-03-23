#include <stdio.h>
#include <string.h>

#define N 100

int dp[N], g[N][N];
int bricks[N][3];
int n, m;
int x, y, z;
int c, max;
int cmp(int a, int b)
{
	return ((bricks[a][0] > bricks[b][0] && bricks[a][1] > bricks[b][1]) || (bricks[a][0] > bricks[b][1] && bricks[a][1] > bricks[b][0]));
}

void init()
{
	m = 0;
	while (n--) {
		scanf("%d %d %d", &x, &y, &z);
		bricks[m][0] = x, bricks[m][1] = y, bricks[m][2] = z;
		m++;
		bricks[m][0] = x, bricks[m][1] = z, bricks[m][2] = y;
		m++;
		bricks[m][0] = y, bricks[m][1] = z, bricks[m][2] = x;
		m++;
	}
}

void solve()
{
	int i, j;
	max = 0;
	memset(dp, -1, sizeof(dp));
	memset(g, 0, sizeof(g));
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
			g[i][j] = cmp(i, j);

	for (i = 0; i < m; i++) {
		dfs(i);
		if (max < dp[i])
			max = dp[i];
	}
	printf("Case %d: maximum height = %d\n",c++, max);  
}

int dfs(int a)
{
	int i;
	if (dp[a] != -1)
		return dp[a];

	dp[a] = bricks[a][2];
	for (i = 0; i < m; i++) {
		if (g[a][i] && dp[a] < dfs(i)+ bricks[a][2])
			dp[a] = dp[i] + bricks[a][2];
	}

	return dp[a];
}

int main()
{
	c = 1;
	while (scanf("%d", &n) && n != 0) {
		init();
		solve();
	}
	return 0;
}
