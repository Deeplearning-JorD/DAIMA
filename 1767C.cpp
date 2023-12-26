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
void Solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll m = 1ll << n;
    priority_queue<int> q;
    priority_queue<int, vector<int>, greater<>> qq;
    rep(i, 1, m){
        q.push(i);
        qq.push(i);
    } 
    int idx = 0;
    while(m){
        m >>= 1;
        if(s[idx] == '1')
            rep(i, 1, m) qq.pop();
        else{
            priority_queue<int, vector<int>, greater<>> ji;
            rep(i, 1, m << 1){
                auto t = qq.top(); qq.pop();
                if(i & 1){
                    ji.push(t);
                }
            }
            qq = ji;
        }
        idx ++;
    }
    int r = qq.top();
    m = 1ll << n;
    idx = 0;
    while(m){
        m >>= 1;
        if(s[idx] == '0'){
            rep(i, 1, m) q.pop();
        }else{
            priority_queue<int> ji;
            rep(i, 1, m << 1){
                auto t = q.top(); q.pop();
                if(i & 1) ji.push(t);
            }
            q = ji;
        }
    }
    rep(i, q.top(), r) cout << i << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}