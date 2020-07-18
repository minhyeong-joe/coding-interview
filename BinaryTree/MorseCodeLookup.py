class Node:
    """
    Represent each node in the binary tree
    """    
    def __init__(self, letter=None):
        self.__letter = letter
        self.__left = None
        self.__right = None
    
    def letter(self, letter=None):
        if letter is None:
            return self.__letter
        self.__letter = letter
    
    def left(self):
        return self.__left

    def right(self):
        return self.__right
    
    def setLeft(self, left):
        self.__left = left

    def setRight(self, right):
        self.__right = right

    def set(self, left, right):
        self.setLeft(left)
        self.setRight(right)

    def __str__(self):
        return self.__letter

# manually constructing Morse Code Binary Tree
# using level-order traversal
root = Node()
morseArray = ["E", "T", "I", "A", "N", "M", "S", "U", "R", "W", "D", "K", "G", "O", "H", "V", "F", None, "L", None, "P", "J", "B", "X", "C", "Y", "Z", "Q", None, None]
queue = []
queue.append(root)
i = 0
while queue and i < len(morseArray):
    parent = queue.pop(0)
    if morseArray[i] is not None:
        left = Node(morseArray[i])
    else:
        left = None
    i += 1
    if morseArray[i] is not None:
        right = Node(morseArray[i])
    else:
        right = None
    i += 1
    parent.set(left, right)
    queue.append(left)
    queue.append(right)


# Morse to Letter Conversion
# catch AttributeError to ignore invalid morse code sequence
def convert(morse):
    output = ""
    arr = morse.split(" ")
    for code in arr:
        ptr = root
        try:
            for c in code:
                if c == '.':
                    ptr = ptr.left()
                if c == '-':
                    ptr = ptr.right()
            if ptr.letter() is not None:
                output += ptr.letter()
        except AttributeError as err:
            pass
        
    return output



# test driver
morse = ".... . .-.. .-.. ---"

print(convert(morse))