/*
 * @Author: JorD
 * @LastEditTime: 2022-10-18 22:11:01
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> one, zero;
    s = ' ' + s;
    zero.push_back(0);
    vector<int> dp(n + 1);
    rep(i, 1, n){
        if(s[i] == '1') one.push_back(i);
        else zero.push_back(i);
        dp[i] = s[i] == '1';
    }
    int need = zero.size() - 1;
    rep(i, 1, n){
        if(s[i] == '1'){
            if(dp[i] < need){
                int now = zero[dp[i] + 1] - zero[dp[i]];
                if(i + now <= n && s[i + now] == '1'){
                    dp[i + now] = max(dp[i + now], dp[i] + 1);
                }
            }
        }
    }
    int res = 0, id = 0;
    rep(i, 1, n){
        if(i <= zero[dp[i]] && s[i] == '1'){
            if(dp[i] > res){
                id = i;
                res = dp[i];
            }
        }
    }
    per(i, n - zero[res], 1){
        if(s[id + i] == '1') s[zero[id] + i] = '1'; 
    }
    rep(i, 1, res){
        s[zero[i]] = '1';
    }
    vector<char> ss;
    rep(i, 1, n) ss.push_back(s[i]);
    reverse(ss.begin(), ss.end());
    while(ss.size() > 1&& ss.back() == '0') ss.pop_back();
    reverse(ss.begin(), ss.end());
    for(auto x:ss) cout << x;
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}