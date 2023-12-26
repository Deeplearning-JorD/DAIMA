/*
 * @Author: JorD
 * @LastEditTime: 2022-10-07 22:40:33
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
    string s;
    cin >> s;
    vector<int> num(26);
    for(auto x:s) num[x - 'a'] ++;
    string res = "";
    rep(i, 1, m){
        rep(j, 0, 25){
            if(num[j]&&j < n/m){
                num[j] --;
                continue;
            }
            res += (char)('a' + j);
            break;
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t -- )
    Solve();
    return 0;
}