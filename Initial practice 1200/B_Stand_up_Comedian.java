import java.util.*;

public class B_Stand_up_Comedian
{
    public static void main(String[] args) {
        int t=0;
        Scanner sc = new Scanner(System.in);
        Solution s = new Solution();
        t = sc.nextInt();
        sc.nextLine();
        while(t>0)
        {
            t--;
            long a1,a2,a3,a4;
            a1=sc.nextLong();
            a2=sc.nextLong();
            a3=sc.nextLong();
            a4=sc.nextLong();
            s.helper(a1,a2,a3,a4);   
        }
    }
}

class Solution {
    public void helper(long a1,long a2,long a3,long a4)
    {
        if(a1==0){
            System.out.println(1);
            return;
        }
        long ans=0;
        long mini=Math.min(a2, a3);
        long maxi=Math.max(a2, a3);
        long alice,bob;
        alice=bob=0;
        ans+=a1;

        alice+=a1;
        bob+=a1;

        ans+=mini;
        alice+=mini;
        bob-=mini;

        long maxUsable = a1+mini;
        long maxUsed = Math.min(maxi, maxUsable);
        ans+=maxUsed;
        maxi-=maxUsed;

        alice-=maxUsed;
        bob+=maxUsed;

        if(alice>=0 && bob>=0){
            long limiter = Math.min(alice, bob);
            long a4Used = Math.min(a4, limiter);
            ans+=a4Used;
            a4-=a4Used;
            if(a4>0 || maxi>0){
                ans+=1;
            }
        }
        
        System.out.println(ans);
    }
}
//5 3 5 0 
//0 3 5 0 - 5 5
//0 0 5 0 - 8 2
//0 0 0 0 - 3 7

//2 3 5 0
//0 3 5 0 - 2 2
//0 0 5 0 - 5 -1
//0 0 0 0 - 0 4

//2 5 10 0
//0 5 10 0 - 2 2
//0 0 10 0 - 7 -3
//0 0 3 0 - 0 4
//0 0 2 0 - (-1) 4

//3 3 0 7
//0 3 0 7 - 3 3
//0 0 0 7 - 6 0
//0 0 0 6 - 5 -1

//3 5 0 7
//0 5 0 7 - 3 3
//0 2 0 7 - 6 0
//0 1 0 7 - 7 -1

//10 2 2 7
//0 2 2 7 - 10 10
//0 0 2 7 - 12 8
//0 0 0 7 - 10 10
//0 0 0 0 - 3 3