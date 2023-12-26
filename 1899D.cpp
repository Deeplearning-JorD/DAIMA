#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
void Solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    map<int,vector<int>> s;
    rep(i, 1, n){
        cin >> a[i];
        int x = a[i];
        int cnt = 0;
        while(x % 2 == 0){
            x >>= 1;
            cnt ++;
        }
        s[x].push_back(a[i] - cnt);
    }
    ll res = 0;
    for(auto &[x,u]:s){
        map<int,int> st;
        for(auto y:u){
            st[y] ++;
        }
        for(auto [v, vv]:st){
            res += 1ll * vv * (vv - 1) / 2;
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    // cout << (8<<4);
    Solve();
    return 0;
}