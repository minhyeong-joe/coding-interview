/*
Implement Insertion Sort
*/

public class insertionSort {

	public static void main(String[] args) {
		int[] testArr = {5, 3, 9, 2, 1, 7, 4, 6, 8};
		// int[] testArr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		// int[] testArr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
		System.out.println("Original Array:");
		printArray(testArr);
		System.out.println();

		insertionSort(testArr);

		System.out.println("\nSorted Array:");
		printArray(testArr);
	}

	public static void printArray(int[] arr) {
		System.out.print("[ ");
		for (int x: arr) {
			System.out.printf("%d ", x);
		}
		System.out.println("]");
	}

	public static void insertionSort(int[] arr) {
		for (int i = 1; i < arr.length; i++) {
			System.out.printf("Iteration %d\n", i);
			int temp = arr[i];
			int newIndex = i;
			for (int j = i-1; j >= 0; j--) {
				if (arr[j] > temp) {
					System.out.printf("%d < %d\n", temp, arr[j]);
					arr[j+1] = arr[j];
					newIndex = j;
				}
			}
			arr[newIndex] = temp;
			printArray(arr);
		}
	}
}
