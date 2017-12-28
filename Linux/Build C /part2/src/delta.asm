

        section .bss
a: resq 1
b: resq 1
c: resq 1
b2: resq 1
fac: resq 1
deltaa: resq 1
        section .data
four: dq 4

        global delta
        section .text
        ;extern printf
delta:
        push rbp
        mov rbp, rsp
        movq [a], xmm0
        movq [b], xmm1
        movq [c], xmm2
        fld qword[b]
        fmul qword[b]
        fstp qword[b2]

        fild qword[four]
        fmul qword[a]
        fmul qword[c]
        fstp qword[fac]

        fld qword[b2]
        fsub qword[fac]
        fstp qword[deltaa]
        movq xmm0,[deltaa]
        pop rbp
        ret
