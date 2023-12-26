/*
 * @Author: JorD
 * @LastEditTime: 2023-03-25 20:28:08
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
    string s;
    cin >> s;
    int n = s.size();
    vector<ll> st(n + 1);
    s = ' ' + s;
    vector<int> a(10);
    rep(i, 1, n){
        a[s[i] - '0'] ^= 1;
        for(int j = 0;j < 10;j ++){
            st[i] |= a[j] << j;
        }
    }
    vector<int> dp(1 << 11);
    ll res = 0;
    rep(i, 1, n){
        if(!st[i]) res ++;
        res += dp[st[i]];
        dp[st[i]] ++;
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