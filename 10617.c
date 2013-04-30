#include <stdio.h>
#include <string.h>

#define MAXN 65
char s[MAXN];
long long dp[MAXN][MAXN];

int main()
{
	int t, cnt, n, i, j, l;

	scanf("%d", &t);

	while (t--) {
		scanf("%s", s);
		n = strlen(s);
		memset(dp, 0, sizeof(dp));

		for (i = 0; i < n; i++)
			dp[i][i] = 1;
		
		for (l = 1; l < n; l++)
			for (i = 0; i < n-l; i++) {
				j = i+l;
				if (s[i] == s[j] )
					dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
				else
					dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
			}

		printf("%lld\n", dp[0][n-1]);
	}

	return 0;
}
