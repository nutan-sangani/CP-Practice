import java.util.*;

public class B_A_Balanced_Problemset
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
            long n,k;
            n=sc.nextLong();
            k=sc.nextLong();
            s.helper(n,k);
        }
    }
}

class Solution {
    public void helper(long n,long k)
    {
        long upperLimit = n/k;
        if(n%k==0){
            System.out.println(upperLimit);
            return;
        }
        for(long i = upperLimit;i>=1;i--){
            long rem = (n-(i*(k-1)));
            if(rem%i==0){
                System.out.println(i);
                // System.out.println("this "+rem+" "+upperLimit+" "+(k-1));
                return;
            }
        }
        System.out.println(1);
        return;
    }
}