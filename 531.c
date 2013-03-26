#include <stdio.h>
#include <string.h>

#define NUM 110
#define LEN 32
char src[NUM][LEN];
char dst[NUM][LEN];
int dp[NUM][NUM];
int p[NUM][NUM];
int n, m;
int flag;
void print_path(int i, int j)
{
	if (!i || !j)
		return;

	if (p[i][j] == 0) {
		print_path(i - 1, j - 1);
		if (flag)
			printf(" ");
		else
			flag = 1;

		printf("%s", src[i]);
	} else if (p[i][j] == 1)
		print_path(i - 1, j);
	else
		print_path(i, j - 1);
	
}

int init()
{
	n = 1;
	m = 1;
	for (;;) {
		if (scanf("%s", src[n]) == EOF)
			return 0;
		if (src[n][0] == '#')
			break;
		n++;
	}
	for (;;) {
		scanf("%s", dst[m]);
		if (dst[m][0] == '#')
			break;
		m++;
	}
	return 1;
}

void solve()
{
	int i, j;
	memset(dp, 0 ,sizeof(dp));
			
	for (i = 1; i < n; i++)
		for (j = 1; j < m; j++) {
				if (strcmp(src[i], dst[j]) == 0) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					p[i][j] = 0;
				} else {
					if (dp[i-1][j] > dp[i][j-1]) {
						dp[i][j] = dp[i-1][j];
						p[i][j] = 1;

					} else {
						dp[i][j] = dp[i][j-1];
						p[i][j] = -1;
					}
				}
		}
	flag = 0;
	print_path(n - 1, m - 1);
	printf("\n");

}
int main()
{

	while (init()) {
		solve();
	}
	return 0;
}
