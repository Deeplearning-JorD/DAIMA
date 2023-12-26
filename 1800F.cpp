/*
 * @Author: JorD
 * @LastEditTime: 2023-03-03 21:28:12
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
    vector<int> f(1 << 26);
    vector<int> mask(n + 1);
    vector<string> s(n + 1);
    vector<vector<int>> cnt(n + 1, vector<int> (26));
    for(int i = 1;i <= n;i ++){
        cin >> s[i];
    }
    for(int i = 1;i <= n;i ++){
        for(auto x:s[i]){
            cnt[i][x - 'a'] ++;
        }
        for(int j = 0;j < 26;j ++){
            mask[i] |= (cnt[i][j] & 1) << j;
        }
    }
    ll res = 0;
    for(int i = 0;i < 26;i ++){
        for(int j = 1;j <= n;j ++)if(!cnt[j][i]){
            res += f[(1 << 26) - 1 - (1 << i) - mask[j]];
            f[mask[j]] ++;
        }
        for(int j = 1;j <= n;j ++)if(!cnt[j][i]){
            f[mask[j]] --;
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}