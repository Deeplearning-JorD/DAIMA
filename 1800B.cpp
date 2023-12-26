/*
 * @Author: JorD
 * @LastEditTime: 2023-03-02 22:45:02
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> q;
    for(auto x:s){
        q[x] ++;
    }
    int res = 0;
    for(char i = 'a';i <= 'z';i ++){
        auto j = i - 32;
        int c = min(q[i], q[j]);
        res += c;
        c = max(q[i], q[j]) - c;
        int d = min(c / 2, k);
        k -= d;
        res += d;
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}