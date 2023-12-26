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
    int n; cin >> n;
    vector<vector<char>> f(n + 1, vector<char> (n + 1));
    rep(i, 1, n) rep(j, 1, n) cin >> f[i][j];
    rep(i, 1, n){
        rep(j, 1, n){
            if(i == 1 || i == n || j == 1 || j == n){
                if(i == 1){
                    if(j == 1){
                        cout << f[2][1];
                    }else cout << f[i][j - 1];
                }else if(i == n){
                    if(j == n){
                        cout << f[i - 1][j];
                    }else cout << f[i][j + 1];
                }else if(j == 1){
                    cout << f[i + 1][j];
                }else if(j == n) cout << f[i - 1][j];
            }else cout << f[i][j];
        }
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