# ------------------------
# FULL STACK TEST FILE
# ------------------------

# Start simple math
push 10
push 20
add
pall

push 50
push 25
sub
pall

push 100
push 4
div
pall

push 9
push 7
mul
pall

push 30
push 7
mod
pall

# Swap & pop
push 1
push 2
push 3
swap
pall

pop
pall

# Rotate left/right
push 5
push 6
push 7
push 8
push 9
rotl
pall

rotr
pall

# String test: HELLO
push 111
push 108
push 108
push 101
push 72
pstr

# NOP test
nop
nop

# Big rotation
push 10
push 20
push 30
push 40
push 50
rotl
rotl
rotl
pall

# Another math test
push 1000
push 2000
add
pall

# PCHAR test valid
push 65
pchar

# PCHAR test invalid
push 60
pchar

# Push many values
push 100
push 200
push 300
push 400
push 500
push 600
push 700
push 800
push 900
push 1000
pall

# Rotate and swap
rotl
swap
pall

# Pop several
pop
pop
pop
pall

# Final rotations
rotl
rotr
pall

# -----------------------------
# FINAL LINE - THE GRAND FINALE!
# MONTY ALX HOLBERTON AWESOME
# -----------------------------

# E (69), M (77), O (79), S (83), E (69), W (87), A (65)
push 69
push 77
push 79
push 83
push 69
push 87
push 65

# Space (32)
push 32

# N (78), O (79), T (84), R (82), E (69), B (66), L (76), O (79), H (72)
push 78
push 79
push 84
push 82
push 69
push 66
push 76
push 79
push 72

# Space (32)
push 32

# X (88), L (76), A (65)
push 88
push 76
push 65

# Space (32)
push 32

# Y (89), T (84), N (78), O (79), M (77)
push 89
push 84
push 78
push 79
push 77

# Print final line 🎉
pstr

# END OF TEST
