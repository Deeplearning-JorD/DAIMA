/*
 * @Author: JorD
 * @LastEditTime: 2023-08-02 19:11:42
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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n, k;
    cin >> n >> k;
    vector<int> st(5);
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int i = 0, j = 1, res = 1e9;
    while(i <= n){
        st[a[i ++]] --;
        while(j <= n && (st[4] < k || st[1] <= 0 || st[2] <= 0 || st[3] <= 0)){
            st[a[j]] ++;
            j ++;
        }
        if(st[4] >= k && st[1] && st[2] && st[3]) res = min(res, j - i);
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}