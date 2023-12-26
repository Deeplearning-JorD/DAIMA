/*
 * @Author: JorD
 * @Date: 2023-11-25 16:31:09
 * @LastEditTime: 2023-11-25 16:49:37
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
void Solve(){
    string a = "", b = "";
    rep(i, 1, 5){
        int x; cin >> x;
        a += to_string(x);
    }
    rep(i, 1, 5){
        int x; cin >> x;
        b += to_string(x);
    }
    queue<string> q;
    map<string, int> st;
    q.push(a);
    st[a] = 0;
    while(q.size()){
        auto s = q.front(); q.pop();
        if(s == b){
            cout << st[s] << endl;
            return;
        }
        for(int i = 0;i < 5;i ++)if(s[i] == '0'){
            auto c = s;
            if(i == 2){
                c[0] ^= 1;
                c[2] ^= 1;
                c[4] ^= 1;
            }else if(i < 2){
                c[i] ^= 1;
                c[i + 2] ^= 1;
                c[i + 3] ^= 1;
            }else{
                c[i] ^= 1;
                c[i - 2] ^= 1;
                c[i - 3] ^= 1;
            }
            if(!st.count(c)){
                st[c] = st[s] + 1; 
                q.push(c);
            }
        }
    }
    cout << -1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}