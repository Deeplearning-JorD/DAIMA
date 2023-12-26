/*
 * @Author: JorD
 * @LastEditTime: 2022-09-20 19:53:32
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
void Solve(){
    ll n, x, y;
    cin >> n >> x >> y;
    string s, ss;
    cin >> s >> ss;
    s = ' ' + s;
    ss = ' ' + ss;
    int idx = 0;
    vector<int> a;
    rep(i, 1, n){
        if(s[i] != ss[i]){
            idx ++;
            a.push_back(i);
        }
    }
    if(idx & 1){
        cout << -1 << endl;
        return;
    }
    if(x >= y||idx == 0){
        ll res = 0;
        if(idx == 2){
            if(a[0] == a[1] - 1){
                if(x >= 2 * y){
                    res = 2 * y;
                }else res = x;
            }else res = idx / 2 * y;
        }else res = idx / 2 * y;
        cout << res << endl;
        return;
    }
    vector<ll> f(idx);
    f[0] = y; f[1] = min(2 * y, (a[1] - a[0]) * 2 * x);
    rep(i, 2, idx - 1){
        f[i] = min(f[i - 1] + y, f[i - 2] + 2 * x * (a[i] - a[i - 1]));
    } 
    f[idx - 1] >>= 1;
    cout << f[idx - 1] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}