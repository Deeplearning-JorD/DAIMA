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
    vector<vector<char>> f(n + 1, vector<char> (m + 1));
    auto g = f;
    rep(i, 0, n - 1) rep(j, 0, m - 1) cin >> f[i][j];
    rep(i, 0, n - 1) rep(j, 0, m - 1) cin >> g[i][j];
    auto change = [&](){
        auto c = g;
        rep(i, 1, n - 1){
            c[i - 1] = g[i];
        }
        c[n - 1] = g[0];
        g = c;
    };
    auto change1 = [&](){
        auto c = g;
        rep(i, 1, m - 1){
            rep(j, 0, n - 1){
                c[j][i - 1] = g[j][i];
            }
        }
        rep(j, 0, n - 1){
            c[j][m - 1] = g[j][0];
        }
        g = c;
    };
    rep(i, 1, n){
        rep(j, 1, m){
            auto gg = g;
            rep(k, 1, i) change();
            rep(k, 1, j) change1();
            bool st = true;
            rep(ii, 0, n - 1){
                if(f[ii] != g[ii]){
                    st = false;
                    break;
                }
            }
            if(st){
                cout << "Yes\n";
                return;
            }
            g = gg;
        }
    }
    cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}