/*
 * @Author: JorD
 * @LastEditTime: 2023-09-11 22:53:08
 * how to Get
 */
#pragma GCC optimize(2)
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
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    int a = 0, b = 0;
    for(int i = 1, j = n;i <= n / 2;i ++, j --){
        if(s[i] == s[j]){
            b ++;
        }else a ++;
    }
    for(int i = 0;i <= n;i ++){
        if(i < a){
            cout << 0;
            continue;
        }
        int need = i - a;
        if(need / 2 <= b){
            if(need % 2 == 1){
                if(n & 1) cout << 1;
                else cout << 0;                    
            }else cout << 1;
        }else cout << 0;
    }
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}