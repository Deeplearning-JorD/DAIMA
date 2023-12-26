/*
 * @Author: JorD
 * @LastEditTime: 2022-08-15 20:31:01
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
const int N = 3e5+10, M=(1<<21)+10;
ll pre[N];
void Solve(){
    int n;
    read(n);
    vector<vector<ll>> v(M);
    vector<vector<ll>> u(M);
    v[0].push_back(0);
    rep(i,1,n){
        ll now;
        read(now);
        pre[i]=pre[i-1]^now;
        if(i&1)
        u[pre[i]].emplace_back(i);
        else v[pre[i]].emplace_back(i);
    }  
    ll res=0;
    rep(i,0,(1<<21)+4){
        ll n=v[i].size(),m=u[i].size();
        res+=(n-1)*n/2;
        res+=(m-1)*m/2;
    }
    cout<<res<<endl;
    return;
}
int main(){
    Solve();
    return 0;
}