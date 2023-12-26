/*
 * @Author: JorD
 * @LastEditTime: 2023-02-03 16:54:28
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
const int N = 2e5 + 10, mod = 1e9 + 7;
ll n;
ll get(int x, int y){
    ll i = x - 1;
    ll last = (2 * n - i + 1) * i;
    return last + y;
}
ll dp[N], res;
unordered_map<ll, int> s;
void Solve(){
    int n, m;
    cin >> n >> m;
    while(m --){
        int x, y;
        cin >> x >> y;
        s[get(x, y)] = 1;
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