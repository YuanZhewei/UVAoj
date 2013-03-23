#include <stdio.h>
#include <string.h>
#define LEN 1002
#define MAX(a ,b) ((a) > (b) ? (a) : (b))
char src[LEN];
char dst[LEN];
int dp[LEN][LEN];

int main()
{
	int len1, len2, i, j;
	while (gets(src) && gets(dst))
	{
		len1 = strlen(src);
		len2 = strlen(dst);

		memset(dp, 0, sizeof(dp));

		for (i = 1; i <= len1; i++)
			for (j = 1; j <= len2; j++) {
				if (src[i-1] == dst[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
		}

		printf("%d\n", dp[len1][len2]);
	}
	return 0;
}