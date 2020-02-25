  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #

.global delay
.global time2string
.global enable_interrupt

.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #
.text

 hexasc:
 	andi $t0,$a0, 0xf	#plocka ut sista fyra 
 	ble $t0, 9, digits	#kolla om mindre eller lika med 9, om sant gå till digits
 	nop
 	addi $t0,$t0, 0x37  	#för att få rätt värde motsvarade bokstav
 	move $v0, $t0		# flytta till $v0
 	jr $ra			#hoppa tillbaka
 	nop
 digits:
 	addi $t0,$t0, 0x30 	#för att få rätt värde motsvarande siffra
 	move $v0, $t0		#flytta till $v0
 	jr $ra			#hoppa tillbaka
 	nop
 	
 delay:
 	PUSH $ra
 	PUSH $s0
 	move $s0,$a0		#apara a0 till s0, så att vi 
 	andi $t1,$t1,0		#ms
 	addi $t1,$t1, 9000
 	andi $t2,$t2, 0		#0
 	
 	ble $s0,$t2, while_end #om a0<=0
 	nop
 while:
 	addi $s0, $s0, -1
 	
 	andi $t0,$t0,0		#i
 	addi $t0,$t0,1
 	beq $t0, $t1, for_end
 	nop
 for: 
 	addi $t0, $t0, 1
 	bne $t0,$t1, for
 	nop
 for_end:
 
 bne $s0,$t2, while
 nop
 while_end:
 	andi $t0,$t0,0
 	POP $s0
 	POP $ra
 	jr $ra
 	nop
 	
 time2string:
 	PUSH $s0
 	PUSH $ra
 	

 
 	move $s0,$a0
 	move $a0,$a1
 	
 	andi $t0,$t0, 0
 	andi $t1,$t1, 0
 	move $t1, $a0
 	andi $t1,$t1,0xffff
 	beq $t1,$t0, hour
 	
 	jal hexasc
 	nop
 	sb $v0,4($s0) # ental sekund
 	
 	srl $a0,$a0,4
 	jal hexasc
 	nop
 	sb $v0,3($s0) # tiotal sekund
 	
 	andi $t0,$t0,0
 	addi $t0,$t0, 0x3A
 	sb $t0,2($s0) # kolon 
 	
 	srl $a0,$a0,4
 	jal hexasc
 	nop
 	sb $v0,1($s0)	#ental minut
 	
 	srl $a0,$a0,4
 	jal hexasc
 	nop
 	sb $v0,0($s0) #tiotal minut
 	sb $zero,5($s0)
 	
 	move $a0,$s0
 	POP $ra
 	POP $s0
	jr $ra
	nop

hour:

	
	andi $t2,$t2,0
	andi $t3,$t3,0
	andi $t4,$t4,0
	andi $t5,$t5,0
	
	sb $t2,4($s0)
	addi $t2,$t2, 0x48
	addi $t3,$t3,0x4f
	addi $t4,$t4,0x55
	addi $t5,$t5,0x52
	
	sb $t5, 3($s0)
	sb $t4, 2($s0)
	sb $t3, 1($s0)
	sb $t2, 0($s0)

	
	 	 	
 	move $a0,$s0
 	POP $ra
 	POP $s0
	jr $ra
	nop

enable_interrupt:
	ei
	jr $ra