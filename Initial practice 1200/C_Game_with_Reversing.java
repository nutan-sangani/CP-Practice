import java.util.*;

public class C_Game_with_Reversing
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
            String one,two;
            int n = sc.nextInt();
            one=sc.next();
            two=sc.next();
            s.helper(one,two,n);
        }
    }
}

class Solution {
    public void helper(String s,String t,int n)
    {
        int normalCount=0;
        int reversedCount=0;
        String copy = new String(s);
        String reversed = new StringBuilder(copy).reverse().toString();
        int mini=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            if(s.charAt(i)!=t.charAt(i)){
                normalCount++;
            }
            if(reversed.charAt(i)!=t.charAt(i)){
                reversedCount++;
            }
        }
        if(normalCount==0){
            System.out.println(0);
            return;
        }
        if(reversedCount==0){
            System.out.println(2);
            return;
        }
        if(normalCount == reversedCount) {
            System.out.println(normalCount+(normalCount-1));
            return;
        }
        if((normalCount-1)%2==0){ //ie further no reversion
            int temp = (normalCount)+(normalCount-1);
            mini=Math.min(mini, temp);
        }
        else{
            int temp = (normalCount)+(normalCount-1)+1;
            mini=Math.min(mini, temp);
        }
        if((reversedCount-1)%2==0){
            int temp = (reversedCount)+(reversedCount-1)+1;
            mini=Math.min(mini, temp);
        }
        else{
            int temp = (reversedCount)+(reversedCount-1);
            mini=Math.min(mini, temp);
        }
        System.out.println(mini);
    }
}