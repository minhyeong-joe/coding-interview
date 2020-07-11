'''
Given a linked list with duplicate items,
remove all duplicate items.
'''

from LinkedList import LinkedList


def removeDuplicate(list):
    dupChecker = set()
    it = list.iterator()
    prevPtr = None
    while it is not None:
        if it.getValue() not in dupChecker:
            dupChecker.add(it.getValue())
            prevPtr = it
            it = it.getNext()
        else:
            # "skip" the duplicate node
            prevPtr.setNext(it.getNext())
            it = it.getNext()


def main():
    arr = ['a', 'c', 'b', 'c', 'd', 'c', 'b']
    list = LinkedList(arr)
    print(list)

    removeDuplicate(list)

    print(list)


if __name__ == "__main__":
    main()
