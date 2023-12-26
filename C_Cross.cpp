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
    rep(i, 1, n){
        rep(j, 1, m){
            cin >> f[i][j];
        }
    }
    vector<int> res(min(n,m) + 1);
    rep(i, 1, n){
        rep(j, 1, m)if(f[i][j] == '#'){
            int k = 0;
            while(i - k >= 1 && i + k <= n && j - k >= 1 && j + k <= m && f[i + k][j + k] == '#'&& f[i - k][j + k] == '#'&& f[i + k][j - k] == '#'&& f[i - k][j - k] == '#') k ++;
            res[k - 1] ++;
        }
    }
    rep(i, 1, min(n, m)) cout << res[i] << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}