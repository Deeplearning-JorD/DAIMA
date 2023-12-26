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
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1);
    vector<pair<int,int>> b(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        if(a[i] > k){
            a[i] %= k;
            if(a[i] == 0) a[i] = k;
        }  
        b[i] = {a[i], i};
    }
    sort(b.begin() + 1, b.end(), [](pair<int,int> a, pair<int,int> b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    rep(i, 1, n) cout << b[i].second << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}