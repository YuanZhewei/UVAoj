#include <stdio.h>
#include <string.h>

#define NUM 21
#define W NUM * 100
int n, m;
int tapes[NUM];
int dp[W];
int p[W];

void print_path(int w)
{
	if (w > 0) {
		print_path(w - p[w]);
		printf("%d ", p[w]);
	}
}
int main()
{
	int i, j;
	while (scanf("%d %d", &m, &n) != EOF) {
		for (i = 1; i <= n; i++)
			scanf("%d", &tapes[i]);

		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= n; i++)
			for (j = m; j >= tapes[i]; j--) {
				if (dp[j] < dp[j - tapes[i]] + tapes[i]) {
					dp[j] = dp[j - tapes[i]] + tapes[i];
					p[j] = tapes[i];
				}
			}
		print_path(dp[m]);
		printf("sum:%d\n", dp[m]);
	}
	return 0;
}
