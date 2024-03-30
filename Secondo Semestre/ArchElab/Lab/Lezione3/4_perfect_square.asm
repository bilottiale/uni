# Convert the following C function into RISC-V
# Calculates the sum of the first N perfect square integers
#
# int N=10;
# int S=0;
# int i;
# for (i=1; i<=N; ++i){
#   S = S + i*i;
# }
#

.globl _start

.text
_start:
        li    t0, 10         # N
        li    t1, 0          # S

        li    t2, 1          # i=1
loop1:
        bgt   t2, t0, end1   # if (i > N) jump

        mul   t3, t2, t2     # t3 = i*i
        add   t1, t1, t3     # S = S + t3;

        addi  t2, t2, 1      # i++
        j     loop1          # jump for
end1:

print:
        addi  a0, t1, 0    	 # print the result
        li    a7, 1
        ecall
exit:
        li    a7, 10         # call number 10 = exit
        ecall
