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

void helper(ll n,ll x)
{
    if(n==x){
        cout<<n<<endl;
        return;
    }
    int leftMostZero=-1;
    int firstMatchedOne=INT_MAX;
    ll copyN,copyX;
    copyN=n;
    copyX=x;
    //n x
    //10 8
    //1010 1000
    //lm=1
    //fm=3

    for(int i=0;i<62;i++){
        ll rightN,rightX;
        copyN=n;
        copyX=x;
        // cout<<copyN;
        // cout<<(copyN>>i&1);
        rightN = (copyN>>i & 1LL);
        rightX = (copyX>>i & 1LL);
        if(rightN==1 && rightX==1){
            if(firstMatchedOne==INT_MAX){
                firstMatchedOne=i;
            }
        }
        else if(rightN==0 && rightX==1){
            cout<<-1<<endl;
            return;
        }
        else if(rightN==1 && rightX==0){
            // cout<<i<<endl;
            leftMostZero = i;
        }
    }
    if(leftMostZero>firstMatchedOne){
        // cout<<leftMostZero<<" "<<firstMatchedOne<<endl;
        cout<<-1<<endl;
        return;
    }
    if((copyN>>(leftMostZero+1) & 1LL)==1){
        cout<<-1<<endl;
        return;
    }
    // cout<<leftMostZero<<" "<<firstMatchedOne<<endl;
    ll toMake = pow(2,leftMostZero);
    ll temp = 0;
    for(int i=0;i<leftMostZero;i++){
        temp = temp<<1;
        temp = temp | 1;
    }
    ll weHave = temp & copyN;
    ll m = toMake - weHave;
    cout<<n+m<<endl;
}
//10 8
//1010 0100
//3 2
//011 
//010
//100 -> 101 -> 110. thus leftmost ke turant baad ek req one nhi hone chahiye firstly.
//3 1
//011
//001


int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        helper(n,x);
    }
    return 0;
}