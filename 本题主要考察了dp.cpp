/*
 * @Author: JorD
 * @LastEditTime: 2023-01-16 14:36:56
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
    int n, m;
    cin >> n >> m;
    vector<int> res;
    int i = 0, idx = 0;
    int L = m, R = n - m;
    while(i < n){
        if(i % 3 == 0){
            if(L){
                L --;
                res.push_back(1);
            }else{
                R --;
                res.push_back(0);
            }
        }else{
            if(R){
                R --;
                res.push_back(0);
            }else{
                L --;
                res.push_back(1);
            }
        }
        i ++;
    }
    vector<int> pre(n);
    pre[0] = res[0];
    int js = 0;
    for(int i = 1;i < n;i ++){
        pre[i] = pre[i - 1] + res[i];
        if(i >= 2){
            if(i == 2){
                if(pre[i] > 1) js ++;
                continue;
            }
            if(pre[i] - pre[i - 3] > 1) js ++;
        }
    }
    cout << js;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}