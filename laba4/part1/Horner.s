	.file	"Horner.c"
	.option nopic
	.attribute arch, "rv64i2p0_a2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.globl	__muldf3
	.globl	__adddf3
	.align	1
	.globl	horner
	.type	horner, @function
horner:
	addi	sp,sp,-48
	sd	ra,40(sp)
	sd	s0,32(sp)
	sd	s1,24(sp)
	sd	s2,16(sp)
	sd	s3,8(sp)
	mv	s3,a0
	mv	s1,a1
	li	a5,1
	ble	a1,a5,.L8
	mv	s2,a2
	ld	a1,0(a0)
	mv	a0,a2
	call	__muldf3
	ld	a1,8(s3)
	call	__adddf3
	mv	a1,a0
	li	a5,2
	ble	s1,a5,.L1
	addi	s0,s3,16
	addiw	s1,s1,-3
	slli	a5,s1,32
	srli	s1,a5,29
	addi	s3,s3,24
	add	s1,s1,s3
.L4:
	mv	a0,s2
	call	__muldf3
	ld	a1,0(s0)
	call	__adddf3
	mv	a1,a0
	addi	s0,s0,8
	bne	s0,s1,.L4
.L1:
	mv	a0,a1
	ld	ra,40(sp)
	ld	s0,32(sp)
	ld	s1,24(sp)
	ld	s2,16(sp)
	ld	s3,8(sp)
	addi	sp,sp,48
	jr	ra
.L8:
	mv	a1,zero
	bne	s1,a5,.L1
	ld	a1,0(a0)
	j	.L1
	.size	horner, .-horner
	.ident	"GCC: (SiFive GCC-Metal 10.2.0-2020.12.8) 10.2.0"
