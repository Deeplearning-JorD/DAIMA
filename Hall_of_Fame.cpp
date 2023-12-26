/*
 * @Author: JorD
 * @LastEditTime: 2023-01-03 22:44:53
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
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for(auto x:s){
        if(x == 'L') cnt1 = 1;
        else cnt2 = 1;
    }
    if(!cnt1 || !cnt2){
        cout << -1 << endl;
        return;
    }
    vector<bool> st(n + 1);
    s = ' ' + s;
    int res = 0;
    rep(i, 2, n){
        if(s[i - 1] == 'L' && s[i] == 'R'){
            res = i - 1;
            swap(s[i - 1], s[i]);
            break;
        }
    }
    int v = 0;
    for(int i = 1;i <= n;i ++){
        if(v) st[i] = true;
        if(s[i] == 'R') v = 1;
    }
    v = 0;
    for(int i = n;i >= 1;i --){
        if(v) st[i] = true;
        if(s[i] == 'L') v = 1;
    }
    for(int i = 1;i <= n;i ++){
        if(!st[i]){
            cout << -1 << endl;
            return;
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