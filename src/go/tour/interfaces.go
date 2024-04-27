package main

import (
	"fmt"
	"math"
)

type Abser interface {
	Abs() float64
}

func testInterfaceAbs() {
	var a Abser
	f := MyFloat(-math.Sqrt2)
	v := Vertex{3, 4}
	a = f  // a MyFloat implements Abser
	a = &v // a *Vertex implements Abser
	// a = v // causes error because Vertex does not implement abser
	fmt.Println(a.Abs())
}

type I interface {
	M()
}

type T struct {
	S string
}

// method means type t implements the interface I implicitely (no explicity keyword)
func (t T) M() {
	fmt.Println(t.S)
}

func testM() {
	var i I = T{"hello"}
	i.M()
}

// func main() {
// 	testM()
// }

type MyFloat float64

func (f MyFloat) Abs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

type Vertex struct {
	X, Y float64
}

func (v *Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}
