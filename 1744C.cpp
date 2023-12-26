/*
 * @Author: JorD
 * @LastEditTime: 2022-10-16 22:54:58
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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    if(c == 'g'){
        cout << 0 << endl;
        return;
    }
    s = ' ' + s;
    vector<int> nex(n + 2);
    int FF = 0, last = 1e9;
    rep(i, 1, n){
        if(s[i] == 'g'){
            FF = i;
            break;
        }
    }
    int res = 0, r = 0;
    per(i, n, 1){
        if(s[i] == 'g'){
            last = i;
            continue;
        }
        if(s[i] == c){
            res = max(res, (int)min(n - i + FF, last - i));
        }
    }
    cout << res << endl;
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