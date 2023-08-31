// Question: How do you print the shortest path between two vertices in a graph?

#include <iostream>
#include <vector>
using namespace std;

void printShortestPath(char source, char target, char p[]) {
    vector<char> path;

    // Traverse the previous node pointers until reaching the source vertex S
    char current = target;
    while (current != source) {
        path.push_back(current);
        current = p[current];
    }

    // Push the source vertex S onto the vector
    path.push_back(source);

    // Print the vertices in the vector to obtain the shortest path from S to A
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i != 0) {
            cout << " -> ";
        }
    }
}
