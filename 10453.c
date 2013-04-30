#include <stdio.h>
#include <string.h>

#define LEN 1024
#define INF 0x3f3f3f3f

char s[LEN];
int dp[LEN][LEN];
int p[LEN][LEN];

int min(int a, int b)
{
	return a < b? a: b;
}

void printpath(int a, int b)
{
	if (a > b)
		return;

	if (p[a][b] == 0) {
		if (a == b)
			printf("%c", s[a]);
		else {
			printf("%c", s[a]);
			printpath(a+1, b-1);
			printf("%c", s[b]);
		}
	} else if (p[a][b] == 1) {
		printf("%c", s[b]);
		printpath(a, b-1);
		printf("%c", s[b]);
	} else {
		printf("%c", s[a]);
		printpath(a+1, b);
		printf("%c", s[a]);
	}
}

int main()
{
	int len, l, i, j;
	while (scanf("%s", s) != EOF) {
		len = strlen(s);
		memset(dp, 0x3f, sizeof(dp));
		for (i = 1; i < len; i++)
			dp[i][i] = dp[i][i-1] = 0;
		dp[0][0] = 0;

		for (l = 1; l < len; l++)
			for (i = 0; i < len - l; i++) {
				j = i + l;
				if (s[i] == s[j]) {
					dp[i][j] = dp[i+1][j-1];
					p[i][j] = 0;
				} else {
					if (dp[i][j-1]+1 < dp[i][j]) {
						dp[i][j] = dp[i][j-1] + 1;
						p[i][j] = 1;
					}
					if (dp[i+1][j]+1 < dp[i][j]) {
						dp[i][j] = dp[i+1][j] + 1;
						p[i][j] = 2;
					}
				}
			}
		printf("%d ",dp[0][len-1]);
		printpath(0, len - 1);
		printf("\n");
	}
	return 0;
}

