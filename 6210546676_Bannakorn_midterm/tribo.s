.data
newline:    .asciiz "\n"
.text

main:

addi s1,x0,0 #i = 0
addi s2,x0,15 #15


loop:
bge s1,s2,exit

add a0,x0,s1 #i = 0
jal tribo

# printf("%d", x)
mv a1, a0
addi a0, x0, 1
ecall


addi s1,s1,1 #i++

addi a0, x0, 4 # print string
la a1, newline # print new line
ecall

j loop


exit:
# exit cleanly
addi a0, x0, 10
ecall




tribo:
addi s3,x0,2 #s3 = 2
blt a0,s3, first_case # if (n < 2)

beq a0,s3, second_case #if (n == 2)



#translate tribo(n-1)
#save a0 and ra to the stack
addi sp, sp, -16
sw a0, 4(sp) 
sw ra,0(sp)


#place n-1 to a0
addi a0,a0,-1
jal tribo



#restore a0 and ra
lw t0,4(sp) #a0 to t0
lw ra,0(sp)
addi sp,sp,16



#a0 = result
addi sp,sp, -16
sw t0, 4(sp)
sw a0, 8(sp)
sw ra, 0(sp)



#place n-2 to a0
addi a0,t0,-2
jal tribo



#restore a0 and ra
lw t0,4(sp) #a0 to t0 #4(sp) = n
lw t1,8(sp) #a0 to t1 #8(sp) tribo n-1
lw ra,0(sp)
addi sp,sp,16



#a0 = result
addi sp,sp, -16
sw t0, 4(sp) #t0 = n
sw t1, 8(sp) #t1 =tribo n-1
sw a0, 12(sp) #tribo n-2
sw ra, 0(sp)



#place n-3 to a0
addi a0,t0,-3
jal tribo


#restore a0 and ra
lw t0,4(sp) #a0 to t0 #4(sp) = n
lw t1,8(sp) #a0 to t1 #8(sp) tribo(n-1)
lw t2,12(sp) #a0 to t2 #12(sp) = tribo(n-2)
lw ra,0(sp)
addi sp,sp,16


#a0 = result
add a0,t1,a0 #tribo(n-3) + tribo(n-1) 
add a0,t2,a0 #(tribo(n-3) + tribo(n-1)) + tribo(n-2)
jr ra


first_case:
addi a0,x0,0 #return 0
jr ra


second_case:
addi a0,x0,1 #return 1
jr ra


