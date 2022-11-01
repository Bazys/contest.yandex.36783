package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func maxScore(cardPoints []int, k int) int {
	sum := 0
	n := len(cardPoints)
	for i := 0; i < k; i++ {
		sum += cardPoints[i]
	}
	max := sum
	for i := k - 1; i >= 0; i-- {
		sum -= cardPoints[i]
		sum += cardPoints[n-k+i]
		if sum > max {
			max = sum
		}
	}
	return max
}

func makeScanner() *bufio.Scanner {
	const maxCapacity = 3 * 1024 * 1024
	buf := make([]byte, maxCapacity)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(buf, maxCapacity)
	return scanner
}

func readArray(scanner *bufio.Scanner) []int {
	scanner.Scan()
	listString := strings.Split(scanner.Text(), " ")
	arr := make([]int, len(listString))
	for i := 0; i < len(listString); i++ {
		arr[i], _ = strconv.Atoi(listString[i])
	}
	return arr
}

func main() {
	var n, k int
	fmt.Scanf("%d", &n)
	fmt.Scanf("%d", &k)

	scanner := makeScanner()
	cards := readArray(scanner)

	fmt.Printf("%d\n", maxScore(cards, k))
}
