# Convert the following C function into RISC-V
#
# for (i=0; i<a; i++) {
#	  for (j=0; j<b; j++) {
#		   R = 2*R + i + j;
#   }
# }
.globl _start

.text
_start:
        li   t0, 10           # a
        li   t1, 5            # b
        li   t2, 0            # R

        li   t3, 0           # i=0
LOOPI:
        bge  t3, t0, ENDI    # when (i>=a) jump

        li   t4, 0           # j
LOOPJ:
        bge  t4, t1, ENDJ    # when (j>=b) jump

        add  t2, t2, t2      # R=2R
        add  t5, t3, t4      # i+j
        add  t2, t2, t5      # R+=i+j

        addi t4, t4, 1      # j++
        j    LOOPJ
ENDJ:

        addi t3, t3, 1      # i++
        j    LOOPI
ENDI:


print:
        addi  a0, t2, 0    	 # print the result? oops!
        li    a7, 1
        ecall
exit:
        li    a7, 10         # call number 10 = exit
        ecall
