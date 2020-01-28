package main

import (
	"fmt"
	"time"
)

// A首先被a阻塞，A()结束后关闭b，使b可读
func A(a, b chan struct{}) {
	<-a
	fmt.Println("A")
	time.Sleep(time.Second)
	close(b)
}

// B首先被a阻塞，B()结束后关闭b，使b可读
func B(a, b chan struct{}) {
	<-a
	fmt.Println("B")
	close(b)
}

// C首先被a阻塞
func C(a chan struct{}) {
	<-a
	fmt.Println("C")
}

func main() {
	x := make(chan struct{})
	y := make(chan struct{})
	z := make(chan struct{})

	go C(z)
	go A(x, y)
	go C(z)
	go B(y, z)
	go C(z)

	// 关闭x，让x可读
	close(x)
	time.Sleep(2 * time.Second)
}
