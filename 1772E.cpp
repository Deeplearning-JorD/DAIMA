/*
 * @Author: JorD
 * @LastEditTime: 2022-12-19 01:45:26
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
    vector<int> c(n + 1);
    rep(i, 1, n) cin >> c[i];
    vector<int> a(n + 1), b(n + 1);
    rep(i, 1, n) a[i] = i;
    for(int i = n, j = 1;i >= 1;i --, j ++) b[j] = i;
    int cnt1 = 0, cnt2 = 0, cnt = 0;
    map<int,int> q;
    for(int i = 1;i <= n;i ++){
        if(c[i] != a[i]) q[i] ++, cnt1 ++;
        if(c[i] != b[i]) q[i] ++, cnt2 ++;
    }
    for(auto [x, y]:q){
        if(y == 2) cnt ++;
    }
    for(int i = 1;;i ++){
        if(i & 1){
            if(cnt1){
                cnt1 --;
            }else if(cnt){
                if(cnt == 1){
                    if(cnt2 == 0){
                        cout << "Tie\n";
                        return;
                    }else{
                        cout << "First\n";
                        return;
                    }
                }else{
                    cnt --;
                }
            }else{
                cout << "First\n";
                return;
            }
        }else{
            if(cnt2){
                cnt2 --;
            }else if(cnt){
                if(cnt == 1){
                    if(cnt1 == 0){
                        cout << "Tie\n";
                        return;
                    }else{
                        cout << "Second\n";
                        return;
                    }
                }else{
                    cnt --;
                }
            }else{
                cout << "Second\n";
                return;
            }
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}