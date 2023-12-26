/*
 * @Author: JorD
 * @LastEditTime: 2023-04-09 20:09:20
 */
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
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector<bool> st(n + 2);
    for(int i = n;i >= 1;i --){
        st[i] = st[i + 1];
        st[i] = st[i] | (s[i] == 'R');
    }
    
    vector<bool> st1(n + 2);
    for(int i = 1;i <= n;i ++){
        st1[i] = st1[i - 1];
        st1[i] = st1[i] | (s[i] == 'R');
    }
    set<int> q;
    bool ff = false;
    for(int i = 1;i <= n;i ++){
        if(s[i] == 'B') q.insert(i % 2);
        if(s[i] == 'K' && st1[i] && st[i]){
            ff = true;
        }
    }
    if(ff && q.size() == 2) cout << "Yes\n";
    else cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}