/*
 * @Author: JorD
 * @LastEditTime: 2023-04-18 19:35:08
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
ll calc(int x){
    ll sum = 0;
    for(int i = 1;i <= x / i;i ++){
        if(x % i == 0){
            if(i == x / i){
                if(x != i) sum += i;
                continue;
            }
            if(i != x) sum += i;
            if(x / i != x) sum += x / i;
        }
    }
    return sum;
}
void Solve(){
    int n;
    cin >> n;
    vector<ll> dp(n + 1);
    // dp[i]表示选取的和不超过i的数中，使得所有约数之和最大。
    for(int i = 0;i <= n;i ++){
        for(int j = i;j <= n;j ++){
            dp[j] = max(dp[j], dp[i] + calc(j - i));
        }
    }
    ll res = 0;
    rep(i, 1, n) 
    res = max(res, dp[i]);
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