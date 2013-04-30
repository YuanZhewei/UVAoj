#include <stdio.h>
#include <string.h>
#define K 1024
#define N 5100
#define INF 0x3f3f3f3f
int dp[N][K];
int ch[N];

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int t, k, n;
	int i, j;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &k, &n);
		for (i = n; i > 0; i--)
			scanf("%d", &ch[i]);
		k += 8;

		memset(dp, 0x3f, sizeof(dp));
		for (i = 0; i <= n; i++)
			dp[i][0] = 0;
		for (i = 3; i <=n; i++)
			for (j = 1; j*3 <= i; j++)
				if (dp[i-2][j-1] != INF)
					dp[i][j] = min(dp[i-1][j], dp[i-2][j-1] + (ch[i]-ch[i-1]) * (ch[i] - ch[i-1]));
		printf("%d\n", dp[n][k]);		
	}
	return 0;
}
