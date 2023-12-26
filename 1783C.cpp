/*
 * @Author: JorD
 * @LastEditTime: 2023-01-09 05:41:13
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2);
    vector<pair<int,int>> b(n + 1);
    vector<bool> use(1001);
    rep(i, 1, n){
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(all1(b));
    int js = 0;
    ll sum = 0;
    for(int i = 1;i <= n;i ++){
        auto [x, y] = b[i];
        if(sum + x <= m){
            sum += x;
            js ++;
            use[x] = true;
        }
    }
    int mx = 0;
    int res = 1;
    rep(i, 1, js){
        mx = max(mx, b[i].first);
    }
    res = n - js;
    if(m - sum + mx >= a[js + 1] || use[a[js + 1]]){
        res = n - js;
    }else res ++;
    cout << max(1, res) << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}