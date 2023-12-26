/*
 * @Author: JorD
 * @LastEditTime: 2022-08-20 12:18:31
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
    int n, m; cin >> n >> m;
    vector<pair<int,int>> a(n+1), b(m+1);
    rep(i, 1, n){
        int x; cin >> x;
        a[i] = {x, i};
    }
    rep(i, 1, m){
        int x; cin >> x;
        b[i] = {x, i};
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l = 0, r = a[n] - a[1];
    while(l < r){
        
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}