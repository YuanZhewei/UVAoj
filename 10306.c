#include <stdio.h>
#include <string.h>

#define MAXN 301
#define INF 0x3f3f3f3f
int dp[MAXN][MAXN];
int w1[50], w2[50];

int min(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
	int cases, m, S, i, j, k, t;
	int ans = INF;
	scanf("%d", &cases);

	while (cases--) {
		scanf("%d %d", &m, &S);
		for (i = 0; i < m; i++)
			scanf("%d %d", &w1[i], &w2[i]);
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0] = 0;

		for (i = 0; i < m; i++)
			for (j = w1[i]; j <= S; j++)
				for (k = w2[i]; k <= S; k++) 
					if (dp[j-w1[i]][k-w2[i]] != INF)
						dp[j][k] = min(dp[j][k], dp[j-w1[i]][k-w2[i]] + 1);
		ans = INF;	
		t = S * S;
		for (i = 0; i <= S; i++)
			for (j = 0; j <= S; j++)
				if (i * i + j * j == t && dp[i][j] != INF)
					if (ans > dp[i][j])
						ans = dp[i][j];
		if (ans == INF)
			printf("not possible\n");
		else
			printf("%d\n", ans);
	}

	return 0;
}

