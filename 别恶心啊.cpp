/*
 * @Author: JorD
 * @LastEditTime: 2022-10-08 13:20:23
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n + 1);
    rep(i, 1, n) cin >> s[i];
    while(m -- ){
        string c; 
        cin >> c;
        bool st = false;
        for(int i = 0;i < c.size();i ++){
            rep(j, 1, n){
                // if(i + s[j].size() > c.size()) continue;
                if(c.substr(i, s[j].size()) == s[j]){
                    cout << "bieexina\n";
                    st = true;
                    break;
                }
                //  cout << c.substr(i, i + s[j].size()) << '\n' << s[j] << "\n\n";
            }
            if(st) break;   
        }
        if(!st) cout << "enenen\n";
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    // while(t --)
    Solve();
    return 0;
}