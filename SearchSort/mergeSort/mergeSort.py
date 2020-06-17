# Implement Merge Sort
# Merge Sort uses divide-and-conquer technique to recursively split array in halves and sort as they are merged.
# Good to use when there's no space constraint as it is NOT an in-place sorting

# Merge Sort
def mergeSort(arr):

	print("Split: ", arr)

	if (len(arr) > 1):
		mid = len(arr)//2

		L = arr[:mid]
		R = arr[mid:]
		
		# recursive on left side
		mergeSort(L)
		# recursive on right side
		mergeSort(R)

		merge(arr, L, R)

def merge(arr, arr1, arr2):
	index1 = 0
	index2 = 0
	sortedIndex = 0
	print("MERGE: ", arr1, arr2, end=" => ")
	while (len(arr1) > index1 and len(arr2) > index2):
		if (arr1[index1] <= arr2[index2]):
			arr[sortedIndex] = arr1[index1]
			index1 += 1
		else:
			arr[sortedIndex] = arr2[index2]
			index2 += 1
		sortedIndex += 1
	while (len(arr1) > index1):
		arr[sortedIndex] = arr1[index1]
		index1 += 1
		sortedIndex += 1
	while (len(arr2) > index2):
		arr[sortedIndex] = arr2[index2]
		index2 += 1
		sortedIndex += 1
	print(arr)
		
 			

# Driver
testArr = [2, 5, 8, 4, 9, 3, 1, 6, 7]
# testArr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
# testArr = [9, 8, 7, 6, 5, 4, 3, 2, 1]

print("Original Array:")
print(testArr)
print()

mergeSort(testArr)

print()
print("Sorted Array:")
print(testArr)