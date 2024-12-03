#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void helper(int n)
{
    int minCount=INT_MAX;
    int minGroupSize=INT_MAX;
    for(int i=1;i<=n;i++){
        int lis=0;
        int lds=0;
        lis = ceil(float(n)/float(i));
        lds = i;
        ll sum = lis+lds;
        if(sum<minCount){
            minCount = sum;
            minGroupSize = i;
        }
    }
    vector<int> ans;
    int groupCount = n/minGroupSize;
    int i=0;
    while(i<groupCount){
        int offSet = i*minGroupSize;
        for(int j=minGroupSize;j>0;j--){
            ans.pb(offSet+j);
        }
        i++;
    }
    i=0;
    if(n%minGroupSize!=0){
        int rem = n%minGroupSize;
        int count=0;
        while(count<rem){
            ans.pb(n);
            n--;
            count++;
        }
    }
    for(i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    FASTIO
    
    int n;
    cin>>n;
    helper(n);
    return 0;
}