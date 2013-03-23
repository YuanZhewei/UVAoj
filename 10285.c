#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 110
int heights[NUM][NUM], dp[NUM][NUM];
int r, c;
int dx[] = {-1, 1, 0, 0}, dy[] = { 0, 0, -1 , 1};
char addr[256];
void init()
{
		int i, j;
		scanf("%s %d %d", addr, &r, &c);

		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				scanf("%d", &heights[i][j]); 
}

int dfs(int x, int y)
{
	int i, j, newx, newy, tmp;
	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 1;
	for (i = 0; i < 4; i++) {
		newx = x + dx[i];
		newy = y + dy[i];

		if (newx >= 0 && newx < r && newy >=0 && newy < c && heights[newx][newy] > heights[x][y]) {
			tmp = dfs(newx, newy);
			if (tmp + 1 > dp[x][y])
				dp[x][y] = tmp + 1;
		}
	}

	return dp[x][y];
}

void solve()
{
	int i, j, tmp, max;
	memset(dp, -1, sizeof(dp));
	max = 1;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			tmp = dfs(i, j);
			if (tmp > max)
				max = tmp;
		}
	printf("%s: %d\n", addr, max);
}
int main()
{
	int t;
	
	scanf("%d", &t);
	while (t--) {
		init();
		solve();
	}

	return 0;
}