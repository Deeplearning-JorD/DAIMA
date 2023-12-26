/*
 * @Author: JorD
 * @LastEditTime: 2022-11-19 21:54:11
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
int pre[310][310][310];
void Solve(){
    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    vector<vector<int>> f(H + 1, vector<int> (W + 1));
    vector<int> col(N + 1, 0);
    rep(i, 1, H){
        rep(j, 1, W){
            cin >> f[i][j];
            col[f[i][j]] ++;
        }  
    }
    rep(i, 1, H){
        rep(j, 1, W){
            rep(SE, 1, N){
                pre[SE][i][j] = pre[SE][i][j - 1] + pre[SE][i - 1][j] - pre[SE][i - 1][j - 1] + (f[i][j] == SE);
            }
        }
    }
    auto js = [&](int x, int y, int sx, int sy, int i){
        return pre[i][sx][sy] - pre[i][x - 1][sy] + pre[i][x - 1][y - 1] - pre[i][sx][y - 1];
    };
    rep(i, 1, H){
        if(i + h - 1 > H) break;
        rep(j, 1, W){
            if(j + w - 1> W) break;
            int res = N;
            rep(SE, 1, N){
                if(js(i, j, i + h - 1, j + w - 1, SE) == col[SE])
                    res --;
            }
            cout << res << ' ';
        }
        cout << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}