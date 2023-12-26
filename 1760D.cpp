/*
 * @Author: JorD
 * @LastEditTime: 2022-11-22 00:21:50
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
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<int> b = a;
    sort(a.begin() + 1, a.end());
    if(b == a){
        cout << "YES\n";
        return;
    }
    reverse(a.begin() + 1, a.end());
    if(b == a){
        cout << "YES\n";
        return;
    }
    int id, mx = 2e9;
    rep(i, 1, n) if(b[i] < mx) id = i, mx = b[i];
    // cout << id << ' ' << mx << endl;
    per(i, id - 1, 1){
        if(b[i] < b[i + 1]){
            cout << "NO\n";
            return;
        }
    }
    rep(i, id + 1, n){
        if(b[i] < b[i - 1]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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