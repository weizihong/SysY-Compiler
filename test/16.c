#include <stdio.h>

const int inf = 1000000000, INF = 0x3f3f3f3f, mod = 998244353, maxn = 20005;
int n, k, a[maxn], p[maxn];
int dp[maxn][22][2], g[maxn][22][2];

int pw(int x, int y)
{
	if (!y)
		return 1;
	if (y == 1)
		return x % mod;
	int mid = pw(x, y / 2);
	if (y % 2 == 1)
		return mid * mid % mod * x % mod;
	return mid * mid % mod;
}

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	scanf("%d %d", &n, &k);
	int i = 1;
	while (1)
	{
		if (i > n)
			break;
		scanf("%d", &a[i]);
		i = i + 1;
	}
	i = 1;
	while (1)
	{
		if (i > n)
			break;
		scanf("%d", &p[i]);
		i = i + 1;
	}

	g[0][0][0] = 1;
	i = 1;
	while (1)
	{
		if (i > n)
			break;
		dp[i][0][0] = 0;
		g[i][0][0] = (1 - p[i] + mod) * g[i - 1][0][0] % mod;
		int j = 1;
		while (1)
		{
			if (j > min(k, (i + 1) / 2))
				break;
			dp[i][j][0] = dp[i][j][0] + (1 - p[i] + mod) * (dp[i - 1][j][1] + dp[i - 1][j][0]) % mod;
			dp[i][j][0] = dp[i][j][0] % mod;
			dp[i][j][1] = dp[i][j][1] + p[i] * (dp[i - 1][j - 1][0] + 1 * g[i - 1][j - 1][0] * a[i] % mod) % mod;
			dp[i][j][1] = dp[i][j][1] % mod;
			dp[i][j][1] = dp[i][j][1] + p[i] * (dp[i - 1][j][1] + 1 * g[i - 1][j][1] * a[i] % mod) % mod;
			dp[i][j][1] = dp[i][j][1] % mod;
			g[i][j][1] = g[i][j][0] + p[i] * (g[i - 1][j][1] + g[i - 1][j - 1][0]) % mod;
			g[i][j][1] = g[i][j][1] % mod;
			g[i][j][0] = g[i][j][0] + (1 - p[i] + mod) * (g[i - 1][j][1] + g[i - 1][j][0]) % mod;
			g[i][j][0] = g[i][j][0] % mod;
			j = j + 1;
		}
		i = i + 1;
	}
	int bs = pw((g[n][k][1] + g[n][k][0]) % mod, mod - 2);
	printf("%d\n", (dp[n][k][1] + dp[n][k][0]) % mod);
	return 0;
}