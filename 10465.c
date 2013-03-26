#include <stdio.h>
#include <string.h>

#define V 10010
int w[3];
int dp[V];
int num[V];
int m, n, t;
int max(int a, int b)
{
	return a > b ? a : b;
}
void cp()
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	memset(num, 0, sizeof(num));
	for (i = 1; i <= 2; i++)
		for (j = w[i]; j <= t; j++) {
			if (dp[j - w[i]] + w[i] > dp[j]) {
				dp[j] = dp[j - w[i]] + w[i];
				num[j] = num[j-w[i]] + 1;
			} else if (dp[j - w[i]] + w[i] == dp[j])
				num[j] = max(num[j-w[i]] + 1, num[j]);
		}
}
int main()
{
	
	while (scanf("%d %d %d", &m, &n, &t) != EOF) {
		w[1] = m;
		w[2] = n;
		cp();
		printf("%d", num[t]);

		if (t - dp[t])
			printf(" %d", t- dp[t]);
		printf("\n");
	}
	return 0;
}
