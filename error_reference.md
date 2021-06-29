# RGB_Led
The source files are contained in RGB.cpp and RGB.h.

test.ino(ino files are similar to cpp files) includes the RGB.h and tries to access the RGB::RED constant but gets this error:
/usr/lib/gcc/avr/9.2.0/../../../../avr/bin/ld: /tmp/RGB_LED.ino.elf.V0WZRt.ltrans0.ltrans.o: in function `digitalWrite':
/usr/share/arduino/hardware/arduino/avr/cores/arduino/wiring_digital.c:141: undefined reference to `RGB::RED'
/usr/lib/gcc/avr/9.2.0/../../../../avr/bin/ld: /usr/share/arduino/hardware/arduino/avr/cores/arduino/wiring_digital.c:141: undefined reference to `RGB::RED'
/usr/lib/gcc/avr/9.2.0/../../../../avr/bin/ld: /usr/share/arduino/hardware/arduino/avr/cores/arduino/wiring_digital.c:142: undefined reference to `RGB::RED'
collect2: error: ld returned 1 exit status
exit status 1
Error compiling for board Arduino Uno.


FIXED: Just added an inline identifier to the declaration of the constants. That error is there for future reference.
