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

vecll findPrimeFactors(ll n){
    vecll ans;
    int flag=0;
    while(n%2==0){
        if(flag==0)
            ans.pb(2);
        n/=2;
        flag=1;
    }
    for(int i=3;i<=(sqrt(n)+1);i+=2){
        flag=0;
        while(n%i==0){
            if(flag==0)
                ans.pb(i);
            n/=i;
            flag=1;
        }
    }
    if(n!=1){
        ans.pb(n);
    }
    return ans;
}

void helper(vecll& nums,int n)
{
    umll prime_freq;
    int countOfOnes=0;
    forLoop
    {
        if(nums[i]==1){
            countOfOnes++;
        }
    }
    if(countOfOnes>=1){
        int rem = n - countOfOnes;
        cout<<rem<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        vecll temp = findPrimeFactors(nums[i]);
        int m=temp.size();
        for(int j=0;j<m;j++)
            prime_freq[temp[j]]++;
    }
    for(auto it: prime_freq){
        if(it.second!=n){
            cout<<n<<endl;
            return; 
        }
    }
    cout<<-1<<endl;
}

int main()
{
    FASTIO
    
    int n;
    cin>>n;
    vecll nums(n);
    forLoop
        cin>>nums[i];
    helper(nums,n);
    return 0;
}
//brute force se kar sakte.