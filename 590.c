#include <stdio.h>
#include <string.h>

#define N 16
#define K 1024
#define D 32
#define INF 0x3f3f3f3f

int f[N][K];
int fs[N][N][D];
int d[N][N];
int n, k;
int cases = 0;
int init()
{
	int i, j, m;
	scanf("%d %d", &n, &k);
	if (!n && !k)
		return 0;
	memset(d, 0, sizeof(d));
	memset(fs, 0, sizeof(fs));
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) {
			if (i == j)
				continue;
			scanf("%d", &d[i][j]);
			for (m = 1; m <= d[i][j]; m++)
				scanf("%d", &fs[i][j][m]);
		}
	memset(f, INF, sizeof(f));
	
	return 1;
}

int min(int a, int b)
{
	return a < b? a: b;
}

void dp()
{
	int i, j, m, p;
	f[1][0] = 0;
	for (m = 1; m <= k; m++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++) {
				if (i != j) {
					p = (m - 1) % d[j][i] + 1;
					if (fs[j][i][p] && f[j][m - 1] != INF)
						f[i][m] = min(f[i][m], f[j][m-1]+fs[j][i][p]);
				}
			}

	printf("Scenario #%d\n", ++cases);

	if (f[n][k] == INF)
		printf("No flight possible.\n\n");
	else
		printf("The best flight costs %d.\n\n", f[n][k]);
}	
int main()
{
	int i, j;
	while (init()) {
		dp();
	}
	return 0;
}
