/*
 * @Author: JorD
 * @LastEditTime: 2023-02-28 22:52:34
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
    string s, t;
    cin >> s >> t;
    if(s[0] == t[0]){
        cout << "YES\n";
        cout << s[0] << '*' << '\n';
        return;
    }
    if(s.back() == t.back()){
        cout << "YES\n";
        cout << '*' << s.back() << endl;
        return;
    }
    for(int i = 0;i < siz(s) - 1;i ++){
        for(int j = 0;j < siz(t) - 1;j ++){
            if(s[i] == t[j] && s[i + 1] == t[j + 1]){
                cout << "YES\n";
                cout << '*' << s[i] << s[i + 1] << '*' << endl;
                return;
            }
        }
    }
    cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}