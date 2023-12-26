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
    vector<vector<int>> res(n + 1, vector<int> (m + 1));
    vector<int> h(n + 1), l(m + 1);
    vector<int> h1(n + 1), l1(m + 1);
    rep(i, 1, n){
        rep(j, 1, m){
            cin >> f[i][j];
            if(f[i][j] == 0){
                h[i] = 1;
                l[j] = 1;
            }
        }
    }
    rep(i, 1, n){
        rep(j, 1, m){
            if(h[i] || l[j]) continue;
            res[i][j] = 1;
        }
    }
    rep(i, 1, n){
        rep(j, 1, m){
            if(res[i][j]) h1[i] = 1;
        }
    }
    rep(j, 1, m){
        rep(i, 1, n){
            if(res[i][j]) l1[j] = 1;
        }
    }
    rep(i, 1, n){
        rep(j, 1, m){
            if(f[i][j]&&(!h1[i] && !l1[j])){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    rep(i, 1, n){
        rep(j, 1, m) cout << res[i][j] << ' ';
        cout << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}