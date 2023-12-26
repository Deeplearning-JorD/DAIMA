/*
 * @Author: JorD
 * @LastEditTime: 2022-12-07 16:48:08
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
void Solve(){
    int n;
    cin >> n;
    vector<int> len(n + 1);
    map<int,int> q;
    vector<vector<int>> a(n + 1);
    rep(i, 1, n){
        int m;
        cin >> m;
        a[i].resize(m);
        for(auto &x:a[i]){
            cin >> x;
            q[x] = 1;
        }
        len[i] = m;
    }
    int idx = 0;
    for(auto &[x, y]:q){
        y = ++ idx;
    }
    vector<int> num(idx + 1);
    vector<int> up(idx + 1), down(idx + 1);
    for(int i = 1;i <= n; i ++){
        for(auto &x:a[i]){
            x = q[x];
        }
        for(int j = 0;j <= len[i] - 1;j ++){
            if(j) up[a[i][j]] = a[i][j - 1];
            if(j != len[i] - 1) down[a[i][j]] = a[i][j + 1];
        }
    }
    int resl = 0, resr = 0;
    for(int now = idx;now >= 1;now --){
        if(now == idx){
            if(down[now] != 0){
                up[down[now]] = 0;
                down[now] = 0;
                resl ++;
            }
            if(up[now] && up[now] != now - 1){
                down[up[now]] = 0;
                up[now] = 0;
                resl ++;
            }
            continue;
        }
        if(down[now] != now + 1){
            resr ++;
            if(down[now]){
                up[down[now]] = 0;
                down[now] = 0;
                resl ++;
            }
        }
        if(up[now] && up[now] != now - 1){
            down[up[now]] = 0;
            up[now] = 0;
            resl ++;
        }
    }
    cout << resl << ' ' << resr << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}