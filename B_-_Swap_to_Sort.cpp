/*
 * @Author: JorD
 * @LastEditTime: 2022-09-04 21:08:38
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
    }
    vector<int> odd, even;
    rep(i, 1, n){
        if((i&1) != (a[i]&1)){
            if(i&1){
                even.push_back(i);
            }else{
                odd.push_back(i);
            }
        }
    }
    vector<pair<char,int>> res;
    auto sp = [&](int l, int r){
        for(int i = r - 2;i >= l;i -= 2){
            res.push_back({'B', i});
            swap(a[i], a[i+2]);
        }
    };
    int l = 1, r = 2;
    for(auto x:even){
        sp(l, x);
        l += 2;
    }
    for(auto x:odd){
        sp(r, x);
        r += 2;
    }
    for(int i = 1;i < l;i += 2){
        res.push_back({'A', i});
        swap(a[i], a[i+1]);
    }
    int m = n - (n&1);
    for(int i = 1;i <= n;i += 2){
        int id = i;
        if(id == a[id]) continue;
        for(int j = i;j <= n;j +=2){
            if(a[j] < a[id]){
                id = j;
            }
        }
        sp(i, id);
    }
    for(int i = 2;i <= m;i += 2){
        int id = i;
        if(id == a[id]) continue;
        for(int j = i;j <= m;j +=2){
            if(a[j] < a[id]){
                id = j;
            }
        }
        sp(i, id);
    }
    // rep(i, 1, n) cout << a[i] << " ";
    cout << res.size() << endl;
    for(auto x:res) cout << x.first << ' ' << x.second << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}