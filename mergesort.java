package com.leetcode;

import java.util.Random;

/**
 * Created with IntelliJ IDEA.
 * User: hongtaocai
 * Date: 1/22/13
 * Time: 4:52 PM
 * To change this template use File | Settings | File Templates.
 */
public class MergeSort {

    void mergeSort(int arr[]){
        int tmp[] = new int[arr.length];
        mergeSort(arr,0,arr.length-1,tmp);
    }

    void merge(int arr[], int start, int mid, int last, int[] tmp){
        int i=start;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=last){
            if(arr[i]<arr[j]){
                tmp[k++]=arr[i++];
            }
            else{
                tmp[k++]=arr[j++];
            }
        }
        while(i<=mid){
            tmp[k++]=arr[i++];
        }
        while(j<=last){
            tmp[k++]=arr[j++];
        }
        for(i=0;i<k;i++){
            arr[start+i]=tmp[i];
        }
    }

    private void mergeSort(int arr[], int start, int last, int[] tmp){
        if(start==last) return;
        int mid = start+(last-start)/2;
        mergeSort(arr,start,mid,tmp);
        mergeSort(arr,mid+1,last,tmp);
        merge(arr, start, mid, last, tmp);
    }

    public static void main(String args[]){
        int a[] = new int[1000];
        Random r = new Random();
        boolean flag = true;
        MergeSort m = new MergeSort();
        loop1 :
        for(int i=0;i<100;i++){
            for(int j=0;j<1000;j++){
                a[j] = r.nextInt();
            }
            m.mergeSort(a);
            for(int j=1;j<1000;j++){
                if(a[j]<a[j-1]){
                    flag = false;
                    break loop1;
                }
            }
        }
        System.out.println(flag);
    }
}
