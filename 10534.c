#include <stdio.h>
#include <string.h>

#define LEN 10010

int seq[LEN], stack[LEN], dpmax[LEN], dpmin[LEN];
int top, n;

void init()
{
	int i;
	for (i = 1; i <= n; i++)
		scanf("%d", &seq[i]);
}

int min(int a, int b)
{
	return a < b ? a : b;
}

void solve()
{
	int i, low, high, mid, max, tmp;
	top = 0;
	stack[top] = -1;
	for (i = 1; i <= n; i++) {
		if (seq[i] > stack[top]) {
			stack[++top] = seq[i];
			dpmax[i] = top;
		} else {
			low = 1;
			high = top;
			while (low <= high) {
				mid = (low + high) / 2;
				if (seq[i] > stack[mid])
					low = mid + 1;
				else
					high = mid - 1;
			}

			stack[low] = seq[i];
			dpmax[i] = low;
		}

	}
	
	top = 0;
	stack[top] = -1;

	for (i = n ; i > 0; i--) {
		if (seq[i] > stack[top]) {
			stack[++top] = seq[i];
			dpmin[i] = top;
		} else {
			low = 1;
			high = top;
			while (low <= high) {
				mid = (low + high) / 2;
				if (seq[i] > stack[mid])
					low = mid + 1;
				else 
					high = mid - 1;
			}

			stack[low] = seq[i];
			dpmin[i] = low;
		}
	}
	
	top = 0;
	max = 1;
	for (i = 1; i <= n; i++) {
		tmp = 2 * min(dpmax[i], dpmin[i]) - 1;
		if (tmp > max)
			max = tmp;
	}

	printf("%d\n", max);

}
int main() 
{
	while (scanf("%d", &n) != EOF) {
		init();
		solve();
	}
	return 0;
}
