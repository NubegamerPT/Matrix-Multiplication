package main

import "fmt"

const (
	INDEX int = 3
)

func fillzeros(n int) [][]int {
	endofunctions := [][]int{}
	for i := 0; i < power(n, n); i++ {
		endofunction := make([]int, n)
		temp := i
		for j := 0; j < n; j++ {
			endofunction[j] = temp % n
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
		for j := 0; j < len(array[i]); j++ {
			fmt.Print("\t", array[i][j])
		}
		fmt.Println()
	}
}

func compost(array1 [][]int, array2 [][]int) [][]int {
	output := make([][]int, len(array1)*len(array2))
	for i := range output {
		output[i] = make([]int, INDEX)
	}

	for i := 0; i < len(array1); i++ {
		for j := 0; j < len(array2); j++ {
			for k := 0; k < len(array1[i]); k++ {
				output[i*len(array2)+j][k] = array1[i][k] * array2[j][k]
			}
		}
	}
	return output
}
