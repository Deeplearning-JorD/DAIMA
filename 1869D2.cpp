/*
 * @Author: JorD
 * @LastEditTime: 2023-09-12 23:19:57
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
int lowbit(int x){
    return x & -x;
}
void Solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    if(sum % n){
        cout << "No\n";
        return;
    }
    sum /= n;
    vector<int> d(33);
    vector<vector<int>> can(33, vector<int> (2));
    for(int i = 1;i <= n;i ++){
        int x = abs(sum - a[i]), cnt = 0;
        if(!x) continue;
        if(x == lowbit(x)){
            int id = 0;
            for(int j = 0;j < 31;j ++){
                if(x >> j & 1) id = j;
            }
            if(sum > a[i]) can[id][0] ++;
            else can[id][1] ++;
            continue;
        }
        bool st = false;
        for(int A = 0;A < 31;A ++){
            for(int B = 0;B < 31;B ++){
                if((1 << A) - (1 << B) == sum - a[i]){
                    d[A] ++;
                    d[B] --;
                    st = true;
                }
            }
        }
        if(!st){
            cout << "No\n";
            return;
        }
    }
    for(int i = 30;i >= 0;i --){
        int now = d[i] + (can[i][0] - can[i][1]);
        if(now == 0) continue;
        if(now > 0){
            if(i > 0 && now <= can[i - 1][1]){
                can[i - 1][1] -= now;
                d[i - 1] += now;
            }else{
                cout << "No\n";
                return;
            }
        }else{
            if(i > 0 && -now <= can[i - 1][0]){
                can[i - 1][0] -= -now;
                d[i - 1] -= -now;
            }else{
                cout << "No\n";
                return;
            }
        }
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