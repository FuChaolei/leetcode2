//go:build ignore

package main

import "fmt"

//"container/list"
//"sort"
//"math/rand"
//"math"
//"strings"
type AbstractFruit interface {
	ShowName()
}
type Apple struct {
}

func (apple *Apple) ShowName() {
	fmt.Println("apple")
}

type Banana struct {
}

func (banana *Banana) ShowName() {
	fmt.Println("banana")
}

type Factory struct {
}

func (factory *Factory) Createfruit(s string) AbstractFruit {
	if s == "apple" {
		return new(Apple)
	} else if s == "banana" {
		return new(Banana)
	}
	return nil
}

func main() {
	factory := new(Factory)
	fruit := factory.Createfruit("apple")
	fruit.ShowName()
	//res := get_res()
}
