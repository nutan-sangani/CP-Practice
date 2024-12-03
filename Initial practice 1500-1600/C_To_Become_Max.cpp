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

void helper(vecll &nums,ll n,ll k)
{
    ll maxPossible=nums[0];
    ll tempMax=-1;
    for(int i=1;i<n;i++){
        tempMax=nums[i];
        if(tempMax>maxPossible){
            maxPossible=tempMax;
        }
        ll kCopy=k;
        int j=i-1;
        ll incrPossible = nums[i] - nums[j]+1;
        if(incrPossible<=0){
            continue;
        }
        int prev=1;
        tempMax=nums[j];
        {
            ll tempPrev=prev;
            ll canIncr = kCopy/tempPrev;
            ll toIncr = min<ll>(canIncr,incrPossible);
            ll temp = tempMax+toIncr;
            if(temp>maxPossible){
                maxPossible=temp;
            }
        }
        for(j=i-2;j>=0;j--,prev++){
            ll diff = nums[j] - tempMax;
            if(diff>=0){
                if(diff<=incrPossible && (prev*diff+1)<=kCopy){
                    incrPossible-=diff;
                    kCopy-=prev*diff;
                    kCopy--;
                    tempMax=nums[j]+1;
                    if(tempMax>maxPossible){
                        maxPossible=tempMax;
                    }
                    {
                        ll tempPrev=prev+1;
                        ll canIncr = kCopy/tempPrev;
                        ll toIncr = min<ll>(canIncr,incrPossible);
                        ll temp = tempMax+toIncr;
                        if(temp>maxPossible){
                            maxPossible=temp;
                        }
                    }
                }
            }
            else{
                diff = abs(diff);
                if(kCopy>=(diff+1)){
                    tempMax+=1;
                    if(tempMax>maxPossible){
                        maxPossible=tempMax;
                    }
                    kCopy-=(diff+1);
                    {
                        ll tempPrev=prev+1;
                        ll canIncr = kCopy/tempPrev;
                        ll toIncr = min<ll>(canIncr,incrPossible);
                        ll temp = tempMax+toIncr;
                        if(temp>maxPossible){
                            maxPossible=temp;
                        }
                    }
                }
                else{
                    break;
                }
            }
        }
    }
    cout<<maxPossible<<endl;
    return;
}//3,5 
//17

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vecll nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,n,k);
    }
    return 0;
}