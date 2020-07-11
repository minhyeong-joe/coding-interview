'''
Linked List Implementation in Python
Singly Linked with basic functionalities only.
'''

class Node:
    __value = None
    __next = None

    def __init__(self, value, next=None):
        self.__value = value
        self.__next = next

    def setValue(self, value):
        self.__value = value

    def setNext(self, next):
        self.__next = next
    
    def getValue(self):
        return self.__value

    def getNext(self):
        return self.__next


class LinkedList:
    __head = None
    
    # constuctor optionally with list object
    def __init__(self, list=None):
        if list is None:
            self.__head = None
        else:
            newNode = Node(list[0])
            self.__head = newNode
            for i in range(1, len(list)):
                ptr = newNode
                newNode = Node(list[i])
                ptr.setNext(newNode)

    
    # get Nth value
    def getVal(self, pos):
        ptr = self.__head
        for i in range(0, pos):
            ptr = ptr.getNext()
            if ptr is None:
                raise IndexError("Index Out of Bound")
        return ptr.getValue()


    # insert at Nth position
    # default to insert to the start if position is not provided
    def insert(self, value, pos=0):
        if pos == 0:
            newNode = Node(value, self.__head)
            self.__head = newNode
        else:
            prevPtr = self.__head
            for i in range(0, pos-1):
                prevPtr = prevPtr.getNext()
                if prevPtr.getNext() is None:
                    break
            newNode = Node(value, prevPtr.getNext())
            prevPtr.setNext(newNode)

    
    # append to the end of list
    def append(self, value):
        newNode = Node(value)
        ptr = self.__head
        if ptr is None:
            self.__head = newNode
            return
        while ptr.getNext() is not None:
            ptr = ptr.getNext()
        ptr.setNext(newNode)


    # remove value at given position
    def remove(self, pos):
        # removing first item
        if pos == 0:
            self.__head = self.__head.getNext()
            return

        prevPtr = self.__head
        for i in range(0, pos-1):
                prevPtr = prevPtr.getNext()
                # if position is out of range
                if prevPtr.getNext() is None:
                    raise IndexError("Index Out of Bound")
        nodeToDelete = prevPtr.getNext()
        # removing last item
        if nodeToDelete.getNext() is None:
            prevPtr.setNext(None)
        else:
            prevPtr.setNext(nodeToDelete.getNext())


    # clear
    def clear(self):
        self.__head = None

    
    # iterator
    def iterator(self):
        return self.__head


    # print format
    def __str__(self):
        toString = "{"
        ptr = self.__head
        while ptr != None:
            toString += str(ptr.getValue())
            if ptr.getNext() != None:
                toString += " => "
            ptr = ptr.getNext()
        toString += "}"
        return toString

    
    # add two sorted lists in a new sorted list
    # this is used for Merge Two Sorted List specifically
    # so assume two linked lists are already sorted.
    def __add__(self, other):
        comb = LinkedList()
        selfPtr = self.__head
        otherPtr = other.__head
        while selfPtr is not None and otherPtr is not None:
            if selfPtr.getValue() < otherPtr.getValue():
                comb.append(selfPtr.getValue())
                selfPtr = selfPtr.getNext()
            else:
                comb.append(otherPtr.getValue())
                otherPtr = otherPtr.getNext()
        while selfPtr is not None:
            comb.append(selfPtr.getValue())
            selfPtr = selfPtr.getNext()
        while otherPtr is not None:
            comb.append(otherPtr.getValue())
            otherPtr = otherPtr.getNext()
        return comb
