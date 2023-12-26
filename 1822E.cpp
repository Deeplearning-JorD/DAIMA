/*
 * @Author: JorD
 * @LastEditTime: 2023-04-25 13:41:02
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> sum(26);
    for(auto x:s) sum[x - 'a'] ++;
    rep(i, 0, 25)if(sum[i] > n / 2){
        cout << -1 << endl;
        return;
    }
    if(n & 1){
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    sum.clear(); sum.resize(26);
    for(int i = 0, j = s.size() - 1;i < j;i ++, j --){
        if(s[i] == s[j]){
            sum[s[i] - 'a'] ++;
            cnt ++;
        }
    }
    sort(sum.begin(), sum.end());
    cout << max((cnt + 1) / 2, *sum.rbegin()) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}