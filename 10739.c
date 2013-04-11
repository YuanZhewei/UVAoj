#include <stdio.h>
#include <string.h>
#define LEN 1024
int len;
char str[LEN];
int f[LEN][LEN];

int min(int x, int y)
{
	return x < y ? x: y;
}

int dp(int x, int y)
{
	if (f[x][y] == -1) {
		if (x >= y)
			f[x][y] = 0;
		else if (str[x] == str[y])
			f[x][y] = dp(x+1, y-1);
		else
			f[x][y] = 1 + min(min(dp(x+1,y), dp(x,y-1)), dp(x+1,y-1));
	}

	return f[x][y];
}
int main()
{
	int t, count = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);
		len = strlen(str);
		memset(f, -1, sizeof(f));
		printf("Case %d: %d\n", ++count, dp(0, len-1));
	}
	return 0;
}
