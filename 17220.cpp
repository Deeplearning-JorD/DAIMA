/*
 * @Author: JorD
 * @LastEditTime: 2022-08-30 23:19:37
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
map<string,bool> q;
void Solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0, res = 0;
    for(auto &x:s){
        if(x>='A'&&x<='Z'){
            if(x == 'T') res ++;
            cnt ++;
            x = (char)(x + 32);
        }    
    }
    sort(s.begin(), s.end());
    if(q[s]&&cnt == 1&&res == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    q["imrtu"]=1;
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}