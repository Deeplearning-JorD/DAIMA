#include <bits/stdc++.h>
#define inf 0x7fffffff
#define eps 1e-14
#define maxm 100005 
#define maxn 505
#define ls (tot << 1)
#define rs (tot << 1 | 1)
#define PII pair<int, int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const double pi = acos(-1);
const ll mod = 1e9 + 7;
inline ll read(){
    ll x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int qpow(int a, int b){
    int ans = 1, base = a;
    while(b){
        if(b & 1) ans = 1ll * ans * base % mod;
        base = 1ll * base * base % mod;
        b >>= 1;
    }
    return ans;
}

const int N = 405;
int fac[N], inv[N], prime[N], pnum, mu[N];//, sub[maxn];
bool visprime[N];


void init(){
	fac[0] = 1;
	for(int i = 1; i <= N; i++) fac[i] = 1ll * i * fac[i - 1] % mod;
	inv[N] = qpow(fac[N], mod - 2);
	for(int i = N - 1; i >= 0; i--) inv[i] = 1ll * (i + 1) * inv[i + 1] % mod;
	mu[1] = 1;
	for(int i = 2; i <= N; i++){
		if(!visprime[i]) prime[++pnum] = i, mu[i] = 1;//, sub[i] = i;
		for(int j = 1; j <= pnum; j++){
			if(prime[j] * i > N) break;
			visprime[prime[j] * i] = 1;
			if(i % prime[j] == 0) {
				mu[prime[j] * i] = 0;
				break;
			}
			mu[prime[j] * i] = -mu[i];
			//sub[prime[j] * i] = min(prime[j], sub[i]);
		}
	}
}

void add(int &x, int y){
	x += y;
	if(x >= mod) x -= mod;
}

void mul(int &x, int y){
	x = 1ll * x * y % mod;
}

int C(int n, int m){
	if(n < m || n < 0 || m < 0) return 0;
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int n, m, c1[maxn], c2[maxn], inde[2][maxn], tot[2];

struct p{
	int u, v, nxt;
}e[2][maxn << 1];

void addEdge(int id, int u, int v){e[id][++tot[id]] = {u, v, inde[id][u]}, inde[id][u] = tot[id];}


vector<int> lst, rst; 
int match[maxn], pre[maxn];
ll mp[maxn][maxn], ex[maxn], ey[maxn], slack[maxn]; 
bool vis[maxn];
void check(int u){
	ll x, y = 0, yy = 0, delta;
	pre[0] = 0;
    for(auto i: rst) pre[i] = 0;
    for(auto i: rst) slack[i] = inf;
    match[y] = u;
    while(1){	
        x = match[y], delta = inf, vis[y] = 1;
        for(auto i: rst){	
            if(vis[i])continue;
            if(slack[i] > ex[x] + ey[i] - mp[x][i]){	
                slack[i] = ex[x] + ey[i] - mp[x][i];
                pre[i] = y;
            }
            if(slack[i] < delta) {delta = slack[i];yy = i;}
        }if(vis[0]) ex[match[0]] -= delta, ey[0] += delta;
            else slack[0] -= delta;
        for(auto i: rst){	
            if(vis[i]) ex[match[i]] -= delta, ey[i] += delta;
            else slack[i] -= delta;
        }
        y = yy;
        if(match[y]==-1)break;
    }
    while(y){match[y] = match[pre[y]];y = pre[y];}
}
ll KM()
{	
	for(auto i: rst) match[i] = -1;
	match[0] = -1;
//    memset(match, -1, sizeof(match));
    for(auto i: lst) ex[i] = ey[i] = 0;
    for(auto i: rst) ex[i] = ey[i] = 0;
    ex[0] = ey[0] = 0;
    for(auto i: lst){
		vis[0] = 0;	
        for(auto j: rst) vis[j] = 0;
        check(i);
    }
    ll res = 0;
    for(auto i: rst)
        if(match[i] != -1) res += mp[match[i]][i];
    return res;
}

bool ok[maxn][maxn];
int dp[maxn][maxn][2];

void solve(int u, int f1, int v, int f2){
	if(ok[u][v]) return ;
	//TODO: clear KM 
	for(int i = inde[0][u]; i; i = e[0][i].nxt){
		int s1 = e[0][i].v;
		if(s1 == f1) continue;
		for(int j = inde[1][v]; j; j = e[1][j].nxt){
			int s2 = e[1][j].v;
			if(s2 == f2) continue;
			if(!ok[s1][s2]) solve(s1, u, s2, v);
			//TODO: addEdge and stack
		}
	}
	for(int i = inde[0][u]; i; i = e[0][i].nxt){
		int s1 = e[0][i].v;
		if(s1 == f1) continue;
		if(!ok[s1][v]) solve(s1, u, v, f2);
	}
	for(int j = inde[1][v]; j; j = e[1][j].nxt){
		int s2 = e[1][j].v;
		if(s2 == f2) continue;
		if(!ok[u][s2]) solve(u, f1, s2, v);
	}
	
	lst.clear(), rst.clear();
	for(int i = inde[0][u]; i; i = e[0][i].nxt){
		int s1 = e[0][i].v;
		if(s1 == f1) continue;
		dp[u][v][0] = max(dp[u][v][0], dp[s1][v][0]);
		lst.push_back(s1);
	}
	for(int j = inde[1][v]; j; j = e[1][j].nxt){
		int s2 = e[1][j].v;
		if(s2 == f2) continue;
		dp[u][v][0] = max(dp[u][v][0], dp[u][s2][0]);
		rst.push_back(s2);
	}
	bool f = 0;
	if(lst.size() > rst.size()) lst.swap(rst), f = 1;
	for(int i = inde[0][u]; i; i = e[0][i].nxt){
		int s1 = e[0][i].v;
		if(s1 == f1) continue;
		for(int j = inde[1][v]; j; j = e[1][j].nxt){
			int s2 = e[1][j].v;
			if(s2 == f2) continue;
			if(f) mp[s2][s1] = dp[s1][s2][0];
			else mp[s1][s2] = dp[s1][s2][0];
		}
	}
	
	dp[u][v][1] = c1[u] == c2[v] ? KM() + 1 : 0;
	dp[u][v][0] = max(dp[u][v][1], dp[u][v][0]);
	ok[u][v] = 1;
	
	for(int i = inde[0][u]; i; i = e[0][i].nxt){
		int s1 = e[0][i].v;
		if(s1 == f1) continue;
		for(int j = inde[1][v]; j; j = e[1][j].nxt){
			int s2 = e[1][j].v;
			if(s2 == f2) continue;
			if(f) mp[s2][s1] = 0;
			else mp[s1][s2] = 0;
		}
	}
}

void solve(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++) c1[i] = read();
	for(int i = 1; i <= m; i++) c2[i] = read();
	for(int i = 1; i < n; i++){
		int u = read(), v = read();
		addEdge(0, u, v), addEdge(0, v, u);
	}
	for(int i = 1; i < m; i++){
		int u = read(), v = read();
		addEdge(1, u, v), addEdge(1, v, u);
	}
	solve(1, 0, 1, 0);
	printf("%d\n", dp[1][1][0]);
}

int main(){
    init();
    int t = 1, cnt = 1;
	while(t--){
//		printf("Case #%d: ", cnt++);
		solve();
	}
	
   return 0;
}
/*
*/

