package main

import (
	// "fmt"
	// "math"
)

// // type MyFloat float64
// type Vertex struct {
// 	X, Y float64
// }

// // method version of abs
// func(v Vertex) Abs() float64 {
// 	return math.Sqrt(v.X*v.X + v.Y * v.Y)
// }

// // function version of abs
// func Abs(v Vertex) float64 {
// 	return math.Sqrt(v.X * v.X + v.Y * v.Y)
// }

// // method on a nonstruct (float64)
// func (f MyFloat) Abs() float64 {
// 	if f < 0 {
// 		return float64(-f)
// 	}
// 	return float64(f)
// }

// pointer receiver for vertex (allows the function to
// modify the value of vertex
func (v *Vertex) Scale(f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

// function version of scal
func Scale(v *Vertex, f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

// func main() {
// 	v := Vertex{3, 4}
// 	Scale(&v, 10)
// 	fmt.Println(v.Abs())
// }
