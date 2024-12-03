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

void helper(vecll& nums,int n)
{
    vecll possibles;
    ll mini=INT_MAX;
    ll count=0;
    forLoop
        if(nums[i]<mini){
            possibles.pb(i);
            mini=nums[i];
        }
    for(int i=0;i<possibles.size();i++)
    {
        int j=possibles[i]+1;
        mini = INT_MAX;
        while(j<n){
            if(nums[j]<mini && nums[j]>nums[possibles[i]]){
                mini=nums[j];
                count++;
                j++;
            }
            else{
                if(mini>nums[j])
                    mini=nums[j];
                j++;
            }
        }
    }
    cout<<count<<endl;
}
//0,1

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vecll nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,n);
    }
    return 0;
}





// 1
// 1
// 2
// 1 2
// 2
// 2 1
// 3
// 1 2 3
// 3
// 1 3 2
// 3
// 2 1 3
// 3
// 2 3 1
// 3
// 3 1 2
// 3
// 3 2 1
// 4
// 1 2 3 4
// 4
// 1 2 4 3
// 4
// 1 3 2 4
// 4
// 1 3 4 2
// 4
// 1 4 2 3
// 4
// 1 4 3 2
// 4
// 2 1 3 4
// 4
// 2 1 4 3
// 4
// 2 3 1 4
// 4
// 2 3 4 1
// 4
// 2 4 1 3
// 4
// 2 4 3 1
// 4
// 3 1 2 4
// 4
// 3 1 4 2
// 4
// 3 2 1 4
// 4
// 3 2 4 1
// 4
// 3 4 1 2
// 4
// 3 4 2 1
// 4
// 4 1 2 3
// 4
// 4 1 3 2
// 4
// 4 2 1 3
// 4
// 4 2 3 1
// 4
// 4 3 1 2
// 4
// 4 3 2 1
// 5
// 1 2 3 4 5
// 5
// 1 2 3 5 4
// 5
// 1 2 4 3 5
// 5
// 1 2 4 5 3
// 5
// 1 2 5 3 4
// 5
// 1 2 5 4 3
// 5
// 1 3 2 4 5
// 5
// 1 3 2 5 4
// 5
// 1 3 4 2 5