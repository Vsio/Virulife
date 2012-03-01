# ===========================
# File : helloWorld.asm
#
# Credit:
# - Coded by (aka in cyber) Vsio Stitched
#
# Misc:
# - Written in Assembly (MIPS) programming language
#
# License:
# - Free to use
# - May include me or not in credit if included in other project
# ===========================

.data

# VARIABLE DECLARATION #

beginProgram: .asciiz "\n== PROGRAM START ==\n\n"
endProgram: .asciiz "\n== PROGRAM END ==\n"
sayHelloWorld: .asciiz "Hello World!\n"

########################

.text
.globl main

# DRIVER #

main:

	li $v0, 4 # call print string
	la $a0, beginProgram # prints message
	syscall

	li $v0, 4 # call print string
	la $a0, sayHelloWorld # prints message
	syscall
	
	li $v0, 4 # call print string
	la $a0, endProgram # prints message
	syscall
	
###########