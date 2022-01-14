.data

.text
main:   addi    t1, x0, 0  # i = 0
        addi    t2, x0, 6 # n = 6
        addi    t3,x0, 1 #  1
        addi    t4,x0, 2 #  2
        addi    t5,x0, 3 # 3

loop:   beq     t2, t3, finish #while n != 1
        addi    t1, t1, 1  #i = i+1
        rem     t6,t2,t4  #n%2
        bne     t6,x0, else #n%2 ==0
        div     t2,t2,t4 #n = n/2
        j loop

else:  mul  t2,t2,t5 # 3*n
       addi t2,t2,1 # (3*n) +1
       j loop

finish: addi a0, x0, 1
        mv  a1,t1
        ecall 
        addi a0,x0,10
        ecall
       