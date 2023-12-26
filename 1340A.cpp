/*
 * @Author: JorD
 * @LastEditTime: 2023-05-01 20:16:51
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
    vector<int> a(n + 1), num(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) num[a[i]] = i;
    vector<int> st(n + 1, -1);
    int flag = -1;
    rep(i, 1, n){
        if(flag == -1){
            flag = num[i];
            st[num[i]] = 1;
            if(num[i] + 1 > n || st[num[i] + 1] != -1){
                flag = -1;
            }
            continue;
        }
        if(num[i] == flag + 1){
            st[num[i]] = 1;
            flag ++;
            if(num[i] + 1 > n || st[num[i] + 1] != -1){
                flag = -1;
            }
            continue;
        }
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}