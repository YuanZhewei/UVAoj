#include <stdio.h>
#include <string.h>

#define MAXN 255
#define INF 0x3f3f3f3f

int dp[MAXN][MAXN];
int S[MAXN];
int sum[MAXN];

int min(int a, int b)
{
	return a < b ? a: b;
}

int main()
{
	int n, i, j, l, k, m;

	while (scanf("%d", &n) != EOF) {
		for (i = 1; i <= n; i++)
			scanf("%d", &S[i]);

		sum[0] = 0;
		for (i = 1; i <= n; i++)
			sum[i] = sum[i-1] + S[i];

		memset(dp, 0, sizeof(dp));

		for (l = 1; l < n; l++)
		       for (i = 1; i <= n - l; i++) {
				j = i + l;
				dp[i][j] = INF;
				for (k = i; k <= j; k++)
					dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k+1][j] + sum[j] - sum[i-1] - S[k]);
			}
		printf("%d\n", dp[1][n]);
	}
	return 0;
}
