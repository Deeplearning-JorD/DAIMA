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
string mb;
bool cmp(string s){
    if(s.size() == mb.size()){
        for(int i = 0;i < s.size();i ++){
            if(s[i] > mb[i]) return false;
            else if(mb[i] > s[i]) return true; 
        }
    }   
    return mb.size() > s.size();
}
bool check(string s){
    if(s.size() < 3) return false;
    int idx = 0;
    int cnt = 0;
    rep(i, 0, 2) cnt += (s[i] == '1');
    if(cnt == 3) return true;
    rep(i, 3, siz(s) - 1){
        cnt += (s[i] == '1');
        cnt -= (s[idx] == '1');
        idx ++;
        if(cnt == 3) return true;
    } 
    return false;
}
ll res;
void dfs(string s){
    if(!cmp(s)) return;
    if(check(s)) res ++;
    if(s.size() == mb.size()) return;
    dfs(s + "0");
    dfs(s + "1");
}
void Solve(){
    cin >> mb;
    string now = "1";
    dfs(now);
    printf("%lld",res);
    return;
}
int main(){
    // std::ios::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}