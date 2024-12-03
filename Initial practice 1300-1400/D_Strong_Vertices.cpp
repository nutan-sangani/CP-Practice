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

void helper(vecll& a, vecll& b,int n)
{
    // vecll diff(n);
    vector<pair<ll,int>> diff(n);
    forLoop
        diff[i]=make_pair(a[i]-b[i],(i+1));
    sort(diff.begin(),diff.end());
    ll max=INT_MIN;
    ll count=0;
    forLoop
        if(diff[i].first>max){
            max=diff[i].first;
        }
    vecll ans;
    forLoop
        if(diff[i].first==max){
            ans.pb(diff[i].second);
            count++;
        }
    cout<<count<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return;
}//-1,-2,0,3
//-2,-1,0,3

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vecll a(n);
        vecll b(n);
        forLoop
            cin>>a[i];
        forLoop
            cin>>b[i];
        helper(a,b,n);
    }
    return 0;
}