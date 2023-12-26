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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> f(n + 1, vector<int> (n + 1));
    rep(i, 1, n) rep(j, 1, n) cin >> f[i][j];
    int res = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            int x = n + 1 - i, y = n + 1 - j;
            res += f[i][j] != f[x][y];
        }
    }

    if(res / 2 <= k){
        k -= res / 2;
        if(k % 2 == 0){
            cout << "YES\n";
            return;
        }
        if(n % 2 == 1 && k % 2 == 1)
            cout << "YES\n";
        else cout << "NO\n";
    }else cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}