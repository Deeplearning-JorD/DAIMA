/*
 * @Author: JorD
 * @LastEditTime: 2022-10-05 13:58:36
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
    string s, c;
    cin >> s >> c;
    int n = s.size(), m = c.size();
    vector<int> a, b;
    a.push_back(0),b.push_back(0);
    for(auto x:s){
        int w = x - '0';
        a.push_back(w);
    }
    for(auto x:c){
        int w = x - '0';
        b.push_back(w);
    }
    vector<vector<int>> f(n + 1, vector<int> (m + 1, -1));
    int cnt = 1e9;
    rep(i, 0, n)
    f[i][0] = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = m;j >= 1;j --){
            if(a[i] == b[j]&&f[i - 1][j - 1] != -1){
                if(j == 1) f[i][j] = i;
                else f[i][j] = f[i - 1][j - 1];
            }else f[i][j] = f[i - 1][j];
        }
        if(f[i][m] != -1) 
        cnt = min(cnt, i - f[i][m] + 1);
    }  
    rep(i, 1, n){
        if(f[i][m] == -1) continue;
        if(i - f[i][m] + 1 == cnt){
            rep(j, f[i][m] - 1, i - 1){
                cout << s[j];
            }
            cout << endl;
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