.rodata             # секция неизменяемых данных
array_length:       # создание переменной длинны массива (степень многочлена + 1)
.word 4             # минимум 2 элемента (иначе, полином равен константе)
x:                  # создание переменной X0 
.word 1
array:
.word 5, 0, 5, 1        # сам массив (состоит из коэффициентов многочлена)
array_length2:
.word 4 
array2:
.word 6, 0, 6, 5
msg: .string " "
 
.text               # директива размещения инструкций в секции кода
__start:            # метка "точки" программы
.globl __start      # эта директива старта выполнения программы

la a1, array_length
lw a1, 0(a1)        # a1 = array.size
la a2, array        # a2 = array[0]/address
la a3, x
lw a3, 0(a3)        # a3 = x
jal ra, fun         # вызов функции

li a0, 4            # a0 = 1
la a1, msg          # a1 = " "
ecall 

la a1, array_length2
lw a1, 0(a1)        # a1 = array.size
la a2, array2       # a2 = array[0]/address
la a3, x
lw a3, 0(a3)        # a3 = x
jal ra, fun         # вызов функции

li a0, 10
ecall

fun:
mv t3, a3           # t3 = x
mv t2, a1           # t2 = array.size
mv t1, a2           # t1 = array[0]/address
lw a2, 0(t1)        # a2 = array[0]
addi t0, zero, 1    # i = 1

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
ret                 # return