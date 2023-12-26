#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
namespace fio
{
	/*
		½»»¥Ìâ½ûÓÃ
		¹ØÁ÷¿ÉÒÔ¿ª
		I:FIN and getchar and scanf
		Only C In
		O:(printf and puts) or cout
		C Out or CPP Out
	*/
	constexpr int BUF_SZ = 1e5;
	bool iof = true;
	inline char NC(void)
	{
		static char buf[BUF_SZ], *p = buf + BUF_SZ, *ed = buf + BUF_SZ;
		if (p != ed)
			return *p++;
		p = buf;
		ed = buf + fread(buf, 1, BUF_SZ, stdin);
		if (p == ed)
		{
			iof = false;
			return -1;
		}
		return *p++;
	}
	inline bool BLK(char c) { return c == ' ' or c == '\n' or c == '\r' or c == '\t'; }
	template <class T>
	inline bool FIN(T &x)
	{
		bool sign = false;
		char c = NC();
		x = 0;
		while (BLK(c))
			c = NC();
		if (not iof)
			return false;
		if (c == '-')
		{
			sign = true;
			c = NC();
		}
		while ('0' <= c and c <= '9')
		{
			x = x * 10 + c - '0';
			c = NC();
		}
		if (sign)
			x = -x;
		return true;
	}
	inline bool FIN(db &x)
	{
		bool sign = false;
		char c = NC();
		x = 0;
		while (BLK(c))
			c = NC();
		if (not iof)
			return false;
		if (c == '-')
		{
			sign = true;
			c = NC();
		}
		while ('0' <= c and c <= '9')
		{
			x = x * 10 + c - '0';
			c = NC();
		}
		if (c == '.')
		{
			db w = 1.0;
			c = NC();
			while ('0' <= c and c <= '9')
			{
				w /= 10.0;
				x += w * (c - '0');
				c = NC();
			}
		}
		if (sign)
			x = -x;
		return true;
	}
	inline bool FIN(char &c)
	{
		c = NC();
		while (BLK(c))
			c = NC();
		if (not iof)
		{
			c = -1;
			return false;
		}
		return true;
	}
	inline bool FIN(char *s)
	{
		char c = NC();
		while (BLK(c))
			c = NC();
		if (not iof)
			return false;
		while (iof and not BLK(c))
		{
			*s++ = c;
			c = NC();
		}
		*s = 0;
		return true;
	}
	inline bool LIN(char *s)
	{
		char c = NC();
		while (BLK(c))
			c = NC();
		if (not iof)
			return false;
		while (iof and c != '\n')
		{
			*s++ = c;
			c = NC();
		}
		*s = 0;
		return true;
	}
	template <class T, class... U>
	bool FIN(T &x, U &...o) { return FIN(x) and FIN(o...); }
	void FIN(int *a, int l, int r)
	{
		for (int i = l; i <= r; ++i)
			FIN(a[i]);
		return;
	}
	void FIN(ll *a, int l, int r)
	{
		for (int i = l; i <= r; ++i)
			FIN(a[i]);
		return;
	}
	void FIN(db *a, int l, int r)
	{
		for (int i = l; i <= r; ++i)
			FIN(a[i]);
		return;
	}
	void FIN(char *a, int l, int r)
	{
		for (int i = l; i <= r; ++i)
			FIN(a[i]);
		return;
	}
}
using namespace fio;
const int N = 1e5 + 10;
int lowbit(int x){return x & -x;}
int tr[N], n;
void add(int i, int x){
    for(;i <= n;i += lowbit(i)) tr[i] += x;
}
int query(int i){
    int res = 0;
    for(;i;i-=lowbit(i)) res += tr[i];
    return res;
}
struct node{
    int l, r, id;
    bool operator< (const node& ji)const{
        return l < ji.l;
    }
};
void Solve(){
    FIN(n);
    vector<int> a(n + 1), pos(n + 1);
    rep(i, 1, n){
        FIN(a[i]);
        pos[a[i]] = i;
    }
    int m; FIN(m); vector<node> f(m);
    for(int i = 0;i < m;i ++){
        int l, r;
        FIN(l); FIN(r);
        f[i] = {l, r, i};
    }
    sort(f.begin(), f.end());
    int now = 1;
    vector<vector<int>> son(n + 1);
    rep(i, 1, n){
        for(int j = 1;j <= sqrt(2 * n);j ++){
            int x = j * j - a[i];
            if(x > n) break;
            if(x <= 0 || pos[x] <= i) continue;
            add(pos[x], 1);
            son[i].push_back(pos[x]);
        }
    }
    vector<int> res(m);
    for(auto [l, r, id]:f){
        cout << l << ' ' << r << endl;
        while(now < l){
            for(auto x:son[now]){
                add(x, -1);
            }
            now ++;
        }
        res[id] = query(r);
    }
    for(auto x:res) cout << x << endl; 
    rep(i, 1, n) tr[i] = 0;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; t = FIN(t); while(t --)
    Solve();
    return 0;
}