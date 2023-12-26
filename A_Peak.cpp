/*
 * @Author: JorD
 * @LastEditTime: 2022-11-25 19:20:03
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(n + 1, vector<int> (m + 1));
    int idx = n * m;
    for(int i = 1;i <= n;i += 2){
        for(int j = 1;j <= m;j += 2){
            f[i][j] = idx --;
        }
    }
    cout << 1 << ' ' << n * m - idx << endl;
    int cnt = 0;
    rep(i, 1, n) rep(j, 1, m) cout << ++ cnt << " \n"[j == m]; 
    rep(i, 1, n) rep(j, 1, m) if(f[i][j]) cout << f[i][j] << " \n"[j == m];
    else cout << idx -- << " \n"[j == m];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}