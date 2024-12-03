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
    umll map;
    forLoop
    {
        map[nums[i]]=i;
    }
    sort(nums.begin(),nums.end());
    int i,j;
    if(n%2==0){
        j=n/2;
        i=j-1;
    }
    else {
        i=((n/2)-1);
        j=((n/2)+1);
    }
    int cost = n/2;
    while(i>=0 && j<n){
        if(map[nums[i]] < map[nums[j]]){
            int mid1,mid2;
            mid1=map[nums[i+1]];
            mid2=map[nums[j-1]];
            if(map[nums[i]]<mid1 && map[nums[j]]>mid2){
                cost--;
            }
            else break;
            i--;
            j++;
        }
        else break;
    }
    cout<<cost<<endl;
    return;
}

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