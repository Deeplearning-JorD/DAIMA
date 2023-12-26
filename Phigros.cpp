/*
 * @Author: JorD
 * @LastEditTime: 2022-10-22 13:02:51
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
    ll n, m;
    cin >> n >> m;
    ll len = 0;
    ll mx = 0;
    double res = 0;
    rep(i, 1, m){
        string s;
        cin >> s;
        if(s == "miss"||s == "bad"){
            // res += 100000.0 * len / n;
            mx = max(mx, len);
            len = 0;
            continue;
        }
        len ++;
        if(s == "good")
        res += 585000.0 / n;
        else res += 900000.0 / n;
    }
    len += n - m;
    mx = max(mx, len);
    res += 900000.0 / n * (n - m);
    res += 100000.0 * mx / n;
    res += 0.5;
    cout << (ll)res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;
    Solve();
    return 0;
}