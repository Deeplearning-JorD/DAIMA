/*
 * @Author: JorD
 * @LastEditTime: 2022-07-30 17:59:17
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
const ll mod=998244353;
ll res,sum,n,q;
ll qsm(ll a,ll k,ll p){
    ll res=1%p;
    while(k){
        if(k&1) res=res*a%p;
        a=a*a%p;
        k>>=1;
    }
    return res;
}
struct node{
    ll iq,eq,aq;
}last[11];
ll f[11][410][410];
vector<node> w[11];
ll seed;
std::uniform_int_distribution<> u(1,400);
ll solve(int a,int b,int c){
    ll now=0;
    rep(i,1,n){
        now+=f[i][a][b]<=c;
    }
    return now;
}
void Solve(){
    cin>>n>>q;
    memset(f,0x3f,sizeof f);
    rep(i,1,n){
        ll m;
        cin>>m;
        rep(j,1,m){
            ll a,b,c;
            cin>>a>>b>>c;
            f[i][a][b]=min(f[i][a][b],c);
        }
        rep(j,1,400){
            rep(k,1,400){
                f[i][j][k]=min(f[i][j][k],f[i][j][k-1]);
                f[i][j][k]=min(f[i][j-1][k],f[i][j][k]);
            }
        }
    }
    cin>>seed;
    std::mt19937 rng(seed);
    ll lastans=0;
    for (int i=1;i<=q;i++){
        ll IQ=(u(rng)^lastans)%400+1;  // The IQ of the i-th friend
        ll EQ=(u(rng)^lastans)%400+1;  // The EQ of the i-th friend
        ll AQ=(u(rng)^lastans)%400+1;  // The AQ of the i-th friend
        lastans=solve(IQ,EQ,AQ);
        res=(res+lastans*qsm(seed,q-i,mod))%mod; 
    }
    cout<<res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    cout<<147%3;
    return 0;
}