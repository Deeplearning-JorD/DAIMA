/*
 * @Author: JorD
 * @LastEditTime: 2022-08-09 20:34:20
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
const ll INF = 1e18;
const int N=2e6+10;
struct node{
  ll idx,w;
};
int d[N];
void Solve(){
    ll n,m;
    cin >> n >> m;
    vector<node> v;
    vector<ll> x(n+2),p(n+2);
    rep(i,1,n){
        cin >> x[i] >> p[i];
        v.push_back({x[i] - p[i] + 1, 1});
        v.push_back({x[i] + 1, -2});
        v.push_back({x[i] + p[i] + 1, 1});
    }
    v.push_back({-INF, 0ll});
    v.push_back({INF ,0ll});
    sort(v.begin(), v.end(),[](node &x,node &y){
        return x.idx < y.idx;
    });
    // 在idx,降雨量为sum的地方考虑,xi和pi对其的影响
    // xi-pi+1>=idx||xi+pi+1<=idx 没有影响
    // 如果有影响p-abs(xi-idx)
    // 现在是拿走xipi的影响
    // 所以拿走之后的贡献为sum-p+abs(xi-idx)<=m;
    // sum+idx-m<=p+xi
    // xi-p<=m+idx-sum
    ll maxn=-INF,minn=INF,pre=0;
    auto update = [&](ll idx,ll sum){
        if(sum<=m) return;
        maxn = max(maxn, sum + idx - m);
        minn = min(minn, m + idx - sum);
    };
    for (int i = 1; i < v.size() - 1; i++){
        d[i] = d[i-1] + v[i].w;
        if(v[i].idx != v[i+1].idx){
            update(v[i].idx, d[i] + pre);
            update(v[i+1].idx-1, pre + d[i]*(v[i+1].idx - v[i].idx));
        }
        pre += d[i] * (v[i+1].idx - v[i].idx);
    }
    rep(i, 1, n){
        if((x[i] - p[i]) <= minn&&maxn<= (p[i] + x[i])) cout<<1;
        else cout<<0;
    }cout<<endl;
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