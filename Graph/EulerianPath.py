from Graph import ListGraph


def isEulerianPath(graph):
    numOddDegree = 0
    # for each connected vertex, check if degree is odd
    for vertex in graph.BFS():
        if len(graph.neighbors(vertex)) % 2 == 1:
            numOddDegree += 1
        if numOddDegree > 2:
            return False
    if numOddDegree == 1:
        return False
    return True


# graph: (Eulerian)
#    'a'
#   /   \
# 'b'---'c'
#  |\   /|
#  | 'd' |
#  |/   \|
# 'e'---'f'
graphA = ListGraph(weighted=False, directed=False)
graphA.addVertex('a')
graphA.addVertex('b')
graphA.addVertex('c')
graphA.addVertex('d')
graphA.addVertex('e')
graphA.addVertex('f')
graphA.addEdge('a', 'b')
graphA.addEdge('a', 'c')
graphA.addEdge('b', 'c')
graphA.addEdge('b', 'd')
graphA.addEdge('b', 'e')
graphA.addEdge('c', 'd')
graphA.addEdge('c', 'f')
graphA.addEdge('d', 'e')
graphA.addEdge('d', 'f')
graphA.addEdge('e', 'f')
print(graphA)

print("Is Graph A Eulerian Path?", isEulerianPath(graphA), end="\n\n")

# graphB (not Eulerian)
# 'a'---'b'
#  |\   /|
#  | 'e' |
#  |/   \|
# 'c'---'d'

graphB = ListGraph(weighted=False, directed=False)
graphB.addVertex('a')
graphB.addVertex('b')
graphB.addVertex('c')
graphB.addVertex('d')
graphB.addVertex('e')
graphB.addEdge('a', 'b')
graphB.addEdge('a', 'c')
graphB.addEdge('a', 'e')
graphB.addEdge('b', 'd')
graphB.addEdge('b', 'e')
graphB.addEdge('c', 'd')
graphB.addEdge('c', 'e')
graphB.addEdge('d', 'e')
print(graphB)

print("Is Graph B Eulerian Graph?", isEulerianPath(graphB))
