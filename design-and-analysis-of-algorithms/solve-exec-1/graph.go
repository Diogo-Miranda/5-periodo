package main

import (
	"fmt"
	"sync"
)

type ItemGraph struct {
	nodes []*Node                      // list of node's pointer
	edges map[Node][](map[*Node]int32) // Node: [] (*Node, int)
	lock  sync.RWMutex
}

type Node struct {
	value string
}

func (n *Node) string() string {
	return fmt.Sprintf("%v", n.value)
}

func (g *ItemGraph) addNode(n *Node) {
	g.lock.Lock()
	g.nodes = append(g.nodes, n)
	g.lock.Unlock()
}

func (g *ItemGraph) addEdge(v1, v2 *Node, weight int32) {
	g.lock.Lock()
	if g.edges == nil {
		g.edges = make(map[Node][](map[*Node]int32))
	}

	mWeightV1 := make(map[*Node]int32)
	mWeightV1[v1] = weight
	mWeightV2 := make(map[*Node]int32)
	mWeightV2[v2] = weight

	g.edges[*v1] = append(g.edges[*v1], mWeightV2)
	g.edges[*v2] = append(g.edges[*v2], mWeightV1)
	g.lock.Unlock()
}

// func (g *ItemGraph) string() {
// 	g.lock.RLock()
// 	s := ""
// 	for i := 0; i < len(g.nodes); i++ {
// 		s += g.nodes[i].string() + " -> "
// 		near := g.edges[*g.nodes[i]]
// 		for j := 0; j < len(near); j++ {
// 			s += near[j].string + " "
// 		}
// 		s += "\n"
// 	}
// 	fmt.Print(s)
// 	g.lock.RUnlock()
// }

func (g *ItemGraph) string() {
	g.lock.RLock()
	s := ""
	// iterate around graph
	for i := 0; i < len(g.nodes); i++ {
		// get current node
		s += g.nodes[i].string() + " -> "
		near := g.edges[*g.nodes[i]]
		// iterate into nears
		for j := 0; j < len(near); j++ {
			valueM := near[j]

			for l, w := range valueM {
				s += l.string() + ":" + fmt.Sprintf("%v", w) + " "
			}
		}
		s += "\n"
	}
	fmt.Print(s)
	g.lock.RUnlock()
}
