#include <stdio.h>
#include <string.h>

#define N 60
#define INF 0x3f3f3f3f3f
int length, n;
int dp[N][N];
int cut[N];

int min(int x, int y) {
	return x < y ? x : y;
}
int main()
{
	int i, j, l, k, m;
	while (scanf("%d", &length) != EOF && length != 0) {
		scanf("%d", &n);
		cut[0] = 0;
		cut[n + 1] = length;

		for (i = 1; i <= n; i++)
			scanf("%d", &cut[i]);
		for (i = 0; i<= n; i++)
			dp[i][i+1] = 0;

		for (l = 2; l <= n + 1; l++)
			for (i = 0; i <= n - l + 1; i++) {
				j = i + l;
				m = INF;
				for (k = i + 1; k < j; k++) 
					m = min(m, dp[i][k] + dp[k][j]);
				dp[i][j] = m + cut[j] - cut[i];
			}
		printf("The minimum cutting is %d.\n", dp[0][n + 1]);
	}
	return 0;
}