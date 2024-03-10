package main

import "fmt"

var memory [256]int32

func main() {
    fmt.Println("Test")
    push_to_memory(12, 45)
    push_to_memory(15, 75)
    res := pop_from_memory(12) + pop_from_memory(15)
    fmt.Println(res)
}

func push_to_memory(key, value int32) {
    memory[key] = value
}

func pop_from_memory(key int32) int32 {
    value := memory[key]
    memory[key] = 0
    return value
}