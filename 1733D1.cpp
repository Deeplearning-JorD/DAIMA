/*
 * @Author: JorD
 * @LastEditTime: 2022-09-20 00:35:31
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
    int idx = 0;
    string s, ss;
    cin >> s >> ss;
    s = ' ' + s;
    ss = ' ' + ss;
    vector<int> a;
    rep(i, 1, n){
        idx += (s[i] != ss[i]);
        if(s[i] != ss[i]){
            a.push_back(i);
        }
    }
    if(idx & 1){
        cout << -1 << endl;
        return;
    }
    ll res = 0;
    if(idx == 2){
        if(a[0] == a[1] - 1){
            if(x >= 2 * y){
                res += 2 * y;
            }else res += x;
        }else res += idx / 2 * y;
    }else res += idx / 2 * y;
    cout << res << endl;
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