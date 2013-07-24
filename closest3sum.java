import java.util.ArrayList;
import java.util.Collections;

public class Solution {
    public int threeSumClosest(int[] num, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<Integer> numArr = new ArrayList<Integer>();
        for(int i=0;i<num.length;i++){
            numArr.add(num[i]);
        }
        int difference = Integer.MAX_VALUE;
        Collections.sort(numArr);
        for(int i=0;i<numArr.size()-2;i++){
            int j=i+1;
            int k=numArr.size()-1;
            while(j<k){
                int tmp = numArr.get(i)+numArr.get(j)+numArr.get(k) - target;
                if(tmp<0){
                    j++;
                }else if(tmp>0){
                    k--;
                }else{
                    return target;
                }
                if(Math.abs(tmp)<Math.abs(difference)){
                    difference = tmp;
                }
            }

        }
        return difference+target;

    }
}