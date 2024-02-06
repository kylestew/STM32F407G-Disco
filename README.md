# STM32F407G-Disco
Learning examples for the STM32F407G-DISC1 board from STM





starting debugger:

openocd -f interface/stlink.cfg -f target/stm32f4x.cfg



example flashing:

openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program apps/01-miniblink/01-miniblink.bin 0x8000000 verify reset exit"


openocd -f interface/<your debugger>.cfg -f target/<your target>.cfg \ 
     -c "program file.elf verify reset exit"