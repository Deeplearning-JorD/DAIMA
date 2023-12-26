/*
 * @Author: JorD
 * @LastEditTime: 2023-03-02 23:31:46
 */
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
    int n;
    cin >> n;
    ll res = 0;
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    priority_queue<ll> q;
    int idx = 0, js = 0;
    multiset<ll> s;
    per(i, n, 1){
        ll x = a[i];
        if(x == 0){
            s.insert(0);
        }else{
            if(s.empty()) continue;
            auto now = *s.begin();
            if(now < x){
                s.erase(s.find(now));
                s.insert(x);
            }
        }
    }
    for(auto x:s) res += x;
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}