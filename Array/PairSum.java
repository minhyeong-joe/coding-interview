package Array;

import java.util.Arrays;
import java.util.HashMap;

/**
 * PairSum Find a pair that sums to target value Using dictionary approach
 */
public class PairSum {

    public static void main(String[] args) {

        int[] arr = { 3, 7, 2, 5, 6, 3 };
        int target = 9;

        int[] pair = pairSum(arr, target);

        System.out.println(Arrays.toString(pair));

    }

    public static int[] pairSum(int[] arr, int target) {
        int pair[] = new int[2];
        HashMap<Integer, Boolean> isInArr = new HashMap<>();

        // keep elements in array into a dictionary (not counting)
        for (int i : arr) {
            isInArr.putIfAbsent(i, true);
        }

        for (int i : arr) {
            int diff = target - i;
            if (isInArr.get(diff) != null) {
                pair[0] = i;
                pair[1] = diff;
                return pair;
            }
        }

        return pair;
    }

}