package main

var head *Node

type Node struct {
	x    int
	next *Node
}

type List struct {
	head *Node
}

// remove a node from the list which contains a certain item
// return true if item found false otherwise
func removeNode(l *List, node *Node) bool {
	var curr *Node = l.head
	for curr != node {
		curr = curr.next
	}
	if curr == nil {
		return false
	}

}
