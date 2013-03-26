#include <stdio.h>
#include <stdlib.h>

#define N 1001
#define MW 31

int n, g;
int p[N], w[N], dp[MW];

void take(int mw)
{
	int i, j;
	memset(dp, 0 ,sizeof(dp));
	for (i = 1; i <= n; i++)
		for (j = mw; j >= w[i]; j--)
			if (dp[j] < dp[j - w[i]] + p[i])
				dp[j] = dp[j - w[i]] + p[i];
}
int main()
{
	int t, i, mw, sum;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d %d", &p[i], &w[i]);
		scanf("%d", &g);
		sum = 0;
		while (g--) {
			scanf("%d", &mw);
			take(mw);
			sum += dp[mw];
		}

		printf("%d\n", sum);
	}
	return 0;
}
