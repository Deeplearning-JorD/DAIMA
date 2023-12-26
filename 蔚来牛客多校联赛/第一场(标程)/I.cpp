#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int n = 136 - 13;
const int mod = 1000000007;

char start[30];
int mapping[255];
int tiles[10][4];
int single;

int f[15][150];
int inv[150];

int fpw(int b, int e = mod - 2)
{
	if (e == 0)
		return 1;
	int ret = fpw(b, e >> 1);
	ret = 1ll * ret * ret % mod;
	if (e & 1)
		ret = 1ll * ret * b % mod;
	return ret;
}

void pre()
{
	mapping['m'] = 0;
	mapping['p'] = 1;
	mapping['s'] = 2;
	mapping['z'] = 3;
	for (int i = 1; i <= n; i++)
	{
		inv[i] = fpw(i);
		for (int j = 1; j <= 13; j++)
		{
			f[j][i] = (1
				+ 1ll * f[max(0, j - 2)][i - 1] * (3 * j) % mod * inv[i]
				+ 1ll * f[j][i - 1] * (i - 3 * j) % mod * inv[i]) % mod;
		}
	}
}

int solve()
{
	scanf("%s", start + 1);
	memset(tiles, 0, sizeof(tiles));
	single = 0;
	for (int i = 1; i <= 26; i += 2)
		tiles[start[i] - '0'][mapping[start[i + 1]]]++;
	for (int i = 1; i <= 9; i++)
		for (int j = 0; j < 4; j++)
			if (tiles[i][j] == 1)
				single++;
	return f[single][n];
}

int main()
{
	pre();
	int T, tc = 0;
	scanf("%d", &T);
	while (T--)
		printf("Case #%d: %d\n", ++tc, solve());
	return 0;
}