/*
 * @Author: JorD
 * @LastEditTime: 2023-01-20 14:29:29
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
int n;
int st[100];
int a[100000];
bool check(){
    rep(i, 1, n){
        if(abs(a[i] - i) <= 3 && abs(a[i] - i) >= 2) continue;
        return false;
    }
    return true;
}
void Solve(){
    cin >> n;
    vector<int> res;
    if(n % 4 == 0){
        if(n >= 4){
            res.push_back(3);
            res.push_back(4);
            res.push_back(1);
            res.push_back(2);
            for(int i = 8;i <= n;i += 4){
                res.push_back(i - 1);
                res.push_back(i);
                res.push_back(i - 3);
                res.push_back(i - 2);
            }
        }else cout << -1 << endl;
    }else if(n % 4 == 1){
        if(n >= 5){
            res.push_back(3);
            res.push_back(4);
            res.push_back(5);
            res.push_back(1);
            res.push_back(2);
            for(int i = 9;i <= n;i += 4){
                res.push_back(i - 1);
                res.push_back(i);
                res.push_back(i - 3);
                res.push_back(i - 2);
            }
        }else cout << -1 << endl;
    }else if(n % 4 == 2){
        if(n >= 6){
            res.push_back(3);
            res.push_back(5);
            res.push_back(1);
            res.push_back(6);
            res.push_back(2);
            res.push_back(4);
            for(int i = 10;i <= n;i += 4){
                res.push_back(i - 1);
                res.push_back(i);
                res.push_back(i - 3);
                res.push_back(i - 2);
            }
        }else cout << -1 << endl;
    }else if(n % 4 == 3){
        if(n >= 11){
            res.push_back(3);
            res.push_back(5);
            res.push_back(1);
            res.push_back(6);
            res.push_back(2);
            res.push_back(4);
            res.push_back(10);
            res.push_back(11);
            res.push_back(7);
            res.push_back(8);
            res.push_back(9);
            for(int i = 15;i <= n;i += 4){
                res.push_back(i - 1);
                res.push_back(i);
                res.push_back(i - 3);
                res.push_back(i - 2);
            }
        }else cout << -1 << endl;
    }
    // rep(i, 1, n){
    //     a[i] = res[i -  1];
    // }
    for(auto x:res) cout << x << ' ';
    // cout << check() << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}