/*
 * @Author: JorD
 * @LastEditTime: 2023-07-25 22:48:23
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
    vector<int> a(n + 1);
    vector<int> pre(n + 1), last(n + 2);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) pre[i] = pre[i - 1] + (a[i] == a[1]);
    per(i, n, 1) last[i] = last[i + 1] + (a[i] == a[n]);
    if(a[1] == a[n]){
        if(pre[n] >= k) cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    rep(i, 1, n){
        if(pre[i] >= k && last[i] >= k){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}