package coincollection

import "testing"

func TestRobotCoinCollection(t *testing.T) {
	graph := [][]int{
		{0, 0, 0, 0, 1, 0},
		{0, 1, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 1},
		{0, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 1, 0},
	}
	if RobotCoinCollection(graph, 4, 5, 0) != 5 {
		t.Fail()
	}
}

func TestDPRobotCoinCollection(t *testing.T) {
	graph := [][]int{
		{0, 0, 0, 0, 1, 0},
		{0, 1, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 1},
		{0, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 1, 0},
	}
	if DPRobotCoinCollection(graph) != 5 {
		t.Fail()
	}
}
