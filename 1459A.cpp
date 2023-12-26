/*
 * @Author: JorD
 * @Date: 2023-11-30 14:02:25
 * @LastEditTime: 2023-11-30 14:02:27
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
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    int a = 0, b = 0;
    for(int i = 0;i < n;i ++)if(s1[i] > s2[i]) a++;
    else if(s1[i] < s2[i]) b ++;
    if(a > b) cout << "RED\n";
    else if(a < b) cout << "BLUE\n";
    else cout << "EQUAL\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}