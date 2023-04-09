//go:build ignore

package main

import "fmt"

//"fmt"
//"container/list"
//"sort"
//"math/rand"
//"math"
//"strings"
type Hungry struct{}

var hungry *Hungry = new(Hungry)

func getInstace() *Hungry {
	return hungry
}
func (it *Hungry) do() {
	fmt.Println("dfvsdfg")
}

func main() {
	tmp := getInstace()
	tmp.do()
}
