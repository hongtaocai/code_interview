public class Solution {
    
    public double findkth(int A[], int B[], int k){

        if(A.length>B.length){
            int K[] = A;
            A = B;
            B = K;
        }

        if(k==0) return 0;
        if(A.length==0 && B.length==0 ){
            return 0;
        }
        if(A.length==0){
            return B[k-1];
        }
        if(B.length==0){
            return A[k-1];
        }


        int ma =k/2-1;
        if(A.length<k/2) {
            ma = (A.length-1);
        }
        int mb = k-ma-2;
        if(k==1){
            if(A[0]<B[0]){
                return A[0];
            }else{
                return B[0];
            }
        }

        if(A[ma]==B[mb]){
            return A[ma];
        }
        else if(A[ma]>B[mb]){
            int nA[] = Arrays.copyOfRange(A,0,ma+1);
            int nB[] = Arrays.copyOfRange(B,mb+1,B.length);
            return findkth(nA,nB,k-mb-1);
        }
        else{
            int nA[] = Arrays.copyOfRange(A,ma+1,A.length);
            int nB[] = Arrays.copyOfRange(B, 0, mb + 1);
            return findkth(nA,nB,k-ma-1);
        }

    }

    public double findMedianSortedArrays(int A[], int B[]) {
        // Start typing your Java solution below
        // DO NOT write main() function

        int k = (A.length+B.length);
        if(k%2==0){
            k = k/2;
            return (findkth(A,B,k)+findkth(A,B,k+1))/2;
        }else{
            k = k/2+1;
            return findkth(A,B,k);
        }

    }
}