public class Solution {
    public ArrayList<ArrayList<Integer>> combinationSum2(int[] num, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
              HashMap<Integer, ArrayList<ArrayList<Integer>>> numberToComb = 
            new HashMap<Integer, ArrayList<ArrayList<Integer>>>();
        ArrayList<Integer> cda = new ArrayList<Integer>();
        for(int i=0;i<num.length;i++){
            cda.add(num[i]);
        }
        Collections.sort(cda);
        
        
        for(int i=1;i<=target;i++){
            numberToComb.put(i, new ArrayList<ArrayList<Integer>>());
        }
        
        for(int i=0;i<cda.size();i++){
            if(cda.get(i)<=target){
                ArrayList<Integer> tmp = new ArrayList<Integer>();
                tmp.add(i);
                numberToComb.get(cda.get(i)).add(tmp);  
            }
        }
        
        for(int i=1;i<=target;i++){
            
            if(i==target){
                break;
            }
            
            for(int k=0;k<cda.size();k++){
                if( cda.get(k)+i<=target ){
                    for(ArrayList<Integer> ar : numberToComb.get(i)){
                        
                        if(k<ar.get(ar.size()-1)){
                            continue;
                        }
                        
                        if(Collections.binarySearch(ar,k)>=0){
                            continue;
                        }
                        
                        ArrayList<Integer> arnew = new ArrayList<Integer>(ar);
                        arnew.add(k);
                        
                        numberToComb.get(cda.get(k)+i).add(arnew);
                    }
                    
                }  
            }
            
        }
        
        ArrayList<ArrayList<Integer>> k  = numberToComb.get(target);
        HashSet<ArrayList<Integer>> res = new HashSet<ArrayList<Integer>>(); 
        for(ArrayList<Integer> k1 : k){
            ArrayList<Integer> k2 = new ArrayList<Integer>();
            for(Integer m: k1){
                k2.add(cda.get(m));
            }
            res.add(k2);
        }
        
        
        
        return new ArrayList<ArrayList<Integer>>(res);
    
    }
}