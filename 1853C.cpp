/*
 * @Author: JorD
 * @LastEditTime: 2023-07-24 02:09:48
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
    map<int,int> st;
    rep(i, 1, n){
        cin >> a[i];
        st[a[i]] = 1;
    }
    int x = 1, j =1;
    for(int i = 1;i <= k;i ++){
        while(j <= n){
            
            if(x + j + 1 >= a[j]) j ++;
            else break;

            // if(st.count(x + j)){
            //     if(x + j <= a[j - 1]) j ++;
            //     else break;
            // }else{
            //     if(x + j <= a[j]) j ++;
            //     else break;
            // }
            // j ++;
            // else break;
        }
        // int l = j, r = n;
        // while(l < r){
        //     int mid = l + r + 1 >> 1;
        //     if(a[mid] <= x + j) l = mid;
        //     else r = mid - 1;
        // }
        // j = l;
        // cout << j << ' ' << x << endl;
        if(j > n) x += n;
        else
        x += j;
        // cout << idx << endl;
    }
    cout << x << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}