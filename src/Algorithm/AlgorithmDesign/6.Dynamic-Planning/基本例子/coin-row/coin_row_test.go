package coinrow

import "testing"

func TestCoinRow(t *testing.T) {
	coin := []int{5, 1, 2, 10, 6, 2}
	if CoinRow(coin) != 17 {
		t.Fail()
	}
}
