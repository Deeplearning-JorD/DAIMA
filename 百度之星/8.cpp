/*
 * @Author: JorD
 * @LastEditTime: 2023-08-06 18:56:25
 * how to Get
 */
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int sum = 0;
    priority_queue<ll> q;
    for(int i = 1;i <= n;i ++){
        ll x; cin >> x;
        q.push(x);
    }
    int cnt = 0;
    while(q.size()){
        auto t = q.top(); q.pop();
        if((t & 1) || t / 2 == 0) continue;
        q.push(t / 2);
        q.push(t / 2);
        sum ^= 1;
        cnt = 1;
    }
    if(cnt == 0){
        cout << "Xiaodu";
        return 0;
    }
    if(sum & 1) cout << "Xiaodu";
    else cout << "Duduxiong";
    return 0;
}