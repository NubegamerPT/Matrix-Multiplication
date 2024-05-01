package main

import (
	"fmt"
)

func fillzeros(n int) [][]int {
	endofunctions := [][]int{}
	for i := 0; i < power(n, n); i++ {
		endofunction := make([]int, n)
		temp := i
		for j := 0; j < n; j++ {
			endofunction[j] = temp + 1%n
			temp /= n
		}
		endofunctions = append(endofunctions, endofunction)
	}
	return endofunctions
}

func power(base, power int) int {
	var result int = 1
	for i := 0; i < power; i++ {
		result *= base
	}
	return result
}

func find(array [][]int, element int) [][]int {
	output := make([][]int, len(array))
	for i := range output {
		output[i] = make([]int, INDEX)
	}

	for i := 0; i < len(array); i++ {
		for j := 0; j < len(array[i]); j++ {
			if array[i][j] == element {
				output[i][j] = 1
			} else if output[i][j] == 1 {
				output[i][j] = 1
			} else {
				output[i][j] = 0
			}
		}
	}

	return output
}

func table(array [][]int, message ...string) {
	if message == nil {
		message = append(message, "")
	}
	fmt.Println("\n", message[0], "\t")
	for i := 0; i < len(array); i++ {
		fmt.Printf("[%3d] = ", i)
		for j := 0; j < len(array[i]); j++ {
			fmt.Print(array[i][j])
		}
		fmt.Println()
	}
}

func compost(array1 [][]int, array2 [][]int) [][]int {
	output := make([][]int, len(array1)*len(array2))

	for i := 0; i < len(output); i++ {
		output[i] = make([]int, INDEX)
	}

	for rowsA := 0; rowsA < len(array2); rowsA++ {
		for i := 0; i < INDEX; i++ {
			newX := (array1[rowsA][i]) - 1
			fmt.Println("array: ", array1[rowsA][i], "sender: ", array2[rowsA][newX])
			/* output[rowsA*len(array2)][i] = array2[rowsB][newX] */
		}
	}

	return output
}
