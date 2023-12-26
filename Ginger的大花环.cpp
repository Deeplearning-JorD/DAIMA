/*
 * @Author: JorD
 * @LastEditTime: 2022-12-16 20:07:24
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
    int n, k;
    cin >> n >> k;
    if(k == 1){
        cout << "Ginger666\n";
        return;
    }
    vector<int> w(k + 1);
    rep(i, 1, k) cin >> w[i];
    sort(all1(w));
    ll res = 1ll * (n / 3) * (w[1] + w[1] + w[2]);
    if(n % 3 == 0){
        cout << res << endl;
    }else if(n % 3 == 1){
        cout << res + w[2] << endl;
    }else cout << res + w[2] + w[1] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}