from LinkedList import LinkedList

# list constructor test
arr = [0, 1, 2, 3, 4]
linkedList = LinkedList(arr)
print(linkedList)

# get value test
try:
    print(linkedList.getVal(3))
except IndexError as err:
    print(err)

# remove test
try:
    linkedList.remove(0)
    print(linkedList)
    linkedList.remove(4)
    print(linkedList)
except IndexError as err:
    print(err)

# insert to start test
linkedList.insert(0)
print(linkedList)

# insert to position test
linkedList.insert(2.5, 3)
print(linkedList)

# append test
linkedList.append(5)
print(linkedList)

# iterator test
it = linkedList.iterator()
for i in range(0, 2):
    it = it.getNext()
print(it.getValue())

# clear test
linkedList.clear()
print(linkedList)