/*
 * @Author: JorD
 * @LastEditTime: 2022-11-05 12:07:23
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
    int be = 0;
    vector<int> a(n + 1), b(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        if(!be) be = a[i];
        b[i] = a[i];
    }
    sort(a.begin() + 1, a.end());
    if(be != a[1]){
        int now = 1e9;
        rep(i, 2, n){
            now = min(now, b[i]);
        }
        if(now + 1 <= be){
            cout << "Alice\n";
        }else cout << "Bob\n";
    }else if(be == a[1]){
        cout << "Bob\n";
    }
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