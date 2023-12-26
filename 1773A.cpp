/*
 * @Author: JorD
 * @LastEditTime: 2022-12-07 19:01:36
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
    vector<int> a(n + 1);
    vector<int> mp(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        mp[a[i]] = i;
    }
    // rep(i, 1, n) cout << mp[i] << endl;
    vector<int> resl(n + 1), resr(n + 1);
    rep(i, 1, n) resr[i] = i;
    int suiji = 250;
    bool real = false;
    while(suiji --){
        random_shuffle(resr.begin() + 1, resr.end());
        bool flag = true;
        rep(i, 1, n){
            if(resr[i] == i || resr[i] == mp[i]){
                flag = false;
                break;
            }
            if(i != a[mp[i]]){
                flag = false;
                break;
            }resl[resr[i]] = mp[i];
        }
        if(flag){
            real = true;
            break;
        }
    }
    if(!real){
        cout << "Impossible\n";
        return;
    }
    cout << "Possible\n";
    for(int i = 1;i <= n;i ++) cout << resl[i] << " \n"[i == n];
    for(int i = 1;i <= n;i ++) cout << resr[i] << " \n"[i == n];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}