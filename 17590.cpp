/*
 * @Author: JorD
 * @LastEditTime: 2022-11-18 22:42:47
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
    set<char> q;
    for(auto x:s){
        q.insert(x);
    } 
    for(auto x:q){
        if(x == 'Y'||x == 'e'||x == 's')
            continue;
        else{
            cout << "NO\n";
            return;
        }
    }
    for(int i = 1;i < siz(s);i ++){
        string ss = s.substr(i - 1, 2);
        if(ss == "sY"||ss == "Ye"||ss == "es") continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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