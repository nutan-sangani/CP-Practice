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
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

bool isValid(vecll& a,int mid,int n){
    if(mid==1) return true;
    int distinctElementsRepeated = 0;
    umll freqOf;
    forn(0,mid){
        ++freqOf[a[i]];
        if(freqOf[a[i]]==2){
            distinctElementsRepeated+=1;
        }
    }
    forn(0,n){
        int start=i;
        int end=i+(mid-1);
        if(end>=n) break;
        if(distinctElementsRepeated==0){
            return true;
        }
        freqOf[a[start]]-=1;
        if(freqOf[a[start]]==1){
            distinctElementsRepeated-=1;
        }
        if((end+1)<n){
            ++freqOf[a[end+1]];
            if(freqOf[a[end+1]]==2){
                distinctElementsRepeated+=1;
            }
        }
    }
    return false;
}

void solve(){
    int n;
    cin>>n;
    vecll a(n,0);
    ll uniqueCount=0;
    um<ll,ll,custom_hash> freqOf;
    bool flag=false;
    forn(0,n){
        cin>>a[i];
        freqOf[a[i]]++;
        if(flag) continue;
        if(freqOf[a[i]]==1) ++uniqueCount;
        else flag=true;
    }
    int low,high;
    low = 1;
    high = n;
    if(uniqueCount==n){
        cout<<n<<endl;
        return;
    }
    else --high;
    while(low<=high){
        int mid = (low+high)/2;
        if(isValid(a,mid,n)){
            low=mid+1;
        }
        else high=mid-1;
    }
    cout<<high<<endl;
}
//this approach uses nlogn which is giving close TLE, can solve using sliding window, but too lazy
//to implement that approach.

//honestly speaking, isko optimize krne me bahot kuch sikhne mile aur jyada maza aaya.
int main()
{
    FASTIO
    solve();
    return 0;
}