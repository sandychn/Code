package main

import (
	"fmt"
	"sort"
)

func findUnsortedSubarray(nums []int) int {
	n := len(nums)
	sorted := make([]int, n)
	copy(sorted, nums)
	sort.Ints(sorted)
	// fmt.Println(sorted)
	left, right := -1, -1
	for i := 0; i < n; i++ {
		if sorted[i] != nums[i] {
			left = i
			break
		}
	}
	for i := n - 1; i >= 0; i-- {
		if sorted[i] != nums[i] {
			right = i
			break
		}
	}
	if left == -1 && right == -1 {
		return 0
	}
	return right - left + 1
}

func main() {
	a := []int{2, 6, 4, 8, 10, 9, 15}
	fmt.Println(findUnsortedSubarray(a))
}
