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

bool isValid(vecll& nums,int n,int k)
{
    int gcdVal = -1;
    for(int i=0;i<k;i++){
        int j=i;
        vecll temp;
        while((j)<n){
            temp.pb(nums[j]);
            j+=k;
        }
        sort(temp.begin(),temp.end());
        if(temp[0]==temp[temp.size()-1])
            continue;
        for(int i=0;i<temp.size()-1;i++){
            int diff = temp[i+1]-temp[i];
            if(diff!=0 && gcdVal==-1){
                gcdVal=diff;
            }
            if(diff!=0)
                gcdVal=gcd(gcdVal,diff);
        }
    }
    if(gcdVal>1 || gcdVal==-1) return true;
    return false;
}

void helper(vecll& nums,int n)
{
    if(n==1){
        cout<<1<<endl;
        return;
    }
    else if(n==2){
        if(nums[0]==nums[1]){
            cout<<2<<endl;
            return;
        }
        cout<<1<<endl;
        return;
    }
    vecll multiples;
    for(int i=1;i<=(sqrt(n)+1);i++){
        if(n%i==0){
            multiples.pb(i);
            if(i!=(n/i))
                multiples.pb(n/i);
        }
        // cout<<i<<" "<<n/i<<endl;
    }
    int count=0;
    int size = multiples.size();
    umll map;
    for(int i=0;i<size;i++){
        if(map[multiples[i]]==0 && multiples[i]!=n && isValid(nums,n,multiples[i])){
            count++;
            // cout<<multiples[i]<<endl;
        }
        map[multiples[i]]=1;
    }
    cout<<count+1<<endl;
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
//1,2,3,6
//