.text

main:
# x = fib(9)
# printf("%d\n", x)
addi a0, x0, 9 # place 9 to a0
jal fib
# the return value is in a0

# printf("%d", x)
mv a1, a0
addi a0, x0, 1
ecall

# exit cleanly
addi a0, x0, 10
ecall

fib:

# if (n == 0) goto termination_case_1
beq a0, x0, termination_case_1

# if (n == 1) goto termination_case_2
addi t0, x0, 1 # place the value 1 into t0
beq a0, t0, termination_case_2

# translate a call to fib(n - 1)
# save a0 and ra on to the stack
addi sp, sp, -8
sw a0, 4(sp)
sw ra, 0(sp)

# place n - 1 to a0
addi a0, a0, -1
jal fib

# restore a0 (represent n) and ra
lw t0, 4(sp) # restore a0 (represent n) to t0)
lw ra, 0(sp)
addi sp, sp, 8

# the result of fib(n - 1) will be placed in a0
addi sp, sp, -8
sw a0, 4(sp)
sw ra, 0(sp)

# translate a call to fib(n - 2)
addi a0, t0, -2
jal fib

# need to restore the value of fib(n - 1) and ra
lw t0, 4(sp) # fib(n - 1) value is restored to t0
lw ra, 0(sp)
addi sp, sp, 8

# the result of fib(n - 2) will be placed in a0
add a0, t0, a0
jr ra


termination_case_1:
# place 0 into a0 as a return value
addi a0, x0, 0
jr ra

termination_case_2:
# place 1 into a0 as a return value
addi a0, x0, 1
jr ra
