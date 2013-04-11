#include <stdio.h>
#include <string.h>

#define isset(a, i) ((a) & 1 << (i))
#define set(a, i) ((a) |= (1 << (i)))
#define flip(a, i) ((a) ^= (1 << (i)))

int t;
int line;
int count;
char str[24];
int dp[4096];
int visit[4096];
int min;
void init()
{
	int i;
	line = 0;
	count = 0;
	scanf("%s", str);
	for (i = 0; i < 12; i++) {
		if (str[i] == 'o') {
			set(line, i);
			count++;
		}
	}
	memset(visit, 0, sizeof(visit));
	dp[line] = count;
	min = count;
}

void dfs(int x)
{
	int i, tmp, flag = 0;
	if (visit[x])
		return;
	visit[x] = 1;

	for (i = 1; i < 11; i++) {
		if (isset(x, i) && ((isset(x, i-1) && !isset(x, i+1)) || (!isset(x, i-1) && isset(x, i+1)))) {
			tmp = x;
			flip(tmp, i-1);
			flip(tmp, i);
			flip(tmp, i+1);
			dp[tmp] = dp[x] - 1;
			if (dp[tmp] < min)
				min = dp[tmp];
			dfs(tmp);
		}
	}
}

void solve()
{
	if (count != 0) 
		dfs(line);

	printf("%d\n", min);
}
int main()
{
	scanf("%d", &t);

	while (t--) {
		init();
		solve();
	}
	return 0;
}
