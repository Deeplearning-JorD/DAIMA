/*
 * @Author: JorD
 * @LastEditTime: 2023-10-08 18:15:04
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
    int n, m, k; cin >> n >> m >> k;
    if(k == 1){
        cout << 1 << endl;
        return;
    }
    if(k == 2){
        if(m >= n) cout << n - 1 + m / n << endl;
        else cout << m << endl;
        return;
    }
    if(k == 3){
        if(m >= n) cout << max(0, m - m / n - n + 1) << endl;
        else cout << 0 << endl;
        return;
    }
    cout << 0 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}