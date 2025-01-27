# r has two loops: while and for

# while loop: print numbers 1-100

i <- 1
while (i < 101) {
	print(i)
	i <- i + 1
}

# break statement: exit the loop when i is greater than 2

i <- 1
while (TRUE) {
	if (i > 2) {
		print("code is breaking")
		break
	}
	i <- i + 1
}

# next statement: skip a loop iteration (like the continue keyword in pytnon
# print every even number

i <- 0
while (i < 101) {
	i <- i + 1
	if (i %% 2 != 0) {
		next
	}
	print(i)
}
