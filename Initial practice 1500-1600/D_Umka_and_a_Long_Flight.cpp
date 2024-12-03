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

bool ans=true;
ll dp[50];

ll findFib(ll n){
    if(n==0 || n==1) return 1;
    if(dp[n]!=0) return dp[n];
    else return dp[n]=findFib(n-1)+findFib(n-2);
}

bool checkOutOfPart(pair<ll,ll>& range,ll x){
    if(x>=range.first && x<=range.second) return false;
    return true;
}

void recur(ll height,ll width,ll lowR,ll highR,ll lowC,ll highC,ll x,ll y)
{
    if((height==2 && width==1)){
        if((x==lowR && y==lowC) || (x==highR && y==lowC)) ans=true;
        return;
    }
    else if((height==1 && width==2)){
        if((x==lowR && y==lowC) || (x==highR && y==highC)) ans=true;
        return;
    }
    if(height < width){
        ll mini = height;
        pair<ll,ll> firstPart,secondPart;
        firstPart.first=lowC;
        firstPart.second = lowC+mini-1;
        secondPart.first = highC-mini+1;
        secondPart.second = highC;
        if(checkOutOfPart(firstPart,y)){
            ll rem = width-mini;
            recur(height,rem,lowR,highR,firstPart.second+1,highC,x,y);
            return;
        }
        else if(checkOutOfPart(secondPart,y)){
            ll rem = width-mini;
            recur(height,rem,lowR,highR,lowC,secondPart.first-1,x,y);
            return;
        }
        else return; //ie false.
    }
    else if(height>width){
        ll mini=width;
        pair<ll,ll> firstPart,secondPart;
        firstPart.first=lowR;
        firstPart.second=lowR+mini-1;
        secondPart.first=highR-mini+1;
        secondPart.second=highR;
        if(checkOutOfPart(firstPart,x)){
            ll rem = height - mini;
            recur(rem,width,firstPart.second+1,highR,lowC,highC,x,y);
            return;
        }
        else if(checkOutOfPart(secondPart,x)){
            ll rem = height - mini;
            recur(rem,width,lowR,secondPart.first-1,lowC,highC,x,y);
            return;
        }
        else return; //ie false.
    }
}

void helper(ll n,ll x,ll y)
{
    if(n==1){
        cout<<"YES"<<endl;
        return;
    }
    ans=false;
    ll height = findFib(n);
    ll width = findFib(n+1);
    recur(height,width,1,height,1,width,x,y);
    if(ans){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
    return;
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
        helper(n,x,y);
    }
    return 0;
}