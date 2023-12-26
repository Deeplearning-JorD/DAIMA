/*
 * @Author: JorD
 * @LastEditTime: 2022-12-19 03:39:09
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
const int N = 35;
struct node{
    ll id, l, r;
};
void Solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<vector<char>>> f(k + 2, vector<vector<char>> (n + 1, vector<char> (m + 1)));
    vector<PII> q(k + 2);
    set<pair<int,int>> s;
    rep(o, 1, k + 1){
        rep(i, 1, n){
            rep(j, 1, m)
                cin >> f[o][i][j];
        }
    }
    rep(o, 1, k + 1){
        rep(i, 1, n) rep(j, 1, m){
            if(i == 1||i == n||j == 1 ||j == m) continue;
            int cnt = 0;
            auto &g = f[o];
            char now = g[i][j];
            if(now != g[i + 1][j]) cnt ++;
            if(now != g[i - 1][j]) cnt ++;
            if(now != g[i][j + 1]) cnt ++;
            if(now != g[i][j - 1]) cnt ++;
            if(cnt == 4){
                s.insert({i, j});
            }
        }
    }
    rep(o, 1, k + 1){
        auto &g = f[o];
        int cnt = 0;
        for(auto [x, y]:s){
            if(g[x][y] == g[x + 1][y]) cnt ++;
        }
        q[o] = {o, cnt};
    }
    sort(q.begin() + 1, q.end(), [](PII &a, PII &b){
        return a.second < b.second;
    });
    int last = q[1].first;
    cout << last << endl;
    vector<node> res;
    rep(o, 2, k + 1){
        auto &g = f[last];
        auto &ji = f[q[o].first];
        rep(i, 1, n)
        rep(j, 1, m){
            if(g[i][j] != ji[i][j])
                res.push_back((node){1, i, j});
        }
        last = q[o].first;
        res.push_back((node){2, last, 0});
    }
    cout << res.size() << endl;
    for(auto [x, y, z]:res){
        if(x == 1) cout << x << ' ' << y << ' ' << z << endl;
        else cout << x << ' ' << y << endl;
    }
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}