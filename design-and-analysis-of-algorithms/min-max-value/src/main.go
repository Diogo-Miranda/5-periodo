package main

import "fmt"

func main() {
	l := newList()

	min, max := l.findMaxAndMinUsingList()
	fmt.Println("min, max: ", min, max)

	min, max = l.findMaxAndMinUsingSwap()
	fmt.Println("min, max: ", min, max)

	min, max = l.findMaxAndMinUsingSequencialFinding()
	fmt.Println("min, max: ", min, max)
}
