/*
 * @Author: JorD
 * @LastEditTime: 2022-10-08 20:24:11
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(n + 1, vector<int> (n + 1));
    while(m --){
        int mm;
        cin >> mm;
        vector<int> q;
        rep(i, 1, mm ){
            int x;
            cin >> x;
            q.push_back(x);
        }
        for(auto x:q){
            for(auto y:q){
                if(x == y) continue;
                // cout << x << ' ' << y << endl;
                f[x][y] = f[y][x] = 1;
            }
        }
    }
    rep(i, 1, n){
        rep(j, 1, n){
            if(i == j) continue;
            if(!f[i][j]||!f[j][i]){
                // cout << i << ' ' << j << endl;
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}