/*
 * @Author: JorD
 * @LastEditTime: 2023-05-07 18:25:32
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
bool st[14][14];
void Solve(){
    int n;
    cin >> n;
    ll last = 0;
    rep(i, 1, n * 3 - 3){
        ll a, b, c;
        cin >> a >> b >> c;
        if(last) continue;
        if((a == 1 || b == 3) && st[2][a]) last = i;
        if(b == 2 && (st[1][a] || st[3][a])) last = i;
        st[a][b] = 1;  
    }
    if(last % 2 == 0) cout << "Sheauhaw\n";
    else cout << "Nocriz\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}