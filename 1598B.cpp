/*
 * @Author: JorD
 * @LastEditTime: 2022-11-21 15:34:38
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
    vector<vector<int>> f(n + 1, vector<int> (6));
    vector<int> sum(6);
    rep(i, 1, n){
        rep(j, 1, 5){
            cin >> f[i][j];
            sum[j] += f[i][j];
        }
    }
    rep(i, 1, 5){
        rep(j, i + 1, 5){
            if(sum[i] >= n / 2&&sum[j] >= n / 2){
                bool st = true;
                for(int k = 1;k <= n;k ++){
                    if(f[k][i]||f[k][j]) continue;
                    st = false;
                    break;
                }
                if(st){
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}