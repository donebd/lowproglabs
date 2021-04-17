.rodata             # секция неизменяемых данных
array_length:       # создание переменной длинны массива (степень многочлена + 1)
.word 4             # минимум 2 элемента (иначе, полином равен константе)
x:                  # создание переменной X0 
.word -7
array:
.word 1, 0, 0, 0        # сам массив (состоит из коэффициентов многочлена)
 
.text               # директива размещения инструкций в секции кода
__start:            # метка "точки" программы
.globl __start      # эта директива старта выполнения программы

addi t0, zero, 1    # i = 1
la t2, array_length
lw t2, 0(t2)        # t2 = array.size
la t1, array        # t1 = array[0]/address
lw a2, 0(t1)        # a2 = array[0]
la t3, x
lw t3, 0(t3)        # t3 = x

j checkLoop         # goto checkLoop
loop:
slli t4, t0, 2      # t4 = i*4 (смещение по адресу)
add t5, t1, t4      # t5 = array[i]/address
lw t5, 0(t5)        # t5 = array[i]
mul a2, a2, t3      # a2 *= x
add a2, a2, t5      # a2 += array[i]
addi t0, t0, 1      # i++
checkLoop: 
bgtu t2,t0, loop    # if(array.size>i) goto loop

li a0, 1            # a0 = 1
mv a1, a2           # a1 = a4 
ecall               # системный вызов, печать результата

li a0, 10
ecall