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
    ll n, c; cin >> n >> c;
    vector<ll> a(n + 1), b(n + 1), id(n + 1);
    vector<pair<ll,ll>> w(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        id[i] = i;
        w[i] = {i * c - a[i], i};
    }
    sort(w.begin() + 1, w.end());
    rep(i, 1, n){
        auto [x, j] = w[i];
        if(j != 1){
            if(a[1] >= x){
                a[1] += a[j];
            }else{
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}