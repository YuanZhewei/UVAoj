#include <stdio.h>
#include <string.h>

#define G 110
#define TANK 210
#define INF 0x3f3f3f3f
int gd[G], gp[G];
int dp[G][TANK];
char tmp[16];
int d, n;

int min(int a, int b)
{
	return a < b ? a: b;
}

void init()
{
	n = 0;
	gets(tmp);
	sscanf(tmp, "%d", &d);

	while (gets(tmp) != NULL && tmp[0] != '\0') {
		++n;
		sscanf(tmp, "%d %d", &gd[n], &gp[n]);

		if (gd[n] < 0|| gd[n] > d)
			--n;
	}

	memset(dp, 0x3f, sizeof(dp));
	dp[0][100] = 0;
}

void solve()
{
	int i, j, l, temp;

	for (i = 1; i<= n; i++) {
		l = gd[i] - gd[i-1];
		for (j = l; j <= 200; j++)
			dp[i][j-l] = dp[i-1][j];
		for (j = 1; j <= 200; j++) {
			if (dp[i][j-1] != INF)
				dp[i][j] = min(dp[i][j], dp[i][j-1]+gp[i]);
		}
	}

	if (d - gd[n] > 100 || dp[n][100+d-gd[n]] == INF)
		printf("Impossible\n");
	else
		printf("%d\n", dp[n][100+d-gd[n]]);
}

int main()
{
	int t, i;
	gets(tmp);
	sscanf(tmp, "%d", &t);
	gets(tmp);
	gd[0] = 0, gp[0] = 0;
	while (t--) {

		init();
		solve();
		if (t)
			printf("\n");
	}
	
	return 0;
}

