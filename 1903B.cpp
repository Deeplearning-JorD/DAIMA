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
void Solve(){
    int n; cin >> n;
    vector<vector<int>> f(n + 1, vector<int> (n + 1));
    vector<int> a(n + 1);
    rep(i, 1, n){
        vector<int> cnt(30);
        rep(j, 1, n){
            int x; cin >> x;
            for(int k = 0;k < 30;k ++)if(x >> k & 1){
                cnt[k] ++;
            }
            f[i][j] = x;
        }
        for(int j = 0;j < 30;j ++)if(cnt[j] == n - 1) a[i] += 1 << j;
    }
    rep(i, 1, n)rep(j, 1, n)if(i != j && (a[i] | a[j]) != f[i][j]){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    rep(i, 1, n) cout << a[i] << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}