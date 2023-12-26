/*
 * @Author: JorD
 * @LastEditTime: 2023-03-29 22:55:27
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
    ll l, r;
    cin >> l >> r;
    string a = to_string(l), b = to_string(r);
    while(a.size() < b.size()) a = '0' + a;
    int res = 10;
    string ans = a;
    auto get = [&](char c){
        if(c != ' ') return c - '0';
        return -1;
    };
    auto gett = [&](char c){
        if(c != ' ') return c - '0';
        return 10;
    };
    auto dfs = [&](auto dfs, int i, int up, int down, int mx, int mi, int zero, string now){
        if(zero){
            mx = 0, mi = 10;
        }else{
            if(mx - mi >= res) return;
        }
        if(i == a.size()){
            ans = now;
            return;
        }
        for(char j = '0';j <= '9';j ++){
            if(down && j < a[i]) continue;
            if(up && j > b[i]) continue;
            dfs(dfs, i + 1, up && j == b[i], down && j == a[i], max(mx, j - '0'), min(mi, j - '0'), zero && j == '0', now + j);
        }
    };
    dfs(dfs, 0, 1, 1, 1, 1, 1, "");
    reverse(all(ans));
    while(ans.back() == '0') ans.pop_back();
    reverse(all(ans));
    cout << ans << endl;
    
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}