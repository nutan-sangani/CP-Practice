import java.util.*;

public class D_Remove_Two_Letters
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
            int n=sc.nextInt();
            String str=sc.next();
            s.helper(str,n);
        }
    }
}

class Solution {
    public void helper(String s,int n)
    {
        int count=0;
        for(int i=0;i<n-1;i++){
            if(i==0){
                count++;
                continue;
            }
            int prev=i-1;
            int end=i+1;
            if(s.charAt(prev)==s.charAt(end)){
                continue;
            }
            count++;
        }
        System.out.println(count);
        return;
    }
}