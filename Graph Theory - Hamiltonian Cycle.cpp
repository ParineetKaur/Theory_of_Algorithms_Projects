//Question: Given a graph G(V, E) and a certificate C[], where C[] is a sequence of vertices forming a potential Hamiltonian Cycle in the graph, design a algorithm that (1)verifies whether the cycle visits each node in the graph exactly once and (2)checks that there is an edge between consecutive nodes in the cycle.
//The algorithm below takes the graph G and certificate C as input and returns "isCorrect" if certificate forms a valid Hamiltonian Cycle. 
//Hamiltonian Cycle: a cycle that visits every vertex exactly once and returns to the starting vertex

VerifyHamiltonianCycle(G(V, E), C[]) {
    isCorrect = true
    for each pair (u, v) in consecutive pairs of C[] {
        if graph does not have an edge between u and v {
            isCorrect = false
            break
        }
    }
    return isCorrect
}
