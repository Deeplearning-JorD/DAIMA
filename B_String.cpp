/*
 * @Author: JorD
 * @LastEditTime: 2022-12-25 14:19:57
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
    string s;   cin >> s;
    n = s.size();
    s = ' ' + s;
    vector<vector<int>> dp(26, vector<int> (n + 2));
    rep(i, 1, n){
        int x = s[i] - 'a';
        for(int j = 0;j <= 25;j ++){
            if(x <= j) dp[j][i] = j - x;
            else dp[j][i] = 25 - x + j + 1; 
         }
    }
    int res = 1e9;
    rep(o, 0, 25){
        auto &f = dp[o];
        int now = 0;
        for(int j = 1;j <= 26;j ++){
            int w = 0;
            for(int i = 1;i <= n;i ++){
                if(i == 1){
                    if(f[1]) f[1] --, w = 1;
                    continue;
                }
               if(f[i]){
                    f[i] --;
                    if(w){
                        continue;
                    }
                    now += w;
                    w = 1;
                }else{
                    now += w;
                    w = 0;
                }
            }
            now += w;
        }
        res = min(res, now);
    }
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