
.data
source: .word 6079
.text
main:   
        addi    t2, x0, 0 # k
    	la		t3, source
        lw		t4, 0(t3) #t4 = 6079
        addi	t5,t0,1 #n = 1
        bne		t4,t5,else # n == 1
        addi    t1, x0, 0  # is_prime = 0
        j finish

else:  addi t1,x0,1 # is_prime = 1
	   addi  t2, x0, 2 # k = 2

loop:	blt	t2,t5 k_plus# k<n
		j finish

if:	rem	s1,t5,t2 #n%k
	bne s1,x0, k_plus # n%k == 0
    addi t1,x0,0 #is_prime = 0
    j finish
    

k_plus: addi t2,x0,1 #k++
	j loop

finish: addi a0, x0, 1
        mv  a1,t1
        ecall 
        addi a0,x0,10
        ecall
       

