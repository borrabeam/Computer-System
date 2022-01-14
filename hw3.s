.data
source: .word 4587901
newline:    .asciiz "\n"
.text

# x = factorial(4)
# x -> s0
addi a0, x0, 4 # a0 = 4
jal factorial # factorial(4)
mv s0, a0 # x = factorial(4)

# print_int
addi a0, x0, 1
mv a1, s0
ecall


la t2,source 
lw a0,0(t2) 
jal num_digits # num_digits(4587901)
mv s0, a0 # x = num_digits(4587901)

addi a0, x0, 4 # print string
la a1, newline # print new line
ecall

# print_int
addi a0, x0, 1
mv a1, s0
ecall


# exit
addi a0, x0, 10
ecall

factorial:
# if (n == 0) goto return 1
beq a0, x0, exit_1

# if (n !=0)
# factorial(n - 1)

addi sp, sp, -4 # push a0
sw a0, 0(sp) # push a0
addi sp, sp, -4 # push ra
sw ra, 0(sp) # push ra
addi a0, a0, -1 # n - 1

jal factorial

# a0 = factorial(n - 1)
lw t1, 4(sp) # t1 = a0
mul a0, a0, t1 # factorial(n - 1) * n
lw ra, 0(sp) # restore the correct return address to ra
addi sp, sp, 8
jr ra


num_digits:
# if (n < 10) return 1;

addi t4, x0, 10 #t4= 10
blt a0, t4, exit_1


addi sp, sp, -4 # push a0
sw a0, 0(sp) # push a0
addi sp, sp, -4 # push ra
sw ra, 0(sp) # push ra
div a0,a0,t4 # n / 10

jal num_digits


lw t1, 4(sp) # t1 = a0
addi a0, a0,1 # 1 + num_digits(n / 10) 
lw ra, 0(sp) # restore the correct return address to ra
addi sp, sp, 8
jr ra

exit_1:
addi a0, x0, 1
jr ra