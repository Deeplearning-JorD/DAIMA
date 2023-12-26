/*
 * @Author: JorD
 * @LastEditTime: 2023-01-28 20:35:19
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
const int N = 3e5 + 10;
char ji[N];
void Solve(){
    string s, t;
    cin >> s >> t;
    int n = siz(s), m = siz(t);
    s = ' ' + s;
    t = ' ' + t;
    int l = 0, r = n - m + 1;
    int res = 0; 
    for(int i = r,j = 1;i <= n;i ++, j ++){
        ji[i] = t[j];
        if(ji[i] == s[i]||ji[i] == '?'||s[i] == '?')
        res++;
    }
    if(res == m) cout << "Yes\n";
    else cout << "No\n"; 
    rep(j, 1, m){
        l ++;
        ji[l] = ji[r];
        int i = l;
        if(ji[i] == s[i]||ji[i] == '?'||s[i] == '?')
        res++;
        i = r;
        if(ji[i] == s[i]||ji[i] == '?'||s[i] == '?')
        res--;
        r ++;
        if(res == m) cout << "Yes\n";
        else cout << "No\n"; 
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}