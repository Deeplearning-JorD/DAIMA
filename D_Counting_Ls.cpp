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
    vector<vector<char>> f(n + 1, vector<char> (n + 1));
    vector<vector<int>> pre(n + 1, vector<int> (n + 1));
    rep(i, 1, n){
        rep(j, 1, n){
            cin >> f[i][j];
            pre[i][j] = f[i][j] == 'o';
        }
    }
    vector<int> lie(n + 1), h(n + 1);
    rep(i, 1, n){
        rep(j, 1, n){
            h[i] += pre[i][j];
            lie[j] += pre[i][j];
        }
    }
    ll res = 0;
    rep(i, 1, n){
        rep(j, 1, n)if(f[i][j] == 'o' && lie[j] >= 2 && h[i] >= 2){
            lie[j] --; h[i] --;
            res += 1ll * lie[j] * h[i];
            lie[j] ++; h[i] ++;
        }
    }
    cout << res << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}