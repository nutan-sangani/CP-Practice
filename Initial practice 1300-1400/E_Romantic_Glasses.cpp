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
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
            if(i%2==0)
                nums[i]*=-1;
        }
        long long sum=0;
        map<long long,int> seti;
        int isDone=0;
        for(int i=0;i<n;i++)
        {
            if(!seti[sum]){
                seti[sum]=1;
            }
            else{
                cout<<"YES"<<endl;
                isDone=1;
                break;
            }
            sum+=(nums[i]);
        }
        if(isDone) continue;
        if(!seti[sum])
            cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}

//bhai, ye question ne tare dikha diye the, since tc 16 me there was some value jo hashmap ko todd rha tha
//phir unordered_map k badle ordered_map use kiya, toh submit hua.
//thus use hashmap in competition with caution.