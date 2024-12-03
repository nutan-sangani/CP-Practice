import java.util.*;
import java.util.TreeMap;

public class C_Binary_String_Copying
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
            int n,m;
            n=sc.nextInt();
            m=sc.nextInt();
            sc.nextLine();
            String str = sc.nextLine();
            // System.out.println(n+" "+m);
            int[][] nums = new int[m][2];
            for(int i=0;i<m;i++){
                int x,y;
                if (sc.hasNextInt()) {
                    x = sc.nextInt();
                } else {
                    break;
                }
                if (sc.hasNextInt()) {
                    y = sc.nextInt();
                } else {
                    break;
                }
                nums[i][0]=x-1;
                nums[i][1]=y-1;
                // System.out.println(m+" "+x+" "+y);
            }
            s.helper(nums,n,m,str);
        }
    }
}

class Pair{
        int value;
        int index;
        public Pair(int value,int index){
            this.value=value;
            this.index=index;
        }

        @Override
        public boolean equals(Object o){
            Pair a = (Pair) o;
            if(a.index==this.index && a.value==this.value) return true;
            return false;
        }

        @Override
        public int hashCode() {
            return Objects.hash(value, index);
        }
}

class Solution {

    private boolean checkAllZeros(int l,int r,TreeMap<Integer,Integer> zeros){
        if(l==r) return true;
        if(zeros.floorKey(l)==null) return false;
        int zeroBegining = zeros.floorKey(l);
        int zeroCount = zeros.get(zeroBegining);
        if(zeroBegining+zeroCount>r)   return true;
        return false;
    }

    private boolean checkAllOnes(int l,int r,TreeMap<Integer,Integer> ones){
        if(l==r) return true;
        if(ones.floorKey(l)==null) return false;
        int oneBegining = ones.floorKey(l);
        int oneCount = ones.get(oneBegining);
        if(oneBegining+oneCount>r){
            return true;
        }
        return false;
    }

    private boolean checkSorted(int l,int r,TreeMap<Integer,Integer> zeros,TreeMap<Integer,Integer> ones){
        if(l==r) return true;
        if(zeros.floorKey(l)==null || ones.floorKey(r)==null) return false;
        int zeroBegining = zeros.floorKey(l);
        int oneBegining = ones.floorKey(r);
        int oneCount = ones.get(oneBegining);
        int zeroCount = zeros.get(zeroBegining);
        int zeroReach = zeroBegining+zeroCount;
        if(zeroReach==oneBegining && oneBegining+oneCount>r) return true;
        return false;
    }

    public void helper(int[][] nums,int n,int m,String s)
    {
        TreeMap<Integer,Integer> zeros = new TreeMap<>();
        TreeMap<Integer,Integer> ones = new TreeMap<>();
        int i=0;
        while(i<n){
            if(s.charAt(i)=='0'){
                int count=0;
                int j=i;
                while(i<n && s.charAt(i)=='0'){
                    i++;
                    count++;
                }
                // System.out.println("zero "+j+" "+count);
                zeros.put(j, count);
            }
            else {
                int count=0;
                int j=i;
                while(i<n && s.charAt(i)=='1'){
                    i++;
                    count++;
                }
                // System.out.println("one "+j+" "+count);
                ones.put(j, count);
            }
        }
        Set<Pair> set = new HashSet<>();
        int flag=0;
        int ans=0;
        for(i=0;i<m;i++){
            if(checkAllOnes(nums[i][0], nums[i][1], ones) || checkAllZeros(nums[i][0], nums[i][1], zeros)
                || checkSorted(nums[i][0], nums[i][1], zeros, ones))
            {
                // set.add(new Pair(0,n-1));
                if(flag==0){
                    flag=1;
                    ans++;
                }
            }
            else{
                int l,r;
                l=nums[i][0];
                r=nums[i][1];
                int lMax,rMax;
                lMax=l;
                rMax=r;
                if(zeros.floorKey(l)!=null){
                    int zeroBegining = zeros.floorKey(l);
                    int zeroCount = zeros.get(zeroBegining);
                    if(zeroBegining+zeroCount>=l) lMax=zeroBegining;
                }
                if(ones.floorKey(r)!=null){
                    int oneBegining = ones.floorKey(r+1);
                    // if(oneBegining>=l){
                    //     oneBegining = ones.floorKey(r+1);
                    // }
                    int oneCount = ones.get(oneBegining);
                    if(oneBegining+oneCount>r) rMax=(oneBegining+oneCount-1);
                }
                // System.out.println(i+" "+lMax+" "+rMax);
                set.add(new Pair(lMax,rMax));
            }
        }
        System.out.println(set.size()+ans);
        // set.forEach((Pair p) -> System.out.println(p.value+" "+p.index));
    }
}
//1 0 0 1 1 1
//0 1 2 3 4 5
//0,3
//zeros - 1,2 
//ones - 0,1 3,3
