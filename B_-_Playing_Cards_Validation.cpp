/*
 * @Author: JorD
 * @LastEditTime: 2022-11-12 20:52:51
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
    set<string> t;
    int n;
    cin >> n;
    string t1 = "HDCS", t2 = "A23456789TJQK";
    map<char, int> q, qq;
    for(auto x:t1){
        q[x] = 1;
    }
    for(auto x:t2){
        qq[x] = 1;
    }
    rep(i, 1, n){
        string s;
        cin >> s;
        t.insert(s);
        if(!q[s[0]]||!qq[s[1]]){
            cout << "No\n";
            return;
        }
    }
    if(t.size() != n) cout << "No\n";
    else cout << "Yes\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}