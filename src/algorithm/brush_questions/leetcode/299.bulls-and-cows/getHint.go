package leetcode

import (
  "fmt"
)

func getHint(secret string, guess string) string {
    return fmt.Sprintf("%dA%dB", bulls(secret, guess), cows(secret, guess))
}

func bulls(secret string, guess string) int {
    var result = 0
    for i := 0; i < len(guess); i++ {
        if secret[i] == guess[i] {
          result++
        }
    }
    return result
}

func cows(secret string, guess string) int {
    var result = 0
    var seen = []byte(secret)
    for i := range guess {
        for j := range seen {
            if (guess[i] == seen[j]) {
                result++
                seen = append(seen[:j], seen[j+1:]...)
                break
            }
        }
    }
    return result - bulls(secret, guess)
}