/*
 * @Author: JorD
 * @LastEditTime: 2022-09-09 19:48:21
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
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> f(n + 1, vector<int> (n + 1, -1));
    s = ' ' + s;
    function<int(int,int)> dfs = [&](int l, int r) -> int{
        if(f[l][r] != -1) return f[l][r];
        if(l + 1 == r) return s[l] != s[r];
        int w = 0;
        if((dfs(l + 2, r)||s[l] < s[l + 1])&&(dfs(l + 1, r - 1)||s[l] < s[r])) w = 1;
        if((dfs(l, r - 2)||s[r] < s[r - 1])&&(dfs(l + 1, r - 1)||s[r] < s[l])) w = 1;
        f[l][r] = w;
        return f[l][r];
    };
    int res = dfs(1, n);
    if(res) cout << "Alice" << endl;
    else cout << "Draw" << endl;
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