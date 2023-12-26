/*
 * @Author: JorD
 * @LastEditTime: 2023-01-25 00:54:26
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
const int N = 4e5 + 10;
int tr[N][12];
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(n + 1, vector<int> (m + 1));
    rep(i, 1, n) rep(j, 1, m){cin >> f[i][j];}
    int idx = 0;
    rep(i, 1, n){
        int p = 0;
        rep(j, 1, m){
            rep(k, 1, m){
                if(f[i][k] == j){
                    if(!tr[p][k]) tr[p][k] = ++ idx;
                    p = tr[p][k];
                    break;
                }
            }
        }
    }
    rep(i, 1, n){
        auto &ls = f[i];
        int res = 0, p = 0;
        for(int j = 1;j <= m;j ++){
            if(tr[p][ls[j]]){res = j;p=tr[p][ls[j]];}
            else break;
        }
        cout << res << ' ';
    }
    cout << endl;
    rep(i, 0, idx) rep(j, 1, 10) tr[i][j] = 0;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}