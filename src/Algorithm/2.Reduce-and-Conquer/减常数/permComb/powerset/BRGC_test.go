package powerset

import (
	"fmt"
	"testing"
)

func TestRecover(t *testing.T) {
	var a = [][]byte{[]byte{0}, []byte{1}, []byte{2}}
	for i, v := range recoverCode(a) {
		if int(v[0])+i != 2 {
			t.Fail()
		}
	}

}

func TestShift(t *testing.T) {
	var data = [][]byte{[]byte{1}}
	data = shift(data, 0)
	if len(data[0]) != 2 && data[0][0] != 0 {
		t.Fail()
	}
}

func TestBRGC(t *testing.T) {
	for _, v := range BRGC(3) {
		fmt.Print(v, " ")
	}
}
