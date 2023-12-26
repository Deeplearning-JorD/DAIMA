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
    vector<vector<char>> f(5, vector<char> (5));
    rep(i, 1, 3) rep(j, 1, 3) cin >> f[i][j];
    vector<pair<int,int>> v;
    v.push_back({1, 2});
    v.push_back({3, 2});
    v.push_back({2, 1});
    v.push_back({2, 3});
    v.push_back({2, 2});
    for(auto [i, j]:v){
        if(f[i][j] == '.') continue;
        if(f[i][j] == f[i][j + 1] && f[i][j - 1] == f[i][j]){
            cout << f[i][j] << endl;
            return;
        }
        if(f[i][j] == f[i + 1][j] && f[i][j] == f[i - 1][j]){
            cout << f[i][j] << endl;
            return;
        }
        if(f[i][j] == f[i + 1][j + 1] && f[i - 1][j - 1] == f[i][j]){
            cout << f[i][j] << endl;
            return;
        }
        if(f[i][j] == f[i - 1][j + 1] && f[i + 1][j - 1] == f[i][j]){
            cout << f[i][j] << endl;
            return;
        }
    }
    
    cout << "DRAW\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}