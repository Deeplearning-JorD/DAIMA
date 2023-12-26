/*
 * @Author: JorD
 * @LastEditTime: 2022-12-16 19:31:36
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
    vector<int> a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    vector<bool> st(n + 1);
    int l = 0, w = 0, r = 0;
    function<void(int,int,int,int)> dfs = [&](int deep, int win, int lose, int ji){
        if(deep > n){
            if(win == lose){
                w ++;
                return;
            }
            if(win > lose) l ++;
            else r ++;
            return;
        }
        rep(i, 1, n){
            if(st[i]) continue;
            st[i] = true;
            if(a[deep] == b[i]) dfs(deep + 1, win, lose, ji + 1);
            else if(a[deep] > b[i]) dfs(deep + 1, win + 1, lose, ji);
            else dfs(deep + 1, win, lose + 1, ji);
            st[i] = false;
        }
    };
    dfs(1, 0, 0, 0);
    cout << l << ' ' << r << ' ' << w << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}