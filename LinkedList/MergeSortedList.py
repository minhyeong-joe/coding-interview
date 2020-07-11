from LinkedList import LinkedList

listA = LinkedList([2, 4, 5])
listB = LinkedList([0, 1, 2, 3, 6])
print(listA)
print(listB)

# __add__ operator has been overloaded in LinkedList.py
# to enable LinkedList + LinkedList to be sorted
# Assume two input lists are already sorted
list = listA + listB
print(list)