/*
 * @Author: JorD
 * @LastEditTime: 2022-07-28 16:32:45
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define double long double
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
const int N=2e3+10;
struct node{
    int x;
    double w;
};
vector<node> son[N];
int n,m;
int st[N];
double mul[N];
int dist[N];
bool flag;
inline void dfs(int now,double w){
    if(!flag) return;
    st[now]=1;
    //取log判负环，不取log判正环。
    for(auto u:son[now]){
        if(mul[u.x]<mul[now]*w*u.w){
            mul[u.x]=mul[now]*w*u.w;
            if(st[u.x]==1){
                flag=false;
                return;
            }
            dfs(u.x,w);
            if(!flag) return;
        }
    }
    st[now]=2;
}
inline bool check(double mid){
    flag=true;
    fill(st+1,st+1+n,0);
    fill(mul+1,mul+1+n,1.0);
    rep(i,1,n){
        if(!flag) return false;
        if(st[i]) continue;
        dfs(i,mid);
    }
    return flag;
}
void Solve(){
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        son[b].push_back({d,1.0*c/a});
    }
    double l=0,r=1.0;
    while(r-l>1e-8){
        double mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<SPO(8)<<l;
    return;
}
int main(){
    Solve();
    return 0;
}