/*
 * @Author: JorD
 * @LastEditTime: 2023-05-06 19:55:44
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
    if(k % 2 == 0){
        cout << "-1";
        return;
    }
    k --;
    vector<int> res(n + 1);
    rep(i, 1, n) res[i] = i;
    auto dfs = [&](auto self, int l, int r){
        if(!k || l >= r) return;
        k -= 2;
        int mid = l + r + 1 >> 1;
        swap(res[mid], res[mid - 1]);
        self(self, l, mid - 1);
        self(self, mid, r);
    };
    dfs(dfs, 1, n);
    if(k){
        cout << -1 << endl;
        return;
    }
    rep(i, 1, n) cout << res[i] << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}
	    			   		    	  		  	 	 		