/*
 * @Author: JorD
 * @LastEditTime: 2022-08-14 01:27:29
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
namespace fastIO{
#define BUF_SIZE 100000
#define OUT_SIZE 100000
    bool IOerror = 0;
    // read / fread
    // inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;}
    inline char nc(){
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if (p1 == pend){
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if (pend == p1){
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) { return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'; }
    template <class T>
    inline bool read(T &x){
        bool sign = 0;
        char ch = nc();
        x = 0;
        for (; blank(ch); ch = nc());
        if (IOerror)
            return false;
        if (ch == '-')
            sign = 1, ch = nc();
        for (; ch >= '0' && ch <= '9'; ch = nc())
            x = x * 10 + ch - '0';
        if (sign)
            x = -x;
        return true;
    }
    inline bool read(double &x)	{
        bool sign = 0;
        char ch = nc();
        x = 0;
        for (; blank(ch); ch = nc())
            ;
        if (IOerror)
            return false;
        if (ch == '-')
            sign = 1, ch = nc();
        for (; ch >= '0' && ch <= '9'; ch = nc())
            x = x * 10 + ch - '0';
        if (ch == '.'){
            double tmp = 1;
            ch = nc();
            for (; ch >= '0' && ch <= '9'; ch = nc())
                tmp /= 10.0, x += tmp * (ch - '0');
        }
        if (sign)
            x = -x;
        return true;
    }
    inline bool read(char *s){
        char ch = nc();
        for (; blank(ch); ch = nc());
        if (IOerror)
            return false;
        for (; !blank(ch) && !IOerror; ch = nc())
            *s++ = ch;
        *s = 0;
        return true;
    }
    inline bool read_line(char *s){
        char ch = nc();
        for (; blank(ch); ch = nc());
        if (IOerror)
            return false;
        for (; ch != '\n' && !IOerror; ch = nc())
            *s++ = ch;
        *s = 0;
        return true;
    }
    inline bool read(char &c){
        for (c = nc(); blank(c); c = nc());
        if (IOerror){
            c = -1;
            return false;
        }
        return true;
    }
    template <class T, class... U>
    bool read(T &h, U &...t) { return read(h) && read(t...); }
    #undef OUT_SIZE	
    #undef BUF_SIZE
};
using namespace fastIO;
void read(int *x, int l, int r){
    for (int i = l; i <= r; i++)
        read(x[i]);
}
void read(long long *x, int l, int r){
    for (int i = l; i <= r; i++)
        read(x[i]);
}
void read(double *x, int l, int r){
    for (int i = l; i <= r; i++)
        read(x[i]);
}

#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N=5e5+10;
pair<int,int> e[N];
int st[N];
int no[N];
bool noo[N];
const int M=2e5+10;
vector<int> son[N];
void dfs(int now,int fa){
    for(auto x:son[now]){
        if(x==fa||st[x]) continue;
        st[x]=2;
        dfs(x,now);
    }
}
int dfs1(int now,int fa){
    int res=0;
    for(auto x:son[now]){
        if(x==fa||st[x]) continue;
        st[x]=2;
        res++;
        res+=dfs1(x,now);
    }
    return res;
}
void Solve(){
    int n, m , k;
    read(n);
    read(m);
    read(k);
    rep(i,1,m)st[i+n]=1;
    rep(i,1,k){
        int a,b;
        read(a);read(b);
        e[i]={a,b};
    }
    int t; read(t);
    rep(i,1,t){  
        int x;
        read(x);
        no[i]=x;
        noo[x]=1;
    }
    vector<int> res(t+1);
    int now=0;
    rep(i,1,k){
        if(noo[i]) continue;
        int a=e[i].first,b=e[i].second;
        son[a].emplace_back(b);
        son[b].emplace_back(a);
    }
    rep(i,1,m){
        dfs(i+n,0);
    }
    rep(i,1,n){
        now+=st[i]>0?1:0;
    }
    per(i,t,1){
        int a=e[no[i]].first,b=e[no[i]].second;
        res[i] = now;
        if(st[a]&&st[b]) continue;
        son[a].emplace_back(b);
        son[b].emplace_back(a);
        if(st[a]&&!st[b]){st[b]=1;now+=dfs1(b,0)+1;}
        if(st[b]&&!st[a]){st[a]=1;now+=dfs1(a,0)+1;}
    }
    rep(i,1,t) printf("%d\n",res[i]);
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}