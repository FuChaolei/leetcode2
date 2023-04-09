//go:build ignore

package main

import (
	"fmt"
	//"container/list"
	//"sort"
	//"math/rand"
	//"math"
	//"strings"
)

type Abstractfruit interface {
	ShowName()
}
type Apple struct {
}

func (apple *Apple) ShowName() {
	fmt.Println("我是苹果")
}

type Banana struct {
}

func (banana *Banana) ShowName() {
	fmt.Println("我是香蕉")
}

type Abstractfactory interface {
	Createfruit() Abstractfruit
}
type AppleFactory struct {
}

func (afactory *AppleFactory) Createfruit() Abstractfruit {
	return new(Apple)
}

type BananaFactory struct {
}

func (bfactory *BananaFactory) Createfruit() Abstractfruit {
	return new(Banana)
}
func main() {
	var factory Abstractfactory
	var fruit Abstractfruit
	factory = new(AppleFactory)
	fruit = factory.Createfruit()
	fruit.ShowName()
	factory = new(BananaFactory)
	fruit = factory.Createfruit()
	fruit.ShowName()
}
