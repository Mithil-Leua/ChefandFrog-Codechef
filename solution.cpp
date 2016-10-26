#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
 
bool mycompare (const tuple<int,long long> &a,const tuple<int,long long> &b){
  return get<1>(a) < get<1>(b);
}
 
int main(void){
    int n,k,p;
    cin >> n >> k >> p;
    vector<tuple<int,long long>> a;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        a.push_back(make_tuple(i+1,tmp));
    }
    sort(a.begin(),a.end(),mycompare);
    int dp[n];
    dp[n-1] = get<1>(a[n-1]);
    for(int i=n-2;i>=0;i--){
        if(get<1>(a[i+1])-get<1>(a[i]) <= k)
            dp[i] = dp[i+1];
        else
            dp[i] = get<1>(a[i]);
    }
    int rank[n];
    for(int i=0;i<n;i++){
        rank[get<0>(a[i])-1] = i+1;
    }
    while(p--){
        int x,y;
        cin >> x >> y;
        int rank1,rank2;
        rank1 = rank[x-1];
        rank2 = rank[y-1];
        //cout << rank1 << rank2 << endl;
        if(dp[rank1-1] == dp[rank2-1])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
