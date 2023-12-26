/*
 * @Author: JorD
 * @LastEditTime: 2023-04-30 19:27:58
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int res = 0;
    vector<int> cnt(n + 1);
    rep(i, 1, n) cnt[a[i]] ++;
    rep(i, 1, n){
        int now = a[i];
        int j = i + 1;
        while(j <= n && now + a[j] <= n){
            now += a[j];
            res += cnt[now];
            cnt[now] = 0;
            j ++;
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