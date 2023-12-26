/*
 * @Author: JorD
 * @Date: 2023-11-25 15:46:33
 * @LastEditTime: 2023-11-25 15:56:23
 * how to Get
 */
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
const int N = 1010;
char s[N][N];
void Solve(){
    int n; cin >> n;
    for(int i = 1;i <= 2 * n - 1;i ++){
        for(int j = 1;j <= 3 * n - 1;j ++)
            s[i][j] = ' ';
    }
    for(int i = n;i <= 2 * n - 1;i ++) s[1][i] = '*';
    for(int i = 1;i <= n;i ++) s[n][i] = '*';
    for(int i = 2 * n - 1;i <= 3 * n - 2;i ++) s[n][i] = '*';
    auto c1 = [&](int i, int j, int x, int y){
        while(i != x){
            s[i][j] = '*';
            i --; j ++;
        }
    };
    auto c2 = [&](int i, int j, int x, int y){
        while(i != x){
            s[i][j] = '*';
            i --; j --;
        }
    };
    c1(n, 1, 1, n);
    c1(n, n, 1, 2 * n - 1);
    c2(n, 2 * n - 1, 1, n);
    c2(n, 3 * n - 2, 1, 2 * n - 1);
    for(int i = n;i <= 2 * n - 1;i ++) s[n + 1][i] = '*';
    for(int i = n;i <= 2 * n - 1;i ++) s[2 * n - 1][i] = '*';
    for(int i = n + 1;i <= 2 * n - 1;i ++){
        s[i][n] = '*';
        s[i][2 * n - 1] = '*';
    }
    c1(2 * n - 1, n, n + 1, 0);
    for(int i = 1;i <= 2 * n - 1;i ++){
        for(int j = 1;j <= 3 * n - 1;j ++)
            cout << s[i][j];
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