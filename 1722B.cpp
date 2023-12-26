/*
 * @Author: JorD
 * @LastEditTime: 2022-08-30 22:58:46
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
    string s, ss;
    int n;
    cin >> n;
    cin >> s >> ss;
    int res = 0;
    for(int i = 0;i <siz(s);i ++){
        int cnt = 0;
        if(s[i]=='G'||s[i]=='B') cnt ++;
        if(ss[i]=='G'||ss[i]=='B') cnt ++;
        if(cnt == 2 || s[i] == ss[i]) res ++;
    }
    if(res == siz(s))
    cout << "YES" << endl;
    else cout << "NO" << endl;
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