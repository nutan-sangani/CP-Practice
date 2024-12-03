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
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x,y;
        cin>>n>>x>>y;
        vecll nums(n,-1);
        int s=-1;
        if(y%2!=0) s=1;
        forLoop
        {
            if(i+1>=y && i+1<=x){
                nums[i]=1;
                if(i+1==x){
                    s=-1;
                }
                continue;
            }
            nums[i]=s;
            s=s==-1? 1 : -1;
        }
        forLoop
            cout<<nums[i]<<" ";
        cout<<endl;
    }
    return 0;
}