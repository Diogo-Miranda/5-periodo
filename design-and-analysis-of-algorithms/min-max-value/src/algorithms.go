package main

type list []int8

const maxInt = int8(^uint8(0) >> 1)
const minInt = -maxInt - 1

func newList() list {
	return list{10, 3, 2, 20, 5, 30, 5, -1}
}

func (l list) findMaxAndMinUsingList() (int8, int8) {
	lenght := len(l)
	if len(l)%2 != 0 {
		lenght = lenght - 1
	}

	lMin := []int8{}
	lMax := []int8{}
	for i := 0; i < lenght; i += 2 {
		if l[i] >= l[i+1] {
			lMax = append(lMax, l[i])
			lMin = append(lMin, l[i+1])
		} else {
			lMax = append(lMax, l[i+1])
			lMin = append(lMin, l[i])
		}
	}

	min := lMin[0]
	max := lMax[0]

	for i := 1; i < len(lMin); i++ {
		if min > lMin[i] {
			min = lMin[i]
		}
	}

	for i := 1; i < len(lMax); i++ {
		if max < lMax[i] {
			max = lMax[i]
		}
	}

	return min, max
}

func (l list) findMaxAndMinUsingSwap() (int8, int8) {
	for i := 0; i < len(l); i += 2 {
		if l[i] < l[i+1] {
			// swap
			aux := l[i]
			l[i] = l[i+1]
			l[i+1] = aux
		}
	}

	max := l[0]
	min := l[1]
	for i := 2; i < len(l); i += 2 {
		if max < l[i] {
			max = l[i]
		}

		if min > l[i+1] {
			min = l[i+1]
		}
	}

	return min, max
}

func (l list) findMaxAndMinUsingSequencialFinding() (int8, int8) {
	max := minInt
	min := maxInt

	for i := 2; i < len(l); i++ {
		if l[i] > max {
			max = l[i]
		}

		if l[i] < min {
			min = l[i]
		}
	}

	return min, max
}
