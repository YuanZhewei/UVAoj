#include <stdio.h>
#include <string.h>

#define MAX 10001

long long dp[22][MAX];
int v[22];

int main()
{
	int n, i, j;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (i = 1; i < 22; i++) {
		v[i] = i * i * i;
		for (j = 0; j < MAX; j++)
			if (j >= v[i])
				dp[i][j] = dp[i-1][j] + dp[i][j-v[i]];
	       		else
				dp[i][j] = dp[i-1][j];	
	}

	while (scanf("%d", &n) != EOF) {
		printf("%lld\n", dp[21][n]);	
	}
	return 0;
}
