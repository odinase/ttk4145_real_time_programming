package main

import (
	"fmt"
	"sync"
	"./test"
)

var i int = 0

func main() {
	var wg sync.WaitGroup
	wg.Add(2)
	go thread_1(&wg)
	go thread_2(&wg)
	wg.Wait()
	fmt.Println("i is now:", i)
}


func thread_1(wg *sync.WaitGroup) {
	defer wg.Done()
	for j := 0; j < 1000000; j++ {
		i++
	}
}

func thread_2(wg *sync.WaitGroup) {
	defer wg.Done()
	for j := 0; j < 1000000; j++ {
		i--
	}
}