/*
 * @Author: JorD
 * @LastEditTime: 2023-03-30 20:47:55
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
const int N = 2e6 + 10;
const ll inf = -(ll)1e18;
ll ans[N], w[N], dp[N], q[N]; 
void Solve(){
    int n, m, p;
    cin >> n >> m >> p;
    rep(i, 1, n){
        cin >> w[i];
        ans[i] = inf;
    }
    while(m --){
        int a; cin >> a;
        if(a > p){
            cout << "Noob\n";
            continue;
        }
        if(ans[a] != inf){
            cout << ans[a] << endl;
            continue;
        }
        dp[0] = 0;
        ll hh = 1, tt = 1;
        q[1] = 0;
        for(int i = a;i <= n;i += a){
            while(hh <= tt && q[hh] < i - p) hh ++;
            dp[i] = dp[q[hh]] + w[i];
            if(i + p > n) ans[a] = max(ans[a], dp[i]);
            while(hh <= tt && dp[q[tt]] <= dp[i]) tt --;
            q[++ tt] = i;
        }
        cout << ans[a] << endl; 
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