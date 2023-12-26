#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    ll n, p; cin >> n >> p;
    vector<ll> a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    vector<int> id;
    rep(i, 1, n){
        if(b[i] < p) id.push_back(i);
    }
    sort(id.begin(), id.end(), [&](int i, int j){
        if(b[i] == b[j]) return a[i] > a[j];
        return b[i] < b[j];
    });
    ll res = n * p, now = 0, can = 0, w = p;
    ll sum = 0, up = 0;
    int j = 0;
    for(int i = 0;i < id.size();i ++){
        int x = id[i];
        if(up - 1 < i){
            now += p;
            up ++;
        }
        ll c = min(n - up, a[x]);
        if(c >= 0){
            now += c * b[x];
            up += c;
        }
    }
    now += max(0ll, n - up) * p;
    cout << now << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}