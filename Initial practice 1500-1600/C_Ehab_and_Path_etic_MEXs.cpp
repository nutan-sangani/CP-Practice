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

void helper()
{
    
}

int main()
{
    FASTIO
    
    int n;
    cin>>n;
    vecll ans;
    omll freq;
    vector<pair<int,int>> nums(n-1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        freq[a]++;
        freq[b]++;
        nums[i]=mp(a,b);
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(freq[i]==1){
            count++;
        }
    }
    int x,y;
    x=0;
    y=count;
    for(int i=0;i<n-1;i++){
        if(freq[nums[i].first]==1 || freq[nums[i].second]==1){
            ans.pb(x);
            x++;
        }
        else ans.push_back(y++);
    }
    for(int i=0;i<n-1;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}