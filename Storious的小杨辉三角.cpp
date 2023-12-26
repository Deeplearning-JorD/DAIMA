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
int a[100][100];
void Solve(){
    int n; cin >> n;
    a[1][1] = 1;
    rep(i, 2, n){
        for(int j = 1;j <= i;j ++){
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    rep(i, 1, n) cout << a[n][i];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}