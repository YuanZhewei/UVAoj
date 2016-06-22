#include <cstdio>

int main() {
    int f[31], g[31];
    f[0] = 1;
    f[1] = g[0] = 0;
    g[1] = 2;
    for (int i = 2; i < 31; i++) {
        f[i] = f[i-2] + g[i-1];
        g[i] = 2 * f[i-1] + g[i-2];
    }
    int n;
    while (scanf("%d", &n)  && n!= -1)
        printf("%d\n", f[n]);
    return 0;
}
