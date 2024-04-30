package main

import (
	"fmt"
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
	table(result, "Multiply Endofunção 1 e Endofunção 2:")
}
