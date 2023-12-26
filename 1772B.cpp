/*
 * @Author: JorD
 * @LastEditTime: 2022-12-18 22:40:35
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
int a[10];
bool check(){
    return a[1] < a[2] && a[1] < a[3] && a[2] < a[4] && a[3] < a[4];
}
void rr(){
    vector<int> now(5);
    now[1] = a[3];
    now[2] = a[1];
    now[3] = a[4];
    now[4] = a[2];
    rep(i, 1, 4) a[i] = now[i]; 
}
void Solve(){
    rep(i, 1, 4) cin >> a[i];
    bool res = check();
    rep(i, 1, 3){
        rr();
        res |= check();
    }
    if(res) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}