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

void helper(vecll& nums,ll n)
{
    vecll prefixSums(n,0);
    ll sum=0;
    ll ogScore=0;
    forLoop
    {
        sum+=nums[i];
        prefixSums[i]=sum;
        if(prefixSums[i]==0){
            ogScore++;
        }
    }
    umll freq;
    ll score=0;
    ll maxFreq=0;
    int flag=0;
    //2 0 1 -1 0
    //2 2 3 2 2
    //0 0 
    forLoop
    {
        if(nums[i]==0){
            score+=maxFreq;
            maxFreq=0;
            freq.clear();
            flag=1;
            freq[prefixSums[i]]++;
            if(freq[prefixSums[i]]>maxFreq){
                maxFreq = freq[prefixSums[i]];
            }
            continue;
        }
        else if(flag==1){
            freq[prefixSums[i]]++;
            if(freq[prefixSums[i]]>maxFreq){
                maxFreq = freq[prefixSums[i]];
            }
        }
        else if(flag==0 && prefixSums[i]==0){
            score++;
        }
    }
    if(flag==1)
        score+=max<ll>(maxFreq,1);
    score = max<ll>(score,ogScore);
    cout<<score<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vecll nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,n);
    }
    return 0;
}