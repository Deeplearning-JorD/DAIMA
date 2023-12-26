/*
 * @Author: JorD
 * @LastEditTime: 2022-09-29 22:49:08
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
    int n;
    cin >> n;
    vector<int> d(n + 1);
    vector<ll> a(n + 1);
    rep(i, 1, n){
        cin >> d[i];
    }
    a[1] = d[1];
    rep(i, 2, n){
        a[i] = a[i - 1] + d[i];
        if(a[i - 1] - d[i] >= 0 && a[i] != a[i - 1] - d[i]){
            cout << -1 << endl;
            return;
        }
    }
    rep(i, 1, n){
        cout << a[i] << ' ';
    }cout << endl;
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