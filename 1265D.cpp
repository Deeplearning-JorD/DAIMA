/*
 * @Author: JorD
 * @LastEditTime: 2022-08-13 16:52:57
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
    vector<int> js(5);
    cin>>js[0]>>js[1]>>js[2]>>js[3];
    int sum=accumulate(js.begin(),js.end(),0ll);
    rep(i,0,3){
        auto now = js;
        int last = i;
        vector<int> res;
        if(!now[i]) continue; 
        now[i]--;
        res.push_back(last);
        for(int j=2;j<=sum;j++){
            if(now[last-1]&&last!=0){
                last--;
                now[last]--;
            }else if(now[last+1]){
                last++;
                now[last]--;
            }else break;
            res.push_back(last);
            if(j==sum){
                cout<<"YES"<<endl;
                for(auto x:res) cout<<x<<' ';
                return;
            } 
        }
        if(sum==1){
            cout<<"YES"<<endl;
            cout<<i<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;
    Solve();
    return 0;
}