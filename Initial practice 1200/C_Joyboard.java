import java.util.*;

public class C_Joyboard
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
            int n,m,k;
            n=sc.nextInt();
            m=sc.nextInt();
            k=sc.nextInt();
            s.helper(n,m,k);
        }
        sc.close();
    }
}

class Solution {
    public void helper(int n,int m,int k)
    {
        if(k>3){
            System.out.println(0);
            return;
        }
        if(k==1){
            System.out.println(1);
            return;
        }
        else if(k==2){
            int fromSmaller = Math.min(m, n-1);
            int fromMultipleOfN = m/n;
            int ans = fromMultipleOfN+fromSmaller;
            System.out.println(ans);
            return;
        }
        else if(k==3){
            int fromGreater = m-n;
            int fromMultipleOfN = (m/n) - 1;
            int ans = fromGreater - fromMultipleOfN;
            if(ans>=0)
                System.out.println(ans);
            else 
                System.out.println(0);
            return;
        }
        return;
    }
}