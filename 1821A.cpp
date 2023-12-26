/*
 * @Author: JorD
 * @LastEditTime: 2023-04-20 22:39:07
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
    string s;
    cin >> s;
    int cnt = 0;
    for(auto x:s) cnt += x == '?';
    ll res = 0;
    if(s[0] == '0'){
        cout << 0 << endl;
        return;
    }
    if(s[0] == '?'){
        ll now = 1;
        rep(i, 1, cnt - 1) now *= 10;
        cout << now * 9 << endl;
    }else{
        ll now = 1;
        rep(i, 1, cnt) now *= 10;
        cout << now << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}