import java.util.*;

public class B_Fancy_Coins
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
            long target,k,oneCount,kCount;
            target=sc.nextLong();
            k=sc.nextLong();
            oneCount=sc.nextLong();
            kCount=sc.nextLong();
            s.helper(target,k,oneCount,kCount);
        }
    }
}

class Solution {
    public void helper(long target,long k,long oneCount,long kCount)
    {
        //make with given coins
        long remaining = (target*1L - k*kCount*1L)+0L;
        long ans=0;
        if(remaining>=0 && remaining<=oneCount){
            System.out.println(ans);
            return;
        }
        long totalKNeeded = target/k; //0
        long totalOneNeeded = (target*1L - totalKNeeded*k*1L+0L); //1
        long oneLeftToFill = (totalOneNeeded - oneCount)*1L; //1
        if(oneLeftToFill<0)
        {
            oneCount = (-1*oneLeftToFill);
            oneLeftToFill=0L;
        }
        else oneCount=0L;
        long extraKNeeded = totalKNeeded - kCount - oneCount/k;
        if(extraKNeeded<0) extraKNeeded=0;
        System.out.println(extraKNeeded+oneLeftToFill);
        return;
    } 
}