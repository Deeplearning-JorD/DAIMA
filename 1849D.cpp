/*
 * @Author: JorD
 * @LastEditTime: 2023-07-27 23:53:18
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
void Solve(){
    int n; cin >> n;
    vector<int> a(n + 2);
    rep(i, 1, n) cin >> a[i];
    int l = 1, r = 1;
    int res = 0; 
    int cnt = 0;
    vector<int> ls;
    ls.push_back(-1);
    rep(i, 1, n){
        if(a[i] == 0){
            cnt ++;
            continue;
        }
        if(cnt >= 2){
            res += cnt - 2;
            ls.push_back(0);
            ls.push_back(0);
        }else if(cnt == 1) ls.push_back(0);
        cnt = 0;
        int j = i;
        bool st = false;
        while(j <= n && a[j]){
            if(a[j] == 2) st = true;
            j ++;
        }
        if(st) ls.push_back(2);
        else ls.push_back(1);
        i = j - 1;
    }
    if(cnt >= 2){
        res += cnt - 2;
        ls.push_back(0);
        ls.push_back(0);
    }else if(cnt == 1) ls.push_back(0);
    int len = siz(ls);
    for(int i = 1;i < len;i ++){
        if(ls[i] == -1) continue;
        if(ls[i] == 1){
            res ++;
            if(ls[i - 1] != -1){
                ls[i] = -1;
            }else{
                if(i + 1 < len)
                ls[i + 1] = -1;
            }
            ls[i] = -1;
        }else if(ls[i] == 2){
            res ++;
            if(i + 1 < len) ls[i + 1] = -1;
            ls[i] = -1;
        }else{
            if(i + 1 >= len || (i + 1 < len && ls[i + 1] == 0)){
                res ++;
                ls[i] = -1;
            }
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}