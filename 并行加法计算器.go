//go:build ignore

package main

import (
	"fmt"
	//"container/list"
	//"sort"
	//"math/rand"
	//"math"
	//"strings"
	"runtime"
	"sync"
	"time"
)

var res int

var mu sync.Mutex

func add(s int, l int) {
	for i := s; i < s+l; i++ {
		mu.Lock()
		res += i
		mu.Unlock()
	}
}
func main() {
	res = 0
	for i := 0; i < 1000; i++ {
		go add(i*100+1, 100)
	}
	for runtime.NumGoroutine() != 1 {
		time.Sleep(time.Second)
	}
	fmt.Println(res)
}
