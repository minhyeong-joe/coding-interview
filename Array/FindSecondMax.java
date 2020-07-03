package Array;

import java.util.Arrays;

/**
 * FindSecondMax
 * Extenstion)
 * Find Nth Max as well
 */
public class FindSecondMax {

    public static void main(String[] args) {
        int arr[] = {2, 4, 5, 3, 8, 6, 1};

        System.out.println(Arrays.toString(arr));

        int secMax = findSecondMax(arr);

        System.out.println("Second Max: " + secMax);

        int thirdMax = findNthMax(arr, 3);

        int fourthMax = findNthMax(arr, 4);

        int fifthMax = findNthMax(arr, 5);

        System.out.println("Third Max: " + thirdMax);

        System.out.println("Fourth Max: " + fourthMax);
        
        System.out.println("Fifth Max: " + fifthMax);
    }

    public static int findSecondMax(int[] arr) {
        int rank[] = new int[2];
        for (int i: arr) {
            insertSorted(rank, i);
        }
        return rank[1];
    }

    // extension find Nth Max
    public static int findNthMax(int[] arr, int N) {
        // create ranking array of size N
        int rank[] = new int[N];
        for (int i: arr) {
            insertSorted(rank, i);
        }
        return rank[N-1];
    }

    // helper function to insert value as sorted order high->low
    public static void insertSorted(int[] arr, int newVal) {
        int temp;
        for (int i = 0; i < arr.length; i++) {
            if (newVal > arr[i]) {
                temp = arr[i];
                arr[i] = newVal;
                newVal = temp;
            }
        }
    }
    
}