/*
 * @Author: JorD
 * @LastEditTime: 2022-09-16 19:09:47
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
    string s;
    cin >> n >> s;
    s = ' ' + s;
    int cnt = 0;
    vector<int> last(n + 2), pre(n + 1);
    rep(i, 1, n){
        pre[i] = pre[i - 1];
        pre[i] += (s[i] == '0');
    }
    per(i, n, 1){
        last[i] = last[i + 1];
        last[i] += (s[i] == '0');
    }
    int res = 2;
    rep(i, 1, n){
        if(s[i] == '1'){
            int w = 0;
            if(last[i]) w ++;
            if(pre[i]) w ++;
            res = min(w, res);
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}