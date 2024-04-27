package main

import (
	"fmt"
	"os"
	"strconv"
	// "math"
)

func main() {
	var n int64 = 10
	if len(os.Args) == 2 {
		var err error
		n, err = strconv.ParseInt(os.Args[1], 10, 64)
		if err != nil {
			os.Exit(1)
		}
	}
	expected := n * (n ) / 2
	// expected := int64(float64(n) * (math.Log(float64(n)) / math.Log(2)))
	ops := 0
	for i := int64(0); i < n; i++ {
		for ii := int64(0); ii < i; ii++ {
			ops++;
		}
	}
	fmt.Printf("Expected: %d, Actual: %d\n", expected, ops)
}
