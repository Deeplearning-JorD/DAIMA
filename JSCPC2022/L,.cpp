/*
 * @Author: JorD
 * @LastEditTime: 2023-03-31 00:03:09
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
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    int sum = 0, pre = 0;
    auto get = [&](int i){
        int l = i - 1, r = i + 1;
        int cnt = 0;
        while(l >= 1 && r <= n){
            if(s[l] == 'A' && s[r] == 'C'){ 
                cnt ++;
                l --, r ++;
            }else break;
        }
        return cnt;
    };
    for(int i = 1;i < n;i ++){
        int cnt = get(i);
        if(s[i] == 'B' && s[i + 1] == 'C' && s[i - 1] == 'A'){
            if(i & 1){
                if(!pre){
                    sum ++;
                    pre ++;
                    continue;
                }
                sum += min(pre + 1, cnt);
                pre ++;
            }else{
                if(!pre){
                    if(cnt > 1){sum += 2; pre ++;}
                    else sum ++;
                    continue;
                }
                sum += min(pre + 2, cnt);
                pre ++;
            }
        }
    }
    cout << sum << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}