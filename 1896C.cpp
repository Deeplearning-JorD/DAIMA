/*
 * @Author: JorD
 * @Date: 2023-11-25 23:23:05
 * @LastEditTime: 2023-11-25 23:32:02
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
void Solve(){
    int n, x; cin >> n >> x;
    vector<pair<int,int>> a(n + 1), b(n + 1);
    rep(i, 1, n){
        int x; cin >> x;
        a[i] = {x, i};
    }
    rep(i, 1, n){
        int x; cin >> x;
        b[i] = {x, i};
    }
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    vector<int> res(n + 1);
    for(int i = n, j = x;i >= n - x + 1;i --, j --){
        if(a[i].first <= b[j].first){
            cout << "NO\n";
            return;
        }
        res[a[i].second] = b[j].first;
    }
    for(int i = n - x, j = n;i >= 1;i --, j --){
        if(b[j].first < a[i].first){
            cout << "NO\n";
            return;
        }
        res[a[i].second] = b[j].first;
    }
    cout << "YES\n";
    rep(i, 1, n) cout << res[i] << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}