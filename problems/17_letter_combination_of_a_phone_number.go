package problems

func letterCombinations(digits string) []string {
	zeroRune := []rune("0")[0]
	a := [][]string{
		{},
		{},
		{"a", "b", "c"},
		{"d", "e", "f"},
		{"g", "h", "i"},
		{"j", "k", "l"},
		{"m", "n", "o"},
		{"p", "q", "r", "s"},
		{"t", "u", "v"},
		{"w", "x", "y", "z"},
	}

	total := 1
	chars := []rune(digits)

	charVals := make([]int, len(chars))
	divisor := make([]int, len(chars))
	for i := len(chars) - 1; i >= 0; i-- {
		charVal := int(chars[i] - zeroRune)
		charVals[i] = charVal
		divisor[i] = total
		total *= len(a[charVal])
	}

	output := make([]string, 0, total)
	for i := range total {
		s := ""
		for j, div := range divisor {
			len := len(a[charVals[j]])
			s += a[charVals[j]][i/div%len]
		}
		output = append(output, s)
	}
	return output
}
