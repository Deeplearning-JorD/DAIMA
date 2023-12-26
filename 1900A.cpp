/*
 * @Author: JorD
 * @Date: 2023-11-26 22:35:15
 * @LastEditTime: 2023-11-26 22:38:45
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
void Solve(){
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0, res = 0, can = 0;
    s = ' ' + s + ' ';
    for(int i = 1;i <= n + 1;i ++){
        if(s[i] != s[i - 1]){
            if(s[i] == '.'){
                cnt = 1;
            }else{
                if(cnt >= 3) can = 1;
                res += min(2, cnt);
                cnt = 0;
            }
        }else{
            if(s[i] == '.') cnt ++;
        }
        // cout << cnt << ' ';
    }
    if(can) cout << 2 << endl;
    else cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}