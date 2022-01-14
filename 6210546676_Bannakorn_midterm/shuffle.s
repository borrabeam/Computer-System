.data
source: .word 7, 3, 9, 9, 6, 9, 8, 9, 8, 9
dest: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
newline:    .asciiz "\n"
.text

main: 
addi t1, x0, 0 # i = 0
addi t2, x0, 0 # r = 0
addi t3, x0, 0 # swap = 0
la t4,source #load address of source
la t5,dest# load address of dest
addi t6,x0,10 # t6 = 10
addi s3,x0,4 #t7 = 4


first_loop:
bge t1,t6, reset
mul s2,t1,s3 #s2 = i*4
add s5,t5,s2 # s5 = (i*4) + t5
lw s1,0(s5)
sw t1,0(s5)
addi t1,t1,1 #i++
j first_loop


reset: addi t1, x0, 0 # i = 0
la t5,dest # load first address of dest
j second_loop

second_loop:
bge t1,t6, reset2
mul s2,t1,s3 #s2 = i*4
add t2,t4,s2 # t2 = (i*4) + t4 #B[i]
add s5,t5,s2 # s5 = (i*4) + t5 #A[i]
lw s1,0(s5)
lw s6,0(t2) #s6 = r
mul s8,s6,s3 # r*4
add s7,t5,s8 # swap = A[r] 
lw s9,0(s7) 
lw s10,0(s5)
sw s10,0(s7)
sw s9,0(s5)


addi t1,t1,1 #i++


j second_loop

reset2:addi t1, x0, 0 # i = 0
la t5,dest # load first address of dest
j print

print:
bge t1,t6 exit
mul s2,t1,s3 #s2 = i*4
add s5,t5,s2 #s5 = (i*4) + t5 
lw s1,0(s5)


#print
addi a0, x0, 1
mv  a1,s1
ecall 
addi t1,t1,1 #i++

addi a0, x0, 4 # print string
la a1, newline # print new line
ecall

j print

exit:
addi a0, x0, 10
ecall