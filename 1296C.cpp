/*
 * @Author: JorD
 * @LastEditTime: 2023-05-01 18:09:44
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
    s = ' ' + s;
    int x = 0, y = 0;
    int l = 0, r = 0;
    int res = 1e9;
    map<pair<int,int>,int> q;
    q[{0, 0}] = 0;
    rep(i, 1, n){
        if(s[i] == 'U') y --;
        if(s[i] == 'D') y ++;
        if(s[i] == 'L') x --;
        if(s[i] == 'R') x ++;
        if(q.count({x, y})){
            if(i - q[{x, y}] < res){
                res = i - q[{x, y}];
                l = q[{x, y}] + 1;
                r = i;
            }
        }
        q[{x, y}] = i;
    }
    if(res == 1e9){
        cout << -1 << endl;
        return;
    }
    cout << l << ' ' << r << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}