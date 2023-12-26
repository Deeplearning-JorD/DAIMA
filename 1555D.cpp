/*
 * @Author: JorD
 * @LastEditTime: 2022-11-24 00:08:54
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
    scanf("%d%d",&n,&m);
    string s;
    cin >> s;
    s = " " + s;
    int cnt = 0;
    vector<vector<int>> cost(18);
    auto calc = [&](string now){
        int j = 0, jj = 1, jjj = 2;
        vector<int> v(n + 1);
        vector<int> vv(n + 1);
        vector<int> vvv(n + 1);
        rep(i, 1, n){
            v[i] = v[i - 1] + (s[i] != now[j % 3]);
            vv[i] = vv[i - 1] + (s[i] != now[jj % 3]);
            vvv[i] = vvv[i - 1] + (s[i] != now[jjj % 3]);
            j ++, jj ++, jjj ++;
        }
        cost[cnt++] = v;
        cost[cnt++] = vv;
        cost[cnt++] = vvv;
    };
    vector<string> beibei(6);
    beibei[0] = "abc";
    beibei[1] = "acb";
    beibei[2] = "bac";
    beibei[3] = "bca";
    beibei[4] = "cab";
    beibei[5] = "cba";
    for(auto x:beibei) calc(x);
    while(m --){
        int l, r;
        scanf("%d%d",&l,&r);
        int res = 1e9;
        for(auto &now:cost){
            res = min(res, now[r] - now[l - 1]);
        }
        printf("%d\n", res);
    }
    return;
}
int main(){
    Solve();
    return 0;
}