package problems

import (
	"math"
	"math/bits"
)

func divide(dividend int, divisor int) int {
	if dividend == math.MinInt32 && divisor == -1 {
		return math.MaxInt32
	}
	pos := true
	if dividend < 0 {
		dividend = -dividend
		pos = false
	}
	if divisor < 0 {
		divisor = -divisor
		pos = !pos
	}

	if dividend < divisor {
		return 0
	}

	q := 0
	r := dividend

	shifts := bits.Len(uint(dividend)) - bits.Len(uint(divisor))

	for i := shifts; i >= 0; i-- {
		d := divisor << i

		if r-d >= 0 {
			q += 1 << i
			r -= d
		}
	}

	if pos {
		return q
	}
	return -q

}
