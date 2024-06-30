package main

import (
	"fmt"
	"math"
	"runtime"
	"strings"
	"time"
	//"golang.org/x/tour/pic"
	//"golang.org/x/tour/wc"
)

func Sqrt(x float64) float64 {
	var prevz float64
	z := 1.0
	for math.Abs(prevz-z) > 0.001 {
		prevz = z
		z -= (z*z - x) / (2 * z)
		fmt.Println(z)
	}
	return z
}

func Os() string {
	switch os := runtime.GOOS; os {
	case "darwin":
		return "OS X"
	case "linux":
		return "Linux"
	default:
		return os
	}
}

func Saturday() {
	switch today := time.Now().Weekday(); time.Saturday {
	case today:
		fmt.Println("TODAY")
	case today + 1:
		fmt.Println("Tomorrow")
	case today + 2:
		fmt.Println("2 days")
	default:
		fmt.Println("Far away")
	}
}

func count() {
	fmt.Println("counting")
	i := 0
LOOP:
	defer fmt.Println(i)
	i++
	if i < 10 {
		goto LOOP
	}
	fmt.Println("done")
}

func slice() {
	names := [4]string{"a", "b", "c", "d"}
	fmt.Println(names)
	a := names[0:2]
	b := names[1:3]
	fmt.Println(a, b)
	b[0] = "HI"
	fmt.Println(a, b)
	fmt.Println(names)
}

func ranges() {
	// only works for slices and maps (not arrays)
	pow := []int{1, 2, 4, 8, 16, 32, 64, 128}
	// append to slice (dynamically increases capacity)
	pow = append(pow, 256, 512, 1024, 2048)
	for i, v := range pow {
		fmt.Printf("2**%d = %d\n", i, v)
	}
	// remake pow with make and useless variable
	newPow := make([]int, 10)
	for i := range newPow {
		newPow[i] = 1 << uint(i) // = 2 ** i
	}
	// _ assigns value to nothing (like /dev/null)
	for _, value := range newPow {
		fmt.Printf("%d\n", value)
	}
}

func Pic(dx, dy int) [][]uint8 {
	picture := make([][]uint8, dy)
	for x := 0; x < dy; x++ {
		picture[x] = make([]uint8, dx)
		for y := 0; y < dx; y++ {
			picture[x][y] = uint8((x + y) / 2)
			// picture[x][y] = uint8(x*y)
			// picture[x][y] = uint8(x ^ y)
		}
	}
	return picture
}

// type Vertex struct {
// 	Lat, Long float64
// }

var m map[string]Vertex

func mapFun() {
	m = make(map[string]Vertex)
	m["Bell Labs"] = Vertex{
		40.68433, -74.39967, // trailing comma is required
	}
}

var mapLiteral = map[string]Vertex{
	"Bell Labs": {
		40.68433, -74.39967, // trailing comma is required
	},
	"Google": {
		37.42202, -122.08408,
	},
}

func mutateMap() {
	mutate := make(map[string]int)
	mutate["Answer"] = 42
	fmt.Println("the value:", mutate["Answer"])
	mutate["Answer"] = 48
	fmt.Println("The value:", mutate["Answer"])
	delete(mutate, "Answer")
	fmt.Println("The value:", mutate["Answer"])
	v, ok := mutate["Answer"]
	fmt.Println("The value:", v, "Present?", ok)
}

func WordCount(s string) map[string]int {
	wordMap := make(map[string]int)
	for _, word := range strings.Fields(s) {
		wordMap[word] += 1
	}
	return wordMap
}

func compute(fn func(float64, float64) float64) float64 {
	return fn(3, 4)
}

// test the function returning properties of compute
func testFunctions() {
	hypot := func(x, y float64) float64 {
		return math.Sqrt(x*x + y*y)
	}
	fmt.Println(hypot(5, 12))
	fmt.Println(compute(hypot))
	fmt.Println(compute(math.Pow))
}

func adder() func(int) int {
	sum := 0
	return func(x int) int {
		sum += x
		return sum
	}
}

func testAdder() {
	pos := adder()
	for i := 0; i < 10; i++ {
		fmt.Printf("Iteration: %d, Value of function, %d\n", i, pos(i))
	}
}

func fibonacci() func() int {
	var prev, curr int
	return func() int {
		tmp := curr
		if curr == 0 {
			prev = 0
			curr = 1
		}
		curr = curr + prev
		prev = tmp
		return tmp;
	}
}

func testFib() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}

// func main() {
// 	testFib()
// }
