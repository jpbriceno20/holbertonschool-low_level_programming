section .data
	msg db "Hello, World", 10  ; The string "Hello, World" followed by a newline
	len equ $ - msg            ; Calculate length of the string

section .text
	global _start

_start:
	; write(1, msg, len)
	mov rax, 1        ; sys_write system call number
	mov rdi, 1        ; file descriptor: 1 = stdout
	mov rsi, msg      ; address of the message to output
	mov rdx, len      ; number of bytes to write
	syscall

	; exit(0)
	mov rax, 60       ; sys_exit system call number
	xor rdi, rdi      ; exit status 0
	syscall
