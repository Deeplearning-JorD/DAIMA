/*
 * @Author: JorD
 * @LastEditTime: 2022-08-13 12:56:43
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
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
int n, m, p, x, a, b, c;
inline int dfs(){
    ll now =((a*((x*x)%p))%p+(b*x)%p+c)%p;
    now %= p;
    return x = now;
}
void Solve(){
    cin >> n >> m >> p >> x >> a >> b >> c;
    map<int,int> q;
    rep(i, 1, n){
        int now = dfs();
        if(!q[now]) q[now] = i;
    }
    int res=0;
    rep(i, 1, m){
        int now = dfs();
        if(q[now]){
            res=max(res,min(m-i+1,n-q[now]+1));
        }
    }
    cout<<res<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}