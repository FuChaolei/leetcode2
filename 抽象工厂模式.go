//go:build ignore

package main

import (
	"fmt"
)

type abstractApple interface {
	ShowName()
}
type abstractBanana interface {
	ShowName()
}
type ChinaApple struct {
}

func (capple *ChinaApple) ShowName() {
	fmt.Println("中国苹果")
}

type ChinaBanana struct {
}

func (cbanana *ChinaBanana) ShowName() {
	fmt.Println("中国香蕉")
}

type USAApple struct {
}

func (mapple *USAApple) ShowName() {
	fmt.Println("美国苹果")
}

type USABanana struct {
}

func (mbanana *USABanana) ShowName() {
	fmt.Println("美国香蕉")
}

type AbstractFactory interface {
	CreateApple() abstractApple
	CreateBanana() abstractBanana
}
type ChinaFactory struct {
}

func (cfactory *ChinaFactory) CreateApple() abstractApple {
	return new(ChinaApple)
}
func (cfactory *ChinaFactory) CreateBanana() abstractBanana {
	return new(ChinaBanana)
}

type USAFactory struct {
}

func (cfactory *USAFactory) CreateApple() abstractApple {
	return new(USAApple)
}
func (cfactory *USAFactory) CreateBanana() abstractBanana {
	return new(USABanana)
}
func main() {
	var factory AbstractFactory
	var fruit abstractApple
	factory = new(ChinaFactory)
	fruit = factory.CreateApple()
	fruit.ShowName()
	factory = new(USAFactory)
	fruit = factory.CreateBanana()
	fruit.ShowName()
}
