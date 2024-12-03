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
        int n,k,m;
        cin>>n>>m>>k;
        vecll nums(m);
        ll max=-1;
        // if(k>m){
        //     cout<<"NO"<<endl;
        //     continue;
        // }
        for(int i=0;i<m;i++){
            cin>>nums[i];
            if(nums[i]>max){
                max=nums[i];
            }
        }
        int rounds = n/k;
        if(n%k!=0){
            rounds++;
            if(max==rounds){
                int count=0;
                for(int i=0;i<m;i++){
                    if(nums[i]==rounds){
                        count++;
                    }
                }
                if(count>n%k){
                    cout<<"NO"<<endl;
                    continue;
                }
            }
        }
        if(max>rounds)
            cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}