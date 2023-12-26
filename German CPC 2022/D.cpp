/*
 * @Author: JorD
 * @LastEditTime: 2022-12-04 14:03:24
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
    rep(i, 1, 42){
        cout << "? " << (1ll << i) - 1 << endl;
        ll x; cin >> x;
        ll now = (1ll << i) - 1;
        if(x != now){
            cout << "! " << now - x << endl;
            return;
        }
    }
    return;
 }
 int main(){
    Solve();
    return 0;
 }