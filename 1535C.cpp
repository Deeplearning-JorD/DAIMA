/*
 * @Author: JorD
 * @LastEditTime: 2023-01-04 21:14:37
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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector<ll> dp(n + 1);
    int last = 1, len = 0;
    rep(i, 1, n){
        if(s[i] != '?' && s[i] == s[i - 1]) last = i;
        if(s[i] == '?'){
            len ++;
            dp[i] = dp[i - 1] + i - last + 1;
        }else{
            if(s[i - len - 1] == s[i]){
                if(len & 1){
                    dp[i] = dp[i - 1] + i - last + 1;
                }else{
                    dp[i] = dp[i - 1] + len + 1;
                    last = max(last, i - len);
                }
            }else{
                if(len & 1){
                    dp[i] = dp[i - 1] + len + 1;
                    last = max(last, i - len);
                }else{
                    dp[i] = dp[i - 1] + i - last + 1;
                }
            }
            len = 0;
        }
    }
    cout << dp[n] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}