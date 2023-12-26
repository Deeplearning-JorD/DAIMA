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
    vector<vector<int>> son(33);
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        for(int j = 0;j <= 30;j ++){
            if(a[i] >> j & 1){
                son[j].push_back(i);
                break;
            }
        }
    }
    while(q --){
        int i; cin >> i;
        int j = i - 1;
        for(;i <= 30;i ++){
            for(auto x:son[i]){
                son[j].push_back(x);
                a[x] += 1 << j;
            }
            son[i].clear();
        }
    }
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