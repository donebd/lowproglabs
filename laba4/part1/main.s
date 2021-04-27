	.file	"main.c"
	.option nopic
	.attribute arch, "rv64i2p0_a2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align	3
.LC2:
	.string	"[%.2f] "
	.align	3
.LC3:
	.string	"\nx=%f\nf(x)=%f"
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-80
	sd	ra,72(sp)
	sd	s0,64(sp)
	sd	s1,56(sp)
	sd	s2,48(sp)
	sd	s3,40(sp)
	lui	a5,%hi(.LANCHOR0)
	addi	a5,a5,%lo(.LANCHOR0)
	ld	a2,0(a5)
	ld	a3,8(a5)
	ld	a4,16(a5)
	ld	a5,24(a5)
	sd	a2,0(sp)
	sd	a3,8(sp)
	sd	a4,16(sp)
	sd	a5,24(sp)
	lui	a5,%hi(.LC1)
	ld	a2,%lo(.LC1)(a5)
	li	a1,4
	mv	a0,sp
	call	horner
	mv	s3,a0
	mv	s0,sp
	addi	s2,sp,32
	lui	s1,%hi(.LC2)
.L2:
	ld	a1,0(s0)
	addi	a0,s1,%lo(.LC2)
	call	printf
	addi	s0,s0,8
	bne	s0,s2,.L2
	mv	a2,s3
	lui	a5,%hi(.LC1)
	ld	a1,%lo(.LC1)(a5)
	lui	a0,%hi(.LC3)
	addi	a0,a0,%lo(.LC3)
	call	printf
	li	a0,0
	ld	ra,72(sp)
	ld	s0,64(sp)
	ld	s1,56(sp)
	ld	s2,48(sp)
	ld	s3,40(sp)
	addi	sp,sp,80
	jr	ra
	.size	main, .-main
	.section	.srodata.cst8,"aM",@progbits,8
	.align	3
.LC1:
	.word	-858993459
	.word	1073794252
	.section	.rodata
	.align	3
	.set	.LANCHOR0,. + 0
.LC0:
	.word	0
	.word	1078689792
	.word	0
	.word	1080037376
	.word	0
	.word	-1071120384
	.word	0
	.word	1075970048
	.ident	"GCC: (SiFive GCC-Metal 10.2.0-2020.12.8) 10.2.0"
