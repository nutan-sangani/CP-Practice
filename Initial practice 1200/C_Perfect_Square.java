import java.util.*;

public class C_Perfect_Square
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
            int[][] nums = new int[n][n];
            for(int i=0;i<n;i++)
            {
                String ithRow = sc.next();
                for(int j=0;j<n;j++)
                {
                    nums[i][j] = ithRow.charAt(j);
                }
            }
            s.helper(nums,n);
        }
        sc.close();
    }
}

class Solution {
    public void helper(int[][] nums,int n)
    {
        long cost=0;
        for(int border=0;border<n/2;border++)
        {
            int[] lastRow,lastCol,firstRow,firstCol = new int[2]; //4 pointers for every border like css box model
            lastRow=new int[2];
            lastCol=new int[2];
            firstRow=new int[2];
            firstCol = new int[2];
            lastRow[0]=n-1-border;
            lastRow[1]=n-1-border;
            lastCol[0]=border;
            lastCol[1]=n-1-border;
            firstRow[1]=border;
            firstRow[0]=border;
            firstCol[0]=n-1-border;
            firstCol[1]=border;
            while(firstRow[1]<n-1-border)
            {
                int[] arr = new int[4];
                arr[0] = nums[firstCol[0]][firstCol[1]];
                arr[1] = nums[firstRow[0]][firstRow[1]];
                arr[2] = nums[lastCol[0]][lastCol[1]];
                arr[3] = nums[lastRow[0]][lastRow[1]];
                Arrays.sort(arr);
                int tempCost=0;
                for(int i=0;i<4;i++)
                {
                    tempCost += (arr[3]-arr[i]);
                }
                cost+=(tempCost+0L);
                firstCol[0]--;
                firstRow[1]++;
                lastCol[0]++;
                lastRow[1]--;
            }
        }
        System.out.println(cost);
    }
}