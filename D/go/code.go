package main

import (
	"fmt"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func canMove(i, j, n, m int) bool {
	return i >= 0 && j >= 0 && i < n && j < m
}

func dfs(matrix [][]int, i, j, n, m int, distances [][]int) int {
	if !canMove(i, j, n, m) {
		return 0
	}
	if distances[i][j] != -1 {
		return distances[i][j]
	}
	res := 1
	dx := [4]int{-1, 1, 0, 0}
	dy := [4]int{0, 0, -1, 1}

	for k := 0; k < 4; k++ {
		newi := i + dx[k]
		newj := j + dy[k]
		if canMove(newi, newj, n, m) {
			if matrix[newi][newj] > matrix[i][j] &&
				distances[i][j] < distances[newi][newj]+1 {
				res = max(res, dfs(matrix, newi, newj, n, m, distances)+1)
			}
		}
	}
	distances[i][j] = res
	return res
}

func getLongestIncreasingPath(matrix [][]int) int {
	n := len(matrix)
	m := len(matrix[0])
	distances := make([][]int, n)
	for i := range distances {
		distances[i] = make([]int, m)
		for j := range distances[i] {
			distances[i][j] = -1
		}
	}
	for i := range distances {
		for j := range distances[i] {
			dfs(matrix, i, j, n, m, distances)
		}
	}
	ans := 1
	for i := range distances {
		for j := range distances[i] {
			ans = max(ans, distances[i][j])
		}
	}

	return ans
}

func main() {
	var n, m int

	fmt.Scanf("%d %d", &n, &m)
	matrix := make([][]int, n)
	for i := range matrix {
		matrix[i] = make([]int, m)
		for j := range matrix[i] {
			fmt.Scanf("%d", &matrix[i][j])
		}
	}
	fmt.Println(getLongestIncreasingPath(matrix))
}
