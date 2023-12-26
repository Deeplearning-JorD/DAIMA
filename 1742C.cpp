/*
 * @Author: JorD
 * @LastEditTime: 2022-10-13 23:03:48
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
    vector<vector<char>> f(9, vector<char> (9));
    rep(i, 1, 8){
        rep(j, 1, 8)
            cin >> f[i][j];
    }
    rep(i, 1, 8){
        bool st = true;
        rep(j, 1, 8){
            if(f[i][j] != 'R'){
                st = false;
                break;
            }
        }
        if(st){
            cout << f[i][1] << endl;
            return;
        }
        st = true;
        rep(j, 1, 8){
            if(f[j][i] != 'B'){
                st = false;
                break;
            }
        }
        if(st){
            cout << f[1][i] << endl;
            return;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}