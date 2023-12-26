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
    int n; cin >> n;
    map<ll,ll> st;
    rep(i, 1, n){
        ll x; cin >> x;
        st[x] ++;
    }
    int m; cin >> m;
    while(m --){
        ll x, y;
        cin >> x >> y;
        // x ^ 2 - a * x + b = 0 求x的个数
        ll delta = x * x - 4 * y;
        if(delta < 0 || ((ll)(sqrt(delta)) * (ll)(sqrt(delta))) != delta){
            cout << 0 << ' ';
            continue;
        }
        // cout << x << ' ' << y << endl;
        // cout << delta << ' ';
        delta = sqrt(delta);
        // cout << delta << endl;
        // cout << "up:";
        // cout << (y - delta)  << ' ' << y + delta << endl;
        ll res = 0; 
        ll a = (x - delta) / 2;
        ll b = (x + delta) / 2;
        if((x - delta) % 2 == 0){
           
            // DBG(a);
            if(st.count(a) && st.count(x - a)){
                if(a == x - a) res += (st[a] - 1) * (st[a]) / 2;
                else res += st[a] * st[x - a];
            }
        }
        if((x + delta) % 2 == 0){
            // DBG(a);
            if(st.count(b) && st.count(x - b)){
                if(b == x - b) res += (st[b] - 1) * (st[b]) / 2;
                else res += st[b] * st[x - b];
            }
        }
        if(a + b == x && st.count(b) && st.count(x - a)){
            if(b == x - b) res -= (st[b] - 1) * (st[b]) / 2;
            else res -= st[b] * st[x - b];;
        }
        cout << res << ' ';
        // cout << endl;
    }
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