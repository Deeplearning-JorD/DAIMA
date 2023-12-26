/*
 * @Author: JorD
 * @LastEditTime: 2023-05-07 21:30:27
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
    int n, HP, DPS;
    cin >> n >> HP >> DPS;
    vector<ll> hp(n + 1), dps(n + 1), d(n + 1);
    rep(i, 1, n) cin >> hp[i] >> dps[i] >> d[i];
    int j = 1;
    vector<ll> pre(n + 2);
    rep(i, 1, n){
        int last = max(1ll, i - d[i]);
        pre[last] += dps[i];
        pre[i + 1] += -dps[i];
    }
    rep(i, 1, n) pre[i] += pre[i - 1];
    for(int i = 1;i <= n;i ++){
        ll now = pre[i];
        ll l = (hp[i] + DPS - 1) / DPS;
        ll r = (HP + now - 1) / now;
        if(r <= l){
            if(r != l) cout << i - 1 << endl;
            else cout << i << endl;
            return;
        }
        HP -= l * now;
    }
    cout << n << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}