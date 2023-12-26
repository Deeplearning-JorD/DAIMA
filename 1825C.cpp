/*
 * @Author: JorD
 * @LastEditTime: 2023-05-08 21:11:49
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
    int n, m;
    cin >> n >> m;
    int cntr = 0, cntl = 0;
    vector<int> st(m + 1);
    vector<int> v;
    rep(i, 1, n){
        int x; cin >> x;
        if(x == -1) cntl ++;
        else if(x == -2) cntr ++;
        else{
            st[x] |= 1;
            v.push_back(x);
        }
    }
    rep(i, 1, m) st[i] += st[i - 1];
    int res = 0;
    auto check = [&](int be){
        int ans = 1;
        ans += min(m - be, cntr + st[m] - st[be]);
        ans += min(be - 1, cntl + st[be - 1]);
        res = max(ans, res);
    };
    for(auto x:v){
        check(x);
    }
    if(cntl){
        cntl --;
        check(m);
        cntl ++;
    }
    if(cntr){
        cntr --;
        check(1);
        cntr ++;
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