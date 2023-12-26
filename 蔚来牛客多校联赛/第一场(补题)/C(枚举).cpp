/*
 * @Author: JorD
 * @LastEditTime: 2022-07-27 09:07:00
 */
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
const int N=2e5+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m,k,q;
ll h[N];
struct point{
    int x,y;
}p[N];
struct slope{
    ll x,y;
    bool operator <(const slope &u) const{
        return y*u.x<u.y*x;
    } 
};
int P[N];
void Solve(){
    fill(h+1,h+m+1,n);
	fill(P+1,P+m+1,n+1);
    rep(i,1,k){
        P[p[i].x]=min(P[p[i].x],p[i].y);
    }
    slope L={1ll,INF};
    rep(i,2,m){
        if(L.y!=INF){
            ll x=L.x,y=L.y;
            h[i]=min(h[i],(y*(i-1)-1)/x);
        }
        L=min(L,(slope){i-1,P[i]});
    }   
    slope R={1ll,INF};
    per(i,m-1,1){
        if(R.y!=INF){
            ll x=R.x,y=R.y;
            h[i]=min(h[i],(y*(m-i)-1)/x);
        }
        R=min(R,(slope){m-i,P[i]});
    }
    ll res=0;
    rep(i,1,m){
        h[i]=min(P[i]-1ll,h[i]);
        res+=h[i];
    }cout<<res<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>k>>q;
    rep(i,1,k){
        cin>>p[i].y>>p[i].x;
    }       
    rep(i,1,q){
        int pos,x,y;
        cin>>pos>>x>>y;
        p[pos]={y,x};
        Solve();
    }
    return 0;
}