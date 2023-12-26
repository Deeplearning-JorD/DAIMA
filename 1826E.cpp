/*
 * @Author: JorD
 * @LastEditTime: 2023-05-06 11:23:57
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
const int N = 5e3 + 10;
ll w[N];
bitset<N> to[N];
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, m) cin >> w[i];
    rep(i, 1, m) to[i].set();
    rep(i, 1, n){
        vector<int> a(m + 2), id(m + 2);
        rep(j, 1, m){
            id[j] = j;
            cin >> a[j];
        }
        sort(id.begin() + 1, id.begin() + m + 1, [&](int i, int j){
            return a[i] < a[j];
        });
        bitset<N> sum;
        sum.set();
        rep(j, 1, m){
            int k = j;
            while(a[id[k]] == a[id[j]]){
                sum[id[k]] = 0;
                k ++;
            }
            rep(ij, j, k - 1)
            to[id[ij]] &= sum;
            j = k - 1;
        }
    }
    vector<ll> dp(m + 1, -1);
    auto dfs = [&](auto self, int now){
        if(dp[now] != -1) return dp[now];
        dp[now] = w[now];
        rep(i, 1, m)if(to[i][now] == 1){
            dp[now] = max(dp[now], self(self, i) + w[now]); 
        }
        return dp[now];
    };
    ll res = 0;
    rep(i, 1, m) res = max(res, dfs(dfs, i));
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}