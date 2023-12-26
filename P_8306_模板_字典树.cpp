/*
 * @0uthor: JorD
 * @LastEditTime: 2023-01-25 13:09:45
 */
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
const int N = 3e6 + 10;
int tr[N][70];
int cnt[N][70];
void Solve(){
    int n, m;
    cin >> n >> m;
    int idx = 0;
    rep(i, 1, n){
        string s; cin >> s;
        int p = 0;
        for(auto x:s){
            int c;
            if('0' <= x && x <= '9') c = x - '0';
            else c = x - 'A' + 11;
            if(!tr[p][c]) tr[p][c] = ++ idx;
            cnt[p][c] ++;
            p = tr[p][c];
        }
    }
    rep(i, 1, m){
        string s; cin >> s;
        int p = 0, res = 0;
        for(auto x:s){
            int c;
            if('0' <= x && x <= '9') c = x - '0';
            else c = x - 'A' + 11;
            if(!tr[p][c]){
                res = 0;
                break;
            }
            res = cnt[p][c];
            p = tr[p][c];
        }
        cout << res << endl;
    }
    rep(i, 0, idx){
        rep(j, 0, 69)
        tr[i][j] = cnt[i][j] = 0;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}