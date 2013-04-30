#include <stdio.h>
#include <string.h>

#define T 5700
#define INF 0x3f3f3f3f

int w[T], s[T];
int dp[T][T];

void swap(int a, int b)
{
	int tmpw = w[a], tmps = s[a];
	w[a] = w[b];
	s[a] = s[b];
	w[b] = tmpw;
	s[b] = tmps;
}

int min(int a, int b)
{
	return a < b ? a: b;
}

void qsort(int left, int right)
{
	int l = left, r = right, m = s[(l+r) / 2];
	while (l < r) {
		while (s[l] < m) l++;
		while (s[r] > m) r--;
		if (l <= r) {
			swap(l, r);
			l++; r--;
		}
	}
	if (r > left) qsort(left, r);
	if (l < right) qsort(l, right);
}

int main()
{
	int i, j, t = 0, ans = 0;
	while (scanf("%d %d", &i, &j) != EOF) {
		w[++t] = i;
		s[t] = j;
	}
	
	qsort(1, t);
	memset(dp, 0x3f, sizeof(dp));
	for (i = 0; i <= t; i++)
		dp[i][0] = 0;

	for (i = 1; i <= t; i++)
		for (j = 1; j <= i; j++) {
			dp[i][j] = dp[i-1][j];
			if (dp[i-1][j-1] != INF && dp[i-1][j-1] + w[i] <= s[i]) {
				dp[i][j] = min(dp[i-1][j-1] + w[i], dp[i][j]);
			}
		}
	for (i = t; i > 0; i--)
		if (dp[t][i] != INF) {
			ans = i;
			break;
		}
	printf("%d\n", ans);
	return 0;
}
