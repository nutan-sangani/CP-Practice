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

class MyComp{
    public :
    bool operator()(pair<ll,ll>a,pair<ll,ll>b){
        if(a.first!=b.first)
            return a.first < b.first;
        return a.second<b.second;
    }
};

void helper(int n,vector<pair<ll,ll>>& intervals)
{
    sort(intervals.begin(),intervals.end(),MyComp());
    int reach=-1;
    for(int i=0;i<n-1;i++){
        if(intervals[i].second >= intervals[i+1].first){
            int overlappingL,overlappingR;
            overlappingL= max<ll>(intervals[i].first,intervals[i+1].first);
            // overlappingR = min<ll>(intervals[i].second,intervals[i+1].second);
            if(reach>=overlappingL){
                cout<<"NO"<<endl;
                return;
            }
        }
        reach = max<ll>(reach,intervals[i].second);
    }
    cout<<"YES"<<endl;
    return;
}

int main()
{
    FASTIO
    
    int n;
    cin>>n;
    vector<pair<ll,ll>> intervals(n);
    forLoop
    {
        int a,b;
        cin>>a>>b;
        intervals[i]=mp(a,b);
    }
    if(n<3){
        cout<<"YES"<<endl;
        return 0;
    }
    helper(n,intervals);
    return 0;
}
//(0,1),(1,2),(2,3),(3,4)
