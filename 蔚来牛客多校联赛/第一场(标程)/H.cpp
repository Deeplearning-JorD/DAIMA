#include <bits/stdc++.h>
#define maxn 270086

using namespace std;

typedef long long ll;

const int p = 998244353;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

const int G = 3, invG = fpow(G, p - 2);
int pos[maxn], prt[2][30]; 

inline void init(){
	for(int i = 1, j = 2;i <= 23;i++, j <<= 1) prt[0][i] = fpow(G, (p - 1) / j);
	for(int i = 1, j = 2;i <= 23;i++, j <<= 1) prt[1][i] = fpow(invG, (p - 1) / j);
}

inline void NTT(int *a, int lim, int type){
	for(int i = 0;i < lim;i++) if(i < pos[i]) swap(a[i], a[pos[i]]);
	for(int mid = 1, pw = 1;mid < lim;mid <<= 1, pw++){
		int wn = prt[type == -1][pw];
		for(int i = mid << 1, j = 0;j < lim;j += i){
			int w = 1;
			for(int k = 0;k < mid;k++, w = 1ll * w * wn % p){
				int x = a[j + k], y = 1ll * w * a[j + k + mid] % p;
				a[j + k] = x + y;
                if(a[j + k] >= p) a[j + k] -= p;
				a[j + k + mid] = x - y + p;
                if(a[j + k + mid] >= p) a[j + k + mid] -= p;
			} 
		}
	}
	if(type == -1){
		int invlim = fpow(lim, p - 2);
		for(int i = 0;i < lim;i++) a[i] = 1ll * a[i] * invlim % p;
	}
} 

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

int a[maxn], L[maxn << 2], R[maxn << 2], st[maxn], cnt, len;
int A[maxn], B[maxn];

void build(int x, int l, int r){
	if(l == r){
		L[x] = st[l], R[x] = st[l + 1] - 1;
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	int deg = R[ls(x)] - L[ls(x)] + R[rs(x)] - L[rs(x)], lim = 1;
	while(lim <= deg) lim <<= 1;
	for(int i = 0;i < lim;i++) A[i] = B[i] = 0, pos[i] = (pos[i >> 1] >> 1) | ((i & 1) ? (lim >> 1) : 0);
	for(int i = L[ls(x)];i <= R[ls(x)];i++) A[i - L[ls(x)]] = a[i];
	for(int i = L[rs(x)];i <= R[rs(x)];i++) B[i - L[rs(x)]] = a[i];
	NTT(A, lim, 1), NTT(B, lim, 1);
	for(int i = 0;i < lim;i++) A[i] = 1ll * A[i] * B[i] % p;
	NTT(A, lim, -1);
	L[x] = L[ls(x)], R[x] = L[x] + deg;
	for(int i = L[x];i <= R[x];i++) a[i] = A[i - L[x]];
}

inline void add(int &x, int y){
	x += y;
	if(x >= p) x -= p;
}

int n, k, x, y;
ll m;
int siz[maxn];
vector<int> v[maxn];
int f[2][maxn], F[2][maxn], g[maxn];

int main(){
	init();
	scanf("%d%lld%d", &n, &m, &k);
	int sum = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d", &siz[i]), sum += siz[i];
		st[++cnt] = len;
		for(int j = 0;j <= siz[i];j++, len++) a[len] = j == 0 || j == siz[i];
	}
	st[cnt + 1] = len;
	build(1, 1, n);
	while(k--){
		scanf("%d%d", &x, &y);
		v[y].push_back(x);
	}
	int lim = 1;
	while(lim <= 3 * sum) lim <<= 1;
	for(int i = 0;i < lim;i++) pos[i] = (pos[i >> 1] >> 1) | ((i & 1) ? (lim >> 1) : 0);
	f[0][0] = 1;
	for(int i = 0;m >> i;i++){
		for(int j = 0;j <= R[1];j++) g[j] = a[j];
		for(int j = R[1] + 1;j < lim;j++) g[j] = 0;
		sort(v[i].begin(), v[i].end());
		v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
		for(int j = 0;j < v[i].size();j++){
			int x = siz[v[i][j]];
			for(int k = x;k <= R[1];k++) add(g[k], p - g[k - x]);
		}
		NTT(f[0], lim, 1), NTT(f[1], lim, 1), NTT(g, lim, 1);
		for(int j = 0;j < lim;j++) f[0][j] = 1ll * f[0][j] * g[j] % p, f[1][j] = 1ll * f[1][j] * g[j] % p;
		NTT(f[0], lim, -1), NTT(f[1], lim, -1);
		for(int j = 0;j < lim;j++){
			if((j & 1) < ((m >> i) & 1)){
				add(F[0][j >> 1], f[0][j]);
				add(F[0][j >> 1], f[1][j]);
			}else if((j & 1) == ((m >> i) & 1)){
				add(F[0][j >> 1], f[0][j]);
				add(F[1][j >> 1], f[1][j]);
			}else{
				add(F[1][j >> 1], f[0][j]);
				add(F[1][j >> 1], f[1][j]);
			}
		}
		for(int j = 0;j < lim;j++) f[0][j] = F[0][j], f[1][j] = F[1][j], F[0][j] = F[1][j] = 0;
	}
	printf("%d", f[0][0]);
}
