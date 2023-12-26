/*
 * @Author: JorD
 * @LastEditTime: 2022-08-31 00:12:01
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
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
ll lowbit(ll x){
    return x&-x;
}
struct node{
    ll x, y;
};
void Solve(){
    int n, t;
    cin >> n >> t;
    vector<vector<ll>> tr(1100, vector<ll> (1100));
    auto add = [&](ll a, ll b, ll x){
        for(int i=a;i<=1000;i+=lowbit(i))
            for(int j=b;j<=1000;j+=lowbit(j))
                tr[i][j]+=x;
    };
    auto sum = [&](ll x,ll y){
        ll ans=0;
        for(int i=x;i;i-=lowbit(i))
            for(int j=y;j;j-=lowbit(j))
                ans+=tr[i][j];
        return ans;
    };
    rep(i, 1, n){
        ll x, y;
        cin >> x >> y;
        add(x, y, x*y);
    }
    while(t--){
        // ll x, y, sx, sy;
        // cin >> x >> y >> sx >> sy;
        // // cout << sum(sx , sy) - sum(x + 1, y + 1) - sum(sx, sy - 1) - sum(sx - 1, sy) + 2 * sum(sx - 1, sy - 1) << endl;
        // cout << sum(sx - 1 , sy - 1) - sum(x , y ) << endl;
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x2 -- , y2 --;
        x1 ++ , y1 ++;
        cout<<sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1)<<endl;
    }
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