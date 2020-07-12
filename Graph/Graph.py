'''
Simple Graph Implementation in Python
using both common implementations:
1. Adjacency Matrix
    - Space: O(V^2)
    - is there edge from u to v?: O(1)
    - find adjacent vertices of u: O(V)
2. Adjacency List
    - Space: O(V + E)
    - is there edge from u to v?: O(degree(u))
    - find adjacent vertices of u: O(degree(u))

basic operations:
- add vertex
- remove vertex
- add edge
- remove edge
'''


# Graph using Adjacency Matrix
# By default, Weighted and Directed, but can be configured using constructor
class MatrixGraph:

    def __init__(self, weighted=True, directed=True):
        self.__vertices = []
        self.__adjMatrix = []
        self.__weighted = weighted
        self.__directed = directed
        self.__numVertex = 0

    def addVertex(self, vertex):
        if vertex in self.__vertices:
            raise Exception("Given vertex already exists")
        self.__vertices.append(vertex)
        self.__numVertex += 1
        # add new vertex as new row and column of adj matrix
        newRow = [0 for x in range(0, self.__numVertex)]
        self.__adjMatrix.append(newRow)
        for i in range(0, self.__numVertex-1):
            self.__adjMatrix[i].append(0)

    def removeVertex(self, vertex):
        if vertex not in self.__vertices:
            raise Exception("Given vertex does not exist")
        vertexIndex = self.__vertices.index(vertex)
        self.__vertices.remove(vertex)
        del self.__adjMatrix[vertexIndex]
        for i in range(0, self.__numVertex-1):
            del self.__adjMatrix[i][vertexIndex]
        self.__numVertex -= 1

    def addEdge(self, source, destination, weight=1):
        if source not in self.__vertices:
            raise Exception("Given source vertex does not exist")
        if destination not in self.__vertices:
            raise Exception("Given destination vertex does not exist")
        sourceIndex = self.__vertices.index(source)
        destIndex = self.__vertices.index(destination)
        if not self.__weighted:
            weight = 1
        self.__adjMatrix[sourceIndex][destIndex] = weight
        if not self.__directed:
            self.__adjMatrix[destIndex][sourceIndex] = weight

    def removeEdge(self, source, destination):
        if source not in self.__vertices:
            raise Exception("Given source vertex does not exist")
        if destination not in self.__vertices:
            raise Exception("Given destination vertex does not exist")
        sourceIndex = self.__vertices.index(source)
        destIndex = self.__vertices.index(destination)
        self.__adjMatrix[sourceIndex][destIndex] = 0
        if not self.__directed:
            self.__adjMatrix[destIndex][sourceIndex] = 0

    def clearEdge(self):
        for i in range(0, self.__numVertex):
            for j in range(0, self.__numVertex):
                self.__adjMatrix[i][j] = 0

    # utilities
    # print out adjacency matrix
    def __str__(self):
        output = '{:^5}'.format("")
        for v in self.__vertices:
            output += '{:^5}'.format(v)
        output += '\n'
        for i in range(0, self.__numVertex):
            output += '{:^5}'.format(self.__vertices[i])
            for j in range(0, self.__numVertex):
                if self.__adjMatrix[i][j] == 0:
                    color = "31"
                else:
                    color = "32"
                output += '\033[0;{0};1m{1:^5}\033[0m'.format(
                    color, self.__adjMatrix[i][j])
            output += '\n'
        return output


# Graph using Adjacency List
# By default, Weighted and Directed, but can be configured using constructor
class ListGraph:

    def __init__(self, weighted=True, directed=True):
        self.__vertices = []
        self.__numVertex = 0
        self.__adjList = []
        self.__weighted = weighted
        self.__directed = directed

    def addVertex(self, vertex):
        if vertex in self.__vertices:
            raise Exception("Given vertex already exists")
        self.__vertices.append(vertex)
        self.__numVertex += 1
        self.__adjList.append([])

    def removeVertex(self, vertex):
        if vertex not in self.__vertices:
            raise Exception("Given vertex does not exist")
        vertexIndex = self.__vertices.index(vertex)
        self.__vertices.remove(vertex)
        self.__numVertex -= 1
        del self.__adjList[vertexIndex]
        # find removed vertex from other edges
        if self.__weighted:
            for i in range(0, len(self.__adjList)):
                self.__adjList[i] = [
                    adj for adj in self.__adjList[i] if adj[0] != vertex]
        else:
            for i in range(0, len(self.__adjList)):
                self.__adjList[i].remove(vertex)

    def addEdge(self, source, destination, weight=1):
        if source not in self.__vertices:
            raise Exception("Given source vertex does not exist")
        if destination not in self.__vertices:
            raise Exception("Given destination vertex does not exist")
        sourceIndex = self.__vertices.index(source)
        if not self.__weighted:
            newAdj = destination
        else:
            newAdj = (destination, weight)
        self.__adjList[sourceIndex].append(newAdj)
        # if undirected add edge the other way too
        if not self.__directed:
            destIndex = self.__vertices.index(destination)
            if not self.__weighted:
                newAdj = source
            else:
                newAdj = (source, weight)
            self.__adjList[destIndex].append(newAdj)

    def removeEdge(self, source, destination):
        if source not in self.__vertices:
            raise Exception("Given source vertex does not exist")
        if destination not in self.__vertices:
            raise Exception("Given destination vertex does not exist")
        sourceIndex = self.__vertices.index(source)
        if self.__weighted:
            self.__adjList[sourceIndex] = [
                adj for adj in self.__adjList[sourceIndex] if adj[0] != destination]
        else:
            self.__adjList[sourceIndex].remove(destination)
        # if undirected, remove edge from dest to src
        if not self.__directed:
            destIndex = self.__vertices.index(destination)
            if self.__weighted:
                self.__adjList[destIndex] = [
                    adj for adj in self.__adjList[destIndex] if adj[0] != source]
            else:
                self.__adjList[destIndex].remove(source)

    def clearEdge(self):
        self.__adjList = [[]]*self.__numVertex

    def BFS(self, vertex=None):
        visited = []
        queue = []      # use enqueue, dequeue
        if vertex is None:
            vertex = self.__vertices[0]
        # add first vertex to visited and enqueue
        if vertex not in visited:
            visited.append(vertex)
            queue.append(vertex)
            # while there's vertex to traverse
            while queue:
                for neighbor in self.neighbors(queue.pop(0)):
                    if neighbor not in visited:
                        visited.append(neighbor)
                        queue.append(neighbor)
        return visited

    def neighbors(self, vertex):
        neighbors = []
        vIndex = self.__vertices.index(vertex)
        if self.__weighted:
            for adj in self.__adjList[vIndex]:
                neighbors.append(adj[0])
        else:
            for adj in self.__adjList[vIndex]:
                neighbors.append(adj)
        return neighbors

    # utilities
    # print out adjacency list

    def __str__(self):
        output = ""
        for i in range(0, self.__numVertex):
            output += self.__vertices[i] + ": "
            for j in range(0, len(self.__adjList[i])):
                output += str(self.__adjList[i][j])
                if j != len(self.__adjList[i])-1:
                    output += ", "
            output += '\n'
        return output
