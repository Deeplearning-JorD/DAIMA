/*
 * @Author: JorD
 * @LastEditTime: 2022-10-03 13:34:15
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
    map<char,char> q,ne;
    map<char,bool> fa,son;
    string res = "";
    rep(i, 1, n){
        if(fa[s[i]]){
            res += q[s[i]];
            continue;
        }
        fa[s[i]] = true;
        for(auto c = 'a'; c <= 'z';c ++){
            if(son[c]||c == s[i]) continue;
            char now = s[i];
            int idx = 1;
            if(son[now]){
            for(;;){
                now = ne[now]; idx ++;
                if(now == c||idx == 26) break;
            }
            if(idx != 26) continue;}
            ne[c] = s[i];
            son[c] = true;
            q[s[i]] = c;
            res += c;
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
    while(t --)
    Solve();
    return 0;
}