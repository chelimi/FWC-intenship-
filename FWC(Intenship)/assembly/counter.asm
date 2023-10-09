.include"/storage/self/primary/Download/FWC/fwc-1/assembly/piosetup/m328Pdef/m328pdef.inc"
ldi r21,0b00000111
out DDRB,r21
ldi r24,0b00000100
out DDRD,r24

ldi r22,0b00000000
ldi r23,0b00000001
loop:
add r22,r23
cpi r22,0b00000101
breq check
cbi PORTD,2
cpi r22,0b00001000
brne rst
ldi r22,0b00000000
check:
mov r24,r22
out PORTD,r24
rjmp rst
rst:
mov r21,r22
out PORTB,r21
call wait

wait:
    push r16
    push r17
    push r18

    ldi r16,0x50
    ldi r17,0x00
    ldi r18,0x00

w0:
   dec r18
   brne w0 ;loop breaks after running 256 times
   dec r17
   brne w0 ;loop breaks after running 256 times
   dec r16 brne w0 ;loop breaks after running 80 times
   pop r18
   pop r17 pop r16
   rjmp loop
