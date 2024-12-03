#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair

using namespace std;

void helper(int n,int m,ll nums[],vector<pii>& q)
{
    vector<pll> psl; //pair of sum : count
    vector<pll> psr;
    for(int i=0;i<n;i++){
        int prevIndex = i-1;
        if(prevIndex>0){
            if(abs(nums[prevIndex]-nums[i])<abs(nums[prevIndex-1]-nums[prevIndex]))
            {
                psl.pb(mp(psl[prevIndex].first,psl[prevIndex].second));
            }
            else{
                psl.pb(mp((psl[prevIndex].first+abs(nums[i]-nums[prevIndex])),psl[prevIndex].second+1));
            }
        }
        else{
            psl.pb(mp(0,0));
        }
    }
    int j=0;
    for(int i=n-1;i>=0;i--){
        int nextIndex = i+1;
        if(nextIndex<n-1){
            if(abs(nums[i]-nums[nextIndex])<abs(nums[nextIndex]-nums[nextIndex+1])){
                psr.pb(mp(psr[j-1].first,psr[j-1].second));
            }
            else{
                psr.pb(mp(psr[j-1].first+(abs(nums[nextIndex]-nums[i])+0LL),psr[j-1].second+1LL));
            }
        }
        else{
            psr.pb(mp(0LL,0LL));
        }
        j++;
    }
    reverse(psr.begin(),psr.end());
    for(int i=0;i<m;i++){
        int x,y;
        x=q[i].first-1;
        y=q[i].second-1;
        if(x<y){
            ll cost = (psl[y].first - psl[x].first+0LL);
            cost+=(y-x-(psl[y].second-psl[x].second))*1LL;
            cout<<cost<<endl;
        }
        else{
            ll cost = (psr[y].first - psr[x].first+0LL);
            cost+=(x-y-(psr[y].second-psr[x].second))*1LL;
            cout<<cost<<endl;
        }
    }
    // for(int i=0;i<n;i++)
    //     cout<<psr[i].first<<" "<<psr[i].second<<endl;
        // cout<<1<<1<<1<<1;
    return;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll nums[n];
        forLoop
        {
            cin>>nums[i];
        }
        int m;
        cin>>m;
        vector<pii> q;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x;
            cin>>y;
            q.pb(make_pair(x,y));
        }
        helper(n,m,nums,q);
    }
    return 0;
}