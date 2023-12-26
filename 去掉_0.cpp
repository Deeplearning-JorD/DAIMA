/*
 * @Author: JorD
 * @LastEditTime: 2022-09-10 19:07:52
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
    vector<char> a;
    for(auto x:s) a.push_back(x);
    int l = 0, r = a.size() - 1;
    for(auto x:a){
        if(x == '1') break;
        l ++;
    }
    for(int i = a.size() - 1;i >= 0;i --){
        if(a[i] == '1') break;
        r --;
    }
    int res = 0;
    rep(i, l, r){
        if(a[i] == '0') res++;
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}