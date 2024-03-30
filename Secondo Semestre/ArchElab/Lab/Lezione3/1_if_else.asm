# Convert the code fragments into RISC-V
.globl _start

.text
_start:
        ######################
        # First code fragment
        # x = x - y
        # if (x < 0)
        #     x = 0
        # y = y - 1
        ######################

        li    t0, 2
        li    t1, 1

        sub   t0, t0, t1            # x = x - y
        bge   t0, zero, end1        # if !(x < 0) jump
        li    t0, 0              	#   x = 0
end1:                               # fi
        addi  t1, t1, -1            # y = y - 1

        ######################
        # Second code fragment
        # x = (x - 2) + y
        # if (x < y)
        #   x = x + 1
        # else
        #   y = y + 1
        ######################

        li    t0, 1
        li    t1, 2

        addi  t0, t0, -2            # x = (x - 2)
        add   t0, t0, t1            # x = x + y

        bge   t0, t1, else2         # if !(x < y) jump
        addi  t0, t0, 1             # x = x + 1
        j     end2                  # end
else2:
        addi  t1, t1, 1             # y = y + 1
end2:                               # fi

exit:
        li    a7, 10                # call number 10 = exit
        ecall
