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

void helper(vector<vecll>& str,int n,int m)
{
    unordered_map<ll,vecll> map;
    // cout<<-2<<endl;
    int sum=0;
    vecll oneCount(n,0);
    for(int i=0;i<n;i++)
    {
        int temp=0;
        for(int j=0;j<m;j++)
        {
            if(str[i][j]==1){
                temp++;
                sum++;
                map[j].pb(i);
            } 
        }
        oneCount[i]=temp;
    }
    if(sum%n!=0){
        cout<<-1<<endl;
        return;
    } 
    int target = sum/n;
    int moves=0;
    forLoop
    {
        if(oneCount[i]<target){
            int diff = target - oneCount[i];
            moves+=diff;
        }
        // cout<<oneCount[i]<<endl;
    }
    cout<<moves<<endl;
    for(int i=0;i<n;i++){
        if(oneCount[i]<target){
            int diff = target - oneCount[i];
            int j=0;
            while(j<m && diff>0){
                if(str[i][j]==0){
                    int flag=1;
                    if(map[j].size()>0){
                        while(flag && map[j].size()>0)
                        {
                            int size=map[j].size();
                            if(oneCount[map[j][size-1]]>target){
                                cout<<i+1<<" "<<map[j][map[j].size()-1]+1<<" "<<j+1<<endl;
                                diff--;
                                flag=0;
                                oneCount[map[j][size-1]]--;
                            }
                            map[j].pop_back();
                        }
                    }
                }
                j++;
            }
        }
    }
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vecll> strs;
        for(int i=0;i<n;i++){
            vecll temp;
            for(int j=0;j<m;j++){
                int a;
                cin>>a;
                temp.pb(a);
            }
            strs.pb(temp);
        }
        helper(strs,n,m);
    }
    return 0;
}