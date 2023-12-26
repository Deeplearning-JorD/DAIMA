/*
 * @Author: JorD
 * @LastEditTime: 2022-11-19 20:04:10
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    if(k >= n){
        rep(i, 1, n) cout << 0 << ' ';
        return;
    }
    int idx = 1;
    rep(i, k + 1, n) idx ++ ,cout << a[i] << ' ';
    rep(i, idx, n) cout << 0 << ' '; 

    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}