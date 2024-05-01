package main

import (
	"fmt"
)

const (
	INDEX int = 2
)

func main() {

	if INDEX > 7 {
		fmt.Println("The program is not optimized for values greater than 6")
		return
	}

	array1 := fillzeros(INDEX)
	array2 := fillzeros(INDEX)

	table(array1, "Endofunção 1:")
	table(array2, "Endofunção 2:")

	result := find(array2, 1)
	table(result, "Find 1:")

	result = compost(array1, array2)
	table(result, "End1 o End2:")
}
