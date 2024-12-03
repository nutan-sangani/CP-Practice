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

void helper(vecll& nums,ll n,ll m)
{
    priority_queue<ll,vecll,greater<ll>> minHeap;
    priority_queue<ll,vecll> maxHeap;
    ll sum=0;
    ll operations=0;
    // if(m!=1)
    {
        for(int i=m-1;i>0;i--){ //yaha pe i>=0 nhi, i>0 hi ayega, since 1st ke pehle koi bhi SA h hi nhi.
            sum+=nums[i];
            maxHeap.push(nums[i]);
            if(sum>0){
                while(sum>0){
                    ll maxElement = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(maxElement*-1);
                    sum-=maxElement; //removing maxElement
                    sum-=maxElement; //adding -ve of maxElement
                    operations++;
                }
            }
        }
    }
    sum=0;
    for(int i=m;i<n;i++){
        sum+=nums[i];
        minHeap.push(nums[i]);
        if(sum<0){
            while(sum<0){
                ll minElement = minHeap.top();
                minHeap.pop();
                minHeap.push(minElement*-1);
                sum-=minElement;
                sum-=minElement;
                operations++;
            }
        }
    }
    cout<<operations<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vecll nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,n,m);
    }
    return 0;
}