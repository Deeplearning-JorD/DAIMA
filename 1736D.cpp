/*
 * @Author: JorD
 * @LastEditTime: 2022-10-11 19:59:34
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
    int n;
    cin >> n;
    string s;   
    cin >> s;
    s = ' ' + s;
    int idx = 0;
    rep(i, 1, n << 1) idx += s[i] - '0';
    if(idx&1){
        cout << -1 << endl;
        return;
    }
    vector<int> res;
    for(int i = 1, j = 1, need = 0;j <= n;i += 2, j ++ ){
        if(s[i] == s[i + 1]) continue;
        if(s[i] - '0' == need){
            need ^= 1;
            res.push_back(i);
        }else{
            need ^= 1;
            res.push_back(i + 1);
        }
    }
    cout << res.size() <<' ';
    for(auto x:res) cout << x << ' ';
    cout << endl;
    for(int i = 1;i <= 2*n; i += 2) cout << i << ' ';
    cout << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}