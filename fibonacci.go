package fibonacci

import "fmt"

func main() {
	fmt.Println(fibonacci(6))
}

func fibonacci(n int)(int){
	a := 1
	b := 1
	for i:=0;i<n;i++{
		b, a = a+b, b
	}
	return b
}
