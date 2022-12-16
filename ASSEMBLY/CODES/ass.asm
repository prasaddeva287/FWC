.include "/home/prasaddeva287/prasad/assembly/codes/m328Pdef.inc"
 
ldi r16,0b00111000
out DDRD,r16
loop:   ;loop for reading the input from pins 2,3,4,5 continously
        ldi r17, 0b00000100 ;

        ldi r24,0b00000100
        mov r18,r17
        and r18,r24
        ldi r25,0b00000010
        loop1:  lsr r18  ;A
        dec r25
        brne    loop1

        mov r19,r17
        ldi r24,0b00001000
        and r19,r24
        ldi r25,0b00000011
        loop2:  lsr r19   ;B
        dec r25
        brne    loop2

        ldi r24,0b00010000
        mov r20,r17
        and r20,r24
        ldi r25,0b00000100
        loop3:  lsr r20  ;C
        dec r25
        brne    loop3

        ldi r24,0b00000000
        mov r21,r17
        and r21,r24
        ldi r25,0b00000101
        loop4:  lsr r21  ;D
        dec r25
        brne    loop4
    
  ldi r31,0x00
  mov r31,r18
  com r31 ;A complement

  ldi r30,0x00
  mov r30,r19
  com r30 ;B complement
 
  ldi r29,0x00
  mov r29,r20
  com r29 ;C  complement
 
  ldi r28,0x00
  mov r28,r21
  com r28 ;D  complement

and r18,r29 ;AC'
and r31,r19,r21 ;A'BD
and r31,r30,r20 ;A'B'C
and r18,r19,r28 ;ABD'
or r18,r31

and r18,r31
 ldi r26,0b00000101
        loop5:  lsl r31 
        dec r26
        brne    loop5
     out PORTB,r31
     rjmp loop

