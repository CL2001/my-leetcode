package problems

func isValidSudoku(board [][]byte) bool {

	for i := range 9 {
		seen := make(map[byte]struct{}, 10)
		for j := range 9 {
			if _, exists := seen[board[i][j]]; exists && board[i][j] != '.' {
				return false
			}
			seen[board[i][j]] = struct{}{}
		}
	}

	for j := range 9 {
		seen := make(map[byte]struct{}, 10)
		for i := range 9 {
			if _, exists := seen[board[i][j]]; exists && board[i][j] != '.' {
				return false
			}
			seen[board[i][j]] = struct{}{}
		}
	}

	for adderIndex := range 9 {
		iAdder := (adderIndex / 3) * 3
		jAdder := (adderIndex % 3) * 3

		seen := make(map[byte]struct{}, 10)

		for preAddIndex := range 9 {
			iPreAdd := preAddIndex / 3
			jPreAdd := preAddIndex % 3

			i := iPreAdd + iAdder
			j := jPreAdd + jAdder

			if _, exists := seen[board[i][j]]; exists && board[i][j] != '.' {
				return false
			}
			seen[board[i][j]] = struct{}{}
		}
	}

	return true
}
