/*
 * @Author: JorD
 * @Date: 2023-11-25 20:34:37
 * @LastEditTime: 2023-11-25 20:42:21
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
const int N = 2e5 + 10;
int a[N], t[N];
void Solve(){
    int n, m;
    cin >> n >> m;
    set<int> s;
    rep(i, 0, n + 1) s.insert(i);
    rep(i, 1, n){
        cin >> a[i];
        if(a[i] > n) continue;
        t[a[i]] ++;
        s.erase(a[i]);
    }
    while(m --){
        int i, x; cin >> i >> x;
        if(a[i] <= n){
            t[a[i]] --;
            if(t[a[i]] == 0) s.insert(a[i]);
        }
        a[i] = x;
        if(a[i] <= n){
            t[a[i]] ++;
            if(t[a[i]]) s.erase(a[i]);
        }
        cout << *s.begin() << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}