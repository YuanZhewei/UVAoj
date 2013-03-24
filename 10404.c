#include <stdio.h>
#include <string.h>

#define MAXN 1000010
#define MAXM 12

int n, m;
int dp[MAXN], stones[MAXM];
int main()
{
	int i, j;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (i = 1; i <= m; i++)
			scanf("%d", &stones[i]);

		dp[0] = 0;
		for (i = 1; i <=n; i++) {
			dp[i] = 0;
			for (j = 1; j <= m; j++) {
				if (i >= stones[j] && !dp[i - stones[j]]) {
					dp[i] = 1;
					break;
				}
			}
		}
		if (dp[n])
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
	return 0;
}
