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
const int N = 510;
ll f[N][N];
void Solve(){
    int n, m;
    cin >> n >> m;
    cout << n * m << endl;
    rep(i, 1, n){
        rep(j, 1, m){
            cout << f[i][j] << ' ';
        }cout << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll idx = 0;
    for(int i = 1;i <= (1 << 8);i += 2){
        for(int j = 1;j <= (1 << 8);j += 2){
            f[i][j] = idx ++;
            f[i][j + 1] = idx ++;
            f[i + 1][j] = idx ++;
            f[i + 1][j + 1] = idx ++;
        }
    }
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}