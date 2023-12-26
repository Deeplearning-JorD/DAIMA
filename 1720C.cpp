/*
 * @Author: JorD
 * @LastEditTime: 2022-08-18 23:23:12
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
    vector<vector<char>> f(n+2, vector<char> (m+2,'1'));
    rep(i, 1, n) rep(j, 1, m) cin >> f[i][j];
    bool st1 = false;
    bool st2 = false;
    int sum = 0;
    rep(i, 1, n){
        rep(j, 1, m){
            if(f[i][j] == '0'){
                if(f[i-1][j] == '0'||f[i][j-1] == '0'||f[i-1][j-1] == '0') st1 = true;
                if(f[i+1][j] == '0'||f[i][j+1] == '0'||f[i+1][j+1] == '0') st1 = true;
                if(f[i+1][j] == '0'||f[i-1][j+1] == '0'||f[i+1][j-1] == '0') st1 = true;
            }
            sum += (f[i][j]=='1');
        }
    }
    if(sum == n*m) st2 = true;
    if(st1){
        cout << sum << endl;
        return;
    }
    if(st2){
        cout << sum - 2 << endl;
    }else{
        if(sum >= 2) cout << sum - 1 << endl;
        else if(sum) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}