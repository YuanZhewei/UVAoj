#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM 1024
int n, w;

char tmp[NUM];
int c = 0;
int g[NUM][NUM];
int dp[NUM][NUM];

void convert(char *s, int row)
{
	char *i, *end;
	int t,
	    col = 0, 
	    len = strlen(s);
	if (len == 0)
		return;

	end = s + len;
	for (i = s + 1; i < end; i++) {
		while (isdigit(*i)) {
			t = *i - '0';
			col = col * 10 + t;
			i++;
		} 
		g[row][col] = 1;
		col = 0;
	}
}

void init()
{
	int i, j;
	scanf("%d %d", &w, &n);
	memset(g, 0, sizeof(g));
	for (i = 0; i < w; i++) {
		scanf("%d", &j);
		gets(tmp);

		convert(tmp, i+1);
	}

	g[1][1] = 1;

}

void solve()
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	dp[1][1] = 1;
	for (i = 1; i <= w; i++)
		for (j = 1; j <= n; j++)
			if (!g[i][j])
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
	if (c == 0)
		c = 1;
	else
		puts("");
	printf("%d\n", dp[w][n]);
}

int main()
{
	int t, i, j;
	scanf("%d", &t);
	while (t--) {
		init();
		solve();
	}
	return 0;
}

