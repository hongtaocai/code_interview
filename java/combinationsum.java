public class Solution {
    public ArrayList<ArrayList<Integer>> combinationSum(int[] candidates, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        HashMap<Integer, ArrayList<ArrayList<Integer>>> numberToComb = 
            new HashMap<Integer, ArrayList<ArrayList<Integer>>>();
        ArrayList<Integer> cda = new ArrayList<Integer>();
        for(int i=0;i<candidates.length;i++){
            cda.add(candidates[i]);
        }
        Collections.sort(cda);
        HashSet<Integer> hs = new HashSet<Integer>(cda);
        
        
        for(int i=1;i<=target;i++){
            numberToComb.put(i, new ArrayList<ArrayList<Integer>>());
        }
        for(int i=1;i<=target;i++){
            if(hs.contains(i)){
                ArrayList<Integer> tmp = new ArrayList<Integer>();
                tmp.add(i);
                numberToComb.get(i).add(tmp);      
            }
            if(i==target){
                break;
            }
            for(Integer k : cda){
                if( k+i<=target ){
                    for(ArrayList<Integer> ar : numberToComb.get(i)){
                        if(k<ar.get(ar.size()-1)){
                            continue;
                        }
                        ArrayList<Integer> arnew = new ArrayList<Integer>(ar);
                        arnew.add(k);
                        
                        numberToComb.get(k+i).add(arnew);
                    }
                    
                }  
            }
            
        }
        return numberToComb.get(target);
    }
}