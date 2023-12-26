/*
 * @Author: JorD
 * @LastEditTime: 2023-07-06 22:38:35
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
    vector<int> a(n + 1);
    int sum = 0;
    vector<int> v;
    rep(i, 1, n){
        cin >> a[i];
        if(i > 1){
            v.push_back(abs(a[i] - a[i - 1]));
            sum += abs(a[i] - a[i - 1]);
        }
    }
    k --;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int i = 0;i < k;i ++){
        sum -= v[i];
    }
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