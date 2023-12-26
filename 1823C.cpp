/*
 * @Author: JorD
 * @LastEditTime: 2023-04-27 23:49:15
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
    map<int, int> q;
    while(n --){
        int x; cin >> x;
        for(int i=2;i<=x/i;i++){
            if(x%i==0){
                int s = 0;
                while(x%i==0) x/=i,s++;
                q[i] += s;
            }
        }
        if(x > 1) q[x] ++;
    }
    vector<int> ls;
    for(auto [x, y]:q)
        ls.push_back(y);
    sort(ls.begin(), ls.end());
    ll sum = 0;
    vector<int> son;
    int c = 0;
    int num = ls.size();
    for(int i = 0;i < ls.size();i ++){
        int& x = ls[i];
        sum += x / 2;
        x = x & 1;
    }
    ll cc = accumulate(ls.begin(), ls.end(), 0ll);
    sum += cc / 3;
    cout << sum << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}