/*
 * @Author: JorD
 * @LastEditTime: 2022-09-26 01:10:58
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
    string s;
    cin >> s;
    char c = '9';
    string res = "", ans = "";
    string now = s;
    for(char i = '0';i <= '9';i ++){
        bool st = false;
        string nw = "";
        int idx = 0, last = 0;
        for(auto x:now){
            if(x == i){ st = true;last = idx;}
            idx ++;
        }
        if(!st) continue;
        int nn = 0;
        idx = 0;
        for(auto x:now){
            if(x == i){
                res += i;
            }else{
                char w = x;
                if(w != '9'&&idx < last) w ++;
                if(idx < last) ans += w;
                else
                nw += w;
            }
            idx ++;
        }
        now = nw;
    }
    res += ans;
    sort(res.begin(), res.end());
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