package SearchSort.binarySearch;

import java.util.Arrays;

import SearchSort.quickSort.*;

/**
 * Binary search uses divide-and-conquer technique to search for target value in
 * a SORTED list. It searches target by recursively doing follow: 1. go to the
 * middle, and check whether target is equal to, or to the left or right of the
 * middle value 2. search from the left or right based on the value comparsion
 * (Think of Up-and-Down game)
 */

public class binarySearch {

    // Driver
    public static void main(String[] args) {
        int[] arr = { 23, 13, 83, 21, 69, 32, 8, 11, 63, 29, 75, 82, 19 };
        System.out.println("Original Array: " + Arrays.toString(arr));

        quickSort.sort(arr, 0, arr.length-1);
        System.out.println("Sorted Array: " + Arrays.toString(arr));

        int target = 29;
        int index = search(arr, target, 0, arr.length-1);
        if (index > 0)
            System.out.printf("Target %d at index %d\n", target, index);
        else
            System.out.printf("Target %d not found\n", target);

        target = 75;
        index = search(arr, target, 0, arr.length-1);
        if (index > 0)
            System.out.printf("Target %d at index %d\n", target, index);
        else
            System.out.printf("Target %d not found\n", target);

        target = 54;
        index = search(arr, target, 0, arr.length-1);
        if (index > 0)
            System.out.printf("Target %d at index %d\n", target, index);
        else
            System.out.printf("Target %d not found\n", target);

    }

    public static int search(int[] arr, int target, int left, int right) {
        // is sub-array still valid?
        if (right >= left) {
            int middleIndex = (left+right)/2;
            // target found at middle index
            if (target == arr[middleIndex]) {
                return middleIndex;
            }
            // target greater than middle value
            else if (target > arr[middleIndex]) {
                return search(arr, target, middleIndex+1, right);
            }
            // target less than middle value
            else {
                return search(arr, target, left, middleIndex-1);
            }
        }
        // not found in any sub-arrays
        return -1;
    }
    
}