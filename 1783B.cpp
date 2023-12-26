/*
 * @Author: JorD
 * @LastEditTime: 2023-01-08 23:21:10
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
    int r = n * n, l = 1;
    vector<vector<int>> f(n + 1, vector<int> (n + 1));
    int idx = 1;
    rep(i, 1, n){
        if(i & 1)
        rep(j, 1, n){
            if(idx){
                f[i][j] = l ++;
            }else f[i][j] = r --;
            idx ^= 1;
        }
        else{
            per(j, n, 1){
                if(idx){
                f[i][j] = l ++;
                }else f[i][j] = r --;
                idx ^= 1;
            }
        }
    }
    auto check = [&](){
        set<int> s;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1}; 
        rep(i, 1, n){
            rep(j ,1, n){
                for(int k = 0;k < 4;k ++){
                    int x = i + dx[k], y = j + dy[k];
                    if(x <= n && y <= n && x >= 1 && y >= 1)
                    s.insert(abs(f[x][y] - f[i][j]));
                }
            }
        }
        cout << (s.size() == (n * n - 1)) << endl;
        // for(auto x:s) cout << x << ' ';
        // cout << s.size() << ' ' << n * n - 1 << ' ' << n << endl;
    };
    // check();
    rep(i, 1, n){
        rep(j, 1, n) cout << f[i][j] << " \n"[j == n];
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    // rep(i , 2, 50){
    //     n = i;
    Solve();//}
    return 0;
}