/*
 * @Author: JorD
 * @LastEditTime: 2022-09-26 20:24:50
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
    string res = "";
    for(auto x:s){
        res += char('9' - x + '0');
    }
    if(s[0] == '1'){
        cout << res << endl;
        return;
    }
    reverse(res.begin(), res.end());
    int idx = 0;
    int t = 0;
    string last = "";
    for(auto x:res){
        int w = 0;
        if(idx == 0) w = 2;
        else w = 1;
        int now = x - '0' + t + w;
        t = now / 10;
        last += (char)(now%10 + '0');
        idx ++;
    }
    reverse(last.begin(), last.end());
    cout << last << endl;
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