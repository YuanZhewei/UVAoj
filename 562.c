#include <stdio.h>
#include <string.h>

#define NUM 101
int n, m, sum, half;
int v[NUM], dp[NUM * 500];
int main()
{
	int i, j, k, ans;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &m);
		sum = 0;
		for (j = 1; j <= m; j++) {
			scanf("%d", &v[j]);
			sum += v[j];
		}

		half = sum / 2;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (j = 1; j <= m; j++)
			for (k = half; k >= v[j]; k--)
				if (dp[k - v[j]])
					dp[k] = 1;

		j = sum / 2;

		while (!dp[j]) j--;

		ans = sum - 2 * j;

		printf("%d\n", ans);
	}
	return 0;
}
