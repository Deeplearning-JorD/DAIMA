/*
 * @Author: JorD
 * @LastEditTime: 2023-05-24 23:31:35
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
    int k; cin >> k;
    vector<int> a(k);
    for(auto &x : a) cin >> x;
    int n, m, x; cin >> n >> m >> x;
    vector<int> b(n + 1);
    b[0] = x;
    for(int i = 1;i <= n;i ++){
        b[i] = (b[i - 1] + a[(i - 1)%k]) % m;
    }
    rep(i, 0, n){
        cout << b[i] << ' ';
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