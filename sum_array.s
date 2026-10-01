.global sum_array
.text

sum_array:
    xorl %eax, %eax # Clear accumulator (sum = 0)
    testq %rsi, %rsi # Check if count <= 0
    jle .Ldone # If count <= 0, jump to return

    xorq %rcx, %rcx # Loop index i = 0

.Lloop_start:
    addl (%rdi,%rcx,4), %eax # sum += arr[i] (base: %rdi, index: %rcx, scale: 4)
    incq %rcx # i++
    cmpq %rsi, %rcx # Compare index (%rcx) with count (%rsi)
    jl .Lloop_start # If i < count, repeat loop

.Ldone:
    ret # Return with sum in %eax

.section .note.GNU-stack,"",@progbits
