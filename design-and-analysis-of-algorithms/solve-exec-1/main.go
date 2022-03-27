package main

var g ItemGraph

func fillGraph() {
	nA := Node{"A"}
	nB := Node{"B"}
	nC := Node{"C"}
	nD := Node{"D"}
	nE := Node{"E"}
	nF := Node{"F"}

	g.addNode(&nA)
	g.addNode(&nB)
	g.addNode(&nC)
	g.addNode(&nD)
	g.addNode(&nE)
	g.addNode(&nF)

	g.addEdge(&nA, &nB, 5)
	g.addEdge(&nA, &nF, 1)
	g.addEdge(&nA, &nD, 2)
	g.addEdge(&nD, &nE, 4)
	g.addEdge(&nD, &nB, 1)
	g.addEdge(&nB, &nC, 3)
	g.addEdge(&nC, &nE, 3)
	g.addEdge(&nE, &nF, 6)

}

func main() {
	fillGraph()
	g.string()
}
