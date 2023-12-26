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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void Solve(){
    int n; cin >> n;
    vector<vector<char>> f(n + 1, vector<char> (n + 1));
    vector<vector<int>> st(n + 1, vector<int> (n + 1));
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j < n;j ++) cin >> f[i][j];
    }
    int res = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j < n;j ++)if(!st[i][j] && f[i][j] == '*'){
            queue<pair<int,int>> q;
            q.push({i, j});
            st[i][j] = 1;
            res ++;
            while(q.size()){
                auto [x, y] = q.front(); q.pop();
                for(int k = 0;k < 4;k ++){
                    int sx = x + dx[k], sy = n + y + dy[k];
                    sy %= n;
                    if(sx < 1 || sx > n || st[sx][sy] || f[sx][sy] == '.') continue;
                    q.push({sx, sy});
                    st[sx][sy] = 1;
                }
            }
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}