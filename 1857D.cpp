/*
 * @Author: JorD
 * @LastEditTime: 2023-08-07 23:49:40
 * how to Get
 */
#pragma GCC optimize(2)
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
    int n; cin >> n;
    vector<ll> a(n + 1), b(n + 1), c(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    vector<int> id(n + 1);
    rep(i, 1, n){
        id[i] = i;
        c[i] = a[i] - b[i];
    }
    sort(id.begin() + 1, id.end(), [&](int i, int j){
        return c[i] > c[j];
    });
    int mx = c[id[1]];
    int cnt = 0;
    vector<int> ls; 
    for(int i = 1;i <= n;i ++){
        if(c[id[i]] != mx) break;
        ls.push_back(id[i]);
        cnt ++;
    }
    sort(ls.begin(), ls.end());
    cout << cnt << endl;
    for(auto x:ls) cout << x << ' ';
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