/*
 * @Author: JorD
 * @LastEditTime: 2023-08-08 12:56:45
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
const int N = 2e5 + 10;
int tr[N];
int lowbit(int x){return x & -x;}
int n;
void add(int i, int x){
    for(;i <= n;i += lowbit(i)) tr[i] += x;
}
int query(int i){
    int res = 0;
    for(;i;i -= lowbit(i)) res += tr[i];
    return x;
}
int a[N];
void Solve(){
    cin >> n;
    ll inv = 0;
    rep(i, 1, n){
        cin >> a[i];
        inv += query(n) - query(a[i]);
        add(a[i], 1);
    }




    // claer
    rep(i, 1, n){
        add(a[i], -1);
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