/*
 * @Author: JorD
 * @LastEditTime: 2023-02-02 00:17:34
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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> pos(n + 1);
    rep(i, 1, n){
        int x; cin >> x; 
        pos[x] = i;
    }
    vector<int> a(n + 1);
    rep(i, 1, m){
        int x; cin >> x;
        a[i] = pos[x];
    }
    int res = 1e9;
    rep(i, 2, m){
        if(a[i] < a[i - 1] || a[i] > a[i - 1] + d) res = 0;
        else{
            res = min(res, a[i] - a[i - 1]);
            if(d + 1 < n) res = min(res, d + 1 - (a[i] - a[i - 1]));
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}