/*
 * @Author: JorD
 * @LastEditTime: 2022-12-10 20:03:09
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
    if(s.size() != 8){
        cout << "No\n";
        return;
    }
    if(s[0] < 'A'||s[0] > 'Z'){
        cout << "No\n";
        return;
    }
    if(s.back() > 'Z'||s.back() < 'A'){
        cout << "No\n";
        return;
    }
    s = s.substr(1, 6);
    if(s >= "100000"&&s <= "999999") cout << "Yes\n";
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