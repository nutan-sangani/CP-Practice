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
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

void helper(vecll& nums,ll n,ll x,ll y)
{
    priority_queue<ll,vecll,greater<ll>> even;
    priority_queue<ll,vecll,greater<ll>> odd;
    ll count=0;
    sort(itr(nums));
    ll yCopy = y;
    forn(0,x){
        if(i==x-1){
            ll diff = n - nums[x-1];
            diff+=nums[0];
            if(diff & 1LL) odd.push(diff);
            else even.push(diff);
        }
        else{
            ll nextPoint = nums[i+1];
            ll diff = (nextPoint - nums[i]);
            if(diff & 1LL) odd.push(diff);
            else even.push(diff);
        }
    }
    while(!even.empty()){
        if(even.top()==2){
            even.pop();
            count++;
        }
        else break;
    }
    while(!even.empty() && y){
        ll top = even.top();
        even.pop();
        ll additionalPoints = top/2;
        ll needed = additionalPoints - 1;
        if(y>=needed){
            y-=needed;
            count+=additionalPoints;
        }
        else{
            count+=y;
            y=0;
        }
    }
    while(!odd.empty() && y){
        ll top = odd.top();
        odd.pop();
        ll addtionalPoints = top/2;
        ll pointsAdded = min<ll>(y,addtionalPoints);
        y-=pointsAdded;
        count+=pointsAdded;
    }
    if(y>0){
        yCopy-=y;
    }
    count+=(x+yCopy-2);
    cout<<count<<endl;
    return;
}
//1 2 5 6
//3,

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x,y;
        cin>>n>>x>>y;
        vecll nums(x,0);
        forn(0,x) cin>>nums[i];
        helper(nums,n,x,y);
    }
    return 0;
}