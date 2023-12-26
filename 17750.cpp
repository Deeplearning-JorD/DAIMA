/*
 * @Author: JorD
 * @LastEditTime: 2023-01-10 19:36:49
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
    for(int i = 1;i < n - 1;i ++){
        if(s[i] == 'a'){
            for(int j = 0;j < i;j ++) cout << s[j];
            cout << ' ';
            cout << s[i] << ' ';
            for(int j = i + 1;j < n;j ++) cout << s[j];
            cout << endl;
            return;
        }
    }
    cout << s[0] << ' ';
    for(int j = 1;j < n - 1;j ++) cout << s[j];
    cout << ' ';
    cout << s[n - 1] << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}