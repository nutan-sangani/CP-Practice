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

int countOfDigits(ll a){
    return floor(log10(a))+1;
}

int getSumOfDigits(ll a){
    int digits = countOfDigits(a);
    int sum=0;
    int i=0;
    ll copy=a;
    while(i<digits){
        sum+=(copy)%10;
        copy/=10;
        i++;
    }
    return sum;
}

void helper(vecll& nums,int n,int q)
{
    omll count; //num : freq
    int i=0;
    for(i=0;i<n;i++){
        count[i+1]=0;
    }
    i=0;
    while(i<q){
        int choice;
        cin>>choice;
        i++;
        if(choice==1){
            ll l,r;
            cin>>l>>r;
            if(count.empty()){
                continue;
            }
            omll::iterator iter = count.lower_bound(l);
            if(iter==count.end()){
                 continue;
            }
            // cout<<"thus : "<<l<<" "<<r<<endl;
            vecll toDelete;
            for(iter;iter!=count.end() && iter->first<=r;iter++){
                iter->second = iter->second+1;
                if(iter->second>=3){
                    toDelete.pb(iter->first);
                }
                // cout<<"this : "<<iter->first<<endl;
            }
            for(ll item : toDelete){
                    count.erase(item);
            }
        }
        else{
            ll index;
            cin>>index;
            if(index-1<0 || index-1>=n){
                cout<<index-1+n<<endl; //206
                //204+x = 206
                //x=2, thus n=2, ye kese be?
                continue;
            }
            if(count.count(index)==0){
                int sum = getSumOfDigits(nums[index-1]);
                sum=getSumOfDigits(sum);
                sum=getSumOfDigits(sum);
                cout<<sum<<endl;
            }
            else{
                int val = count[index];
                if(index-1<0 || index-1>=n){
                    cout<<index-1+n<<endl;
                    continue;
                }
                int sum=nums[index-1];
                while(val){
                    val--;
                    sum=getSumOfDigits(sum);
                }
                cout<<sum<<endl;
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
        int n,q;
        cin>>n>>q;
        vecll nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,n,q);
        // cout<<0/10<<endl;
        // cout<<0%10<<endl;
    }
    return 0;
}