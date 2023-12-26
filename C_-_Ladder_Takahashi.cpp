/*
 * @Author: JorD
 * @LastEditTime: 2022-11-12 21:02:46
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
    map<int, vector<int>> son;
    int n;
    cin >> n;
    rep(i, 1, n){
        int a, b;
        cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    map<int, bool> st;
    queue<int> q;
    q.push(1);
    st[1] = true;
    int res = 1;
    while(q.size()){
        auto t = q.front(); q.pop();
        res = max(res, t);
        for(auto x:son[t]){
            if(st[x]) continue;
            q.push(x);
            st[x] = true;
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