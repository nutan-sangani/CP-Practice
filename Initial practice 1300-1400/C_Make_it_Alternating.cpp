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
#define mod 998244353LL

using namespace std;

ll findFactorial(ll i){
    if(i<=0) return 1;
    if(i<=2){
        return i;
    }
    else return (i*findFactorial(i-1))%mod;
}
void helper(string s)
{
    ll size=0;
    int n=s.size();
    vecll count;
    for(int i=0;i<n;)
    {
        int j=i;
        while(s[j]==s[i]){
            j++;
        }
        count.pb(j-i);
        i=j;
    }
    int k = count.size();
    ll permutation = findFactorial(n-k); //the formula is, countOfCombination*countOfPermutation.
    ll combination=1;
    for(int i=0;i<k;i++){
        combination*=(count[i]*1LL);
        combination%=mod;
    }
    cout<<(n-k)<<" "<<(permutation*combination)%mod<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        helper(s);
    }
    return 0;
}



// 1
// 0
// 10
// 11
// 00
// 01
// 100
// 101
// 110
// 111
// 000
// 001
// 010
// 011
// 1000
// 1001
// 1010
// 1011
// 1100
// 1101
// 1110
// 1111
// 0000
// 0001
// 0010
// 0011
// 0100
// 0101
// 0110
// 0111
// 10000
// 10001
// 10010
// 10011
// 10100
// 10101
// 10110
// 10111
// 11000
// 11001
// 11010
// 11011
// 11100
// 11101
// 11110
// 11111
// 00000
// 00001
// 00010
// 00011
// 00100
// 00101
// 00110
// 00111
// 01000
// 01001
// 01010
// 01011
// 01100
// 01101
// 01110
// 01111
// 100000
// 100001
// 100010
// 100011
// 100100
// 100101
// 100110
// 100111
// 101000
// 101001
// 101010
// 101011
// 101100
// 101101
// 101110



// 0 1
// 0 1
// 0 1
// 1 2
// 1 2
// 0 1
// 1 2
// 0 1
// 1 2
// 2 6
// 2 6
// 1 2
// 0 1
// 1 2
// 2 6
// 1 2
// 0 1
// 1 2
// 2 8
// 1 2
// 2 6
// 3 24
// 3 24
// 2 6
// 1 2
// 2 8
// 1 2
// 0 1
// 1 2
// 2 6
// 3 24
// 2 6
// 1 2
// 2 8
// 1 2
// 0 1
// 1 2
// 2 6
// 3 36
// 2 8
// 1 2
// 2 8
// 3 36
// 2 6
// 3 24
// 4 120
// 4 120
// 3 24
// 2 6
// 3 36
// 2 8
// 1 2
// 2 8
// 3 36
// 2 6
// 1 2
// 0 1
// 1 2
// 2 8
// 1 2
// 2 6
// 3 24
// 4 120
// 3 24
// 2 6
// 3 36
// 2 8
// 1 2
// 2 8
// 3 36
// 2 6
// 1 2
// 0 1
// 1 2
// 2 8
// 1 2
// 2 6
// 3 24
// 4 192
// 3 36
// 2 8
// 3 48
// 2 8
// 1 2
// 2 8
// 3 36
// 4 216
// 3 36
// 2 6
// 3 36
// 4 192
// 3 24
// 4 120
// 5 720