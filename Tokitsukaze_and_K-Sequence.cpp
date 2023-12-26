/*
 * @Author: JorD
 * @LastEditTime: 2023-01-18 16:04:24
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
const int N = 1e5 + 10;
int tr[N << 2], mark[N << 2];
void Solve(){
    int n;
    cin >> n;
    vector<int> a(1e5 + 1), c(1e5 + 2);
    rep(i, 1, n){
        int x; cin >> x;
        a[x] ++;
    }
    sort(all1(a));
    int idx = 1;
    while(idx <= 1e5 && !a[idx]) idx ++;
    int res = 0;
    while(idx <= 1e5 && a[idx] == 1)idx ++, res ++;
    while(idx <= 1e5){
        c[2] ++;
        c[a[idx] + 1] --;
        c[a[idx]] ++;
        c[a[idx] + 1] --;
        idx ++;
    }
    rep(i, 1, n){
        c[i] += c[i - 1];
    }
    rep(i, 1, n){
        res += c[i];
        cout << res << endl;
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