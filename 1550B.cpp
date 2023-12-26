/*
 * @Author: JorD
 * @LastEditTime: 2022-11-24 22:27:32
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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    ll res = n * a;
    s = s[0] + s;
    int idx = 0;
    rep(i, 1, n){
        if(s[i] == s[i - 1]) continue;
        idx ++;
    } 
    idx ++;
    if(b < 0){
        res += (idx / 2 + 1) * b;
    }else res += n * b;
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