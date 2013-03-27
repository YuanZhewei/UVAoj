#include <stdio.h>
#include <string.h>

#define LENX 10010
#define LENZ 110
#define LEN 30
#define BASE 1000000000

class bignum {
public:
	bignum() : len(0) { }
	bignum(int v) : len(0)
	{
		while (v > 0) {
			data[len++] = v % BASE;
			v /= BASE;
		}
	}
	friend bignum operator+ (const bignum &a, const bignum &b);
	int &operator[] (int index)
	{
		return data[index];
	}

	int operator[] (int index) const
	{
		return data[index];
	}
	
	void print();
private:
	int len;
	int data[30];
};

bignum operator+ (const bignum &a, const bignum &b)
{
	bignum res;
	int i, carry = 0;
	for (i = 0; i < a.len || i < b.len || carry > 0; i++) {
		if (i < a.len)
			carry += a[i];
		if (i < b.len)
			carry += b[i];
		res[i] = carry % BASE;
		carry /= BASE;
	}

	res.len = i;

	return res;
}

void bignum::print()
{
	int i;
	if (len == 0) {
		printf("%d", 0);
		return;
	}
	for (i = len-1; i >= 0; i--)
		printf("%d", data[i]);


}
char x[LENX], z[LENZ];
bignum dp[LENX][LENZ];

void solve()
{
	int i, j, c = 0,
	    lenx = strlen(x + 1),
	    lenz = strlen(z + 1);
	for (i = 1; i < lenx; i++) {
		if (z[1] == x[i])
			dp[i][1] = bignum(++c);
		else
			dp[i][1] = bignum(c);
	}

	for (i = 2; i <= lenx; i++)
		for (j = 2; j <= lenz; j++)
			if (x[i] == z[j])
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
	 dp[lenx][lenz].print();
	 printf("\n");
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s%s", x + 1, z + 1);

		solve();
	}
	return 0;	
}
