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
    int n; cin >> n;
    vector<ll> h(n + 1, 1e9);
    rep(i, 1, n){
        int x; cin >> x;
        for(ll j = 0, now = 0;(now = j * j + x) <= n;j ++){
            if(i + j <= n) h[i + j] = min(h[i + j], now);
            if(i - j > 0) h[i - j] = min(h[i - j], now);
        }
    }
    int m;
    cin >> m;
    while(m --){
        int op;
        cin >> op;
        if(!op){
            int i, x; cin >> i >> x;
            for(ll j = 0, now = 0;(now = j * j + x) <= n;j ++){
                if(i + j <= n) h[i + j] = min(h[i + j], now);
                if(i - j > 0) h[i - j] = min(h[i - j], now);
            }
        }else{int x;cin>>x;cout<<h[x]<<endl;}
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}