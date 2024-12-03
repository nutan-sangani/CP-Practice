import java.util.*;

public class D_Find_the_Different_Ones
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
            int[] nums=new int[n];
            for(int i=0;i<n;i++){
                nums[i]=sc.nextInt();
            }
            int q=sc.nextInt();
            int[][] query = new int[q][2];
            for(int i=0;i<q;i++){
                int a,b;
                a=sc.nextInt();
                b=sc.nextInt();
                query[i][0]=a;
                query[i][1]=b;
            }
            s.helper(nums,query,n,q);
        }
    }
}

class Solution {
    public void helper(int[] nums,int[][] query,int n,int q)
    {
        TreeSet<Integer> set = new TreeSet<>();
        for(int i=0;i<n;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                set.add(i+1);
            }
        }
        for(int i=0;i<q;i++){
            if(set.ceiling(query[i][0])==null || set.floor(query[i][1])==null){
                System.out.println("-1 -1");
                continue;
            }
            int lowerLimit = set.ceiling(query[i][0]);
            int upperLimit = set.floor(query[i][1]);
            if(lowerLimit>upperLimit){
                System.out.println("-1 -1");
                continue;
            }
            if(lowerLimit==upperLimit){
                int diff1,diff2;
                diff1 = lowerLimit - query[i][0];
                diff2 = query[i][0] - upperLimit;
                if(diff1>0){
                    System.out.println(query[i][0]+" "+lowerLimit);
                }
                else if(diff2>0){
                    System.out.println(query[i][1]+" "+upperLimit);
                }
                else{
                    System.out.println("-1 -1");
                }
                continue;
            }
            else if(lowerLimit!=upperLimit){
                if(nums[lowerLimit-1]==nums[upperLimit-1]){
                    if(set.lower(upperLimit)==null || set.lower(upperLimit)<query[i][0]){
                        System.out.println("-1 -1");
                        continue;
                    }
                    int newUpperLimit = set.lower(upperLimit);
                    System.out.println(lowerLimit+" "+newUpperLimit);
                }
                else System.out.println(lowerLimit+" "+upperLimit);
            }
        }
        System.out.println();
    }
}
//1,2,4,6
