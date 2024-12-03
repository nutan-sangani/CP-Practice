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

ll getCarry(ll i){
    return i/10;
}

ll getLastDigit(ll i){
    return i%10;
}

void helper(string s,int n)
{
    vecll prefixSum(n);
    ll sum=0;
    forLoop
    {
        sum+=((s[i]-'0')*1LL);
        prefixSum[i]=sum;
    }
    string ans=s;
    ll carry=0;
    int j=n-1;
    //0005
    forLoop
    {
        sum=prefixSum[j];
        sum+=carry;
        carry=0;
        ll last = getLastDigit(sum);
        carry = getCarry(sum);
        ans[j]=(last+'0');
        j--;
    }
    if(carry>0){
        char a = ('0'+carry);
        ans=a+ans;
        // cout<<ans;
    }
    int leadingZeros=0;
    forLoop
    {
        if(ans[i]=='0'){
            leadingZeros++;
        }
        else break;
    }
    ans.erase(0,leadingZeros);
    cout<<ans<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        helper(s,n);
    }
    return 0;
}