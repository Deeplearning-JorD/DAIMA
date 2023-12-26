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
void Solve(){
    ll n, P, Q, R;
    cin >> n >> P >> Q >> R;
    vector<ll> pre(n + 1);
    vector<ll> a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    rep(i, 1, n){
        ll t = lower_bound(pre.begin(), pre.end(), P + Q + R + pre[i - 1]) - pre.begin();
        ll x = i, y, z, w;
        if(pre[t] - pre[i - 1] == P + Q + R){
            w = t + 1;
            t = lower_bound(pre.begin(), pre.end(), P + pre[i - 1]) - pre.begin();
            if(pre[t] - pre[i - 1] == P){
                y = t + 1;
                t = lower_bound(pre.begin(), pre.end(), Q + pre[y - 1]) - pre.begin();
                if(pre[t] - pre[y - 1] == Q){
                    z = t + 1;
                    t = lower_bound(pre.begin(), pre.end(), R + pre[z - 1]) - pre.begin();
                    if(pre[t] - pre[z - 1] == R){
                        cout << "Yes" << endl;
                        return;
                    }
                }
                
            }
        }
    }
    cout << "No" << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}