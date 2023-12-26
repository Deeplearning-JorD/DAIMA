#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N=1e5+10;
int h[N],ph[N],hp[N],cnt,mm;
int q[N],mp[N]; 
void jh(int x,int y){
    swap(mp[x],mp[y]);
    swap(h[x],h[y]);
}
void down(int t){
    int u=t;
    if(t*2<=cnt&&q[h[t*2]]<q[h[u]])   u=2*t;
    if(t*2+1<=cnt&&q[h[t*2+1]]<q[h[u]]) u=2*t+1;
    if(u!=t){
        jh(u,t);
        down(u);
    }
}
void up(int t){
    while(t/2&&q[h[t/2]]>q[h[t]]){
        jh(t,t/2);
        t/=2;
    }
}
void inerst(int x){
    ++cnt;
    h[cnt]=x;
    if(!mp[x])
    mp[x]=cnt;
    up(cnt);
}
void midofy(int x){
    int qq=mp[x];
    up(qq);
    down(qq);
}
void Solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    int now=0;
    rep(i,1,n) inerst(i);
    rep(i,1,m){
        int x;
        scanf("%d",&x);
        q[x]++;
        midofy(x);
        if(q[h[1]]>now){
            printf("1");
            now++;
        }
        else printf("0");
    }
    return;
}
int main(){
    Solve();
    return 0;
}