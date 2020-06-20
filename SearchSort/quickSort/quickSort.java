/**
Implement Quick Sort
Quick sort uses a pivot to move smaller elements to its left and larger elements to its right.
Recursively doing so on left side of pivot and right side of pivot.
This divide-and-conquer technique takes O(n log n) time.
Unlike the MergeSort, QuickSort is an in-place sorting algorithm.
*/
import java.lang.*;
import java.util.*;

public class quickSort {

  // Driver
  public static void main(String[] args) {
      int[] testArr = {3, 6, 4, 8, 7, 1, 9, 2, 5};
      // int[] testArr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
      // int[] testArr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
      // int[] testArr = {8, 3, 7, 6, 5, 1, 2, 9, 4};  // unsored, but 5 as middle
      System.out.println("Original Array:");
      System.out.println(Arrays.toString(testArr));
      System.out.println();

      quickSort(testArr, 0, testArr.length-1);

      System.out.println("\nSorted Array:");
      System.out.println(Arrays.toString(testArr));
  }

  public static void quickSort(int[] arr, int left, int right) {
    if (right > left) {
      // System.out.println(Arrays.toString(Arrays.copyOfRange(arr, left, right)));

      int pivotIndex = partition(arr, left, right);

      quickSort(arr, left, pivotIndex);
      quickSort(arr, pivotIndex+1, right);

    }
  }

  public static int partition(int[] arr, int left, int right) {
    int pivot = arr[(left+right)/2];
    int i = left;
    int j = right;
    System.out.println("Pivot: " + pivot);
    while(true) {
      while (arr[i] < pivot) {
        i++;
      }
      System.out.println("Left pointer at " + arr[i]);
      while (arr[j] > pivot) {
        j--;
      }
      System.out.println("Right pointer at " + arr[j]);
      if (i >= j) {
        return j;
      }
      System.out.println("Swapping " + arr[i] + " and " + arr[j]);
      swap(arr, i, j);
      System.out.println(Arrays.toString(arr));
      i++;
      j--;
    }


  }

  public static void swap(int[] arr, int a, int b) {
    arr[a] = arr[a] + arr[b];
    arr[b] = arr[a] - arr[b];
    arr[a] = arr[a] - arr[b];
  }

}
