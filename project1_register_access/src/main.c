/* Project 1 - Register Access
Purpose: Access memory, registers, directly, using pointers. Blink a led to illustrate it.    

    Led blinking on ARM platforms
    
    1. Enable clock for GPIO module (On ARM, before using any peripheral, its clock has to be enabled).
        . Locate in reference manual(RM) the clocking chapter/module, which controls the clock enable to every peripheral.   
        . Search RM for "memory map".
        . Locate the table which contains addresses in chapter: Memory map and register boundary addresses.
        . Search for the clocking module name(RCC) in the memory map table for the specific microcontroller used.
        . The starting address is the module base address(the address in memory where all the module`s registers are stored).
        . NOTE: Check using the debugger that the base address for RCC module, found in the table, is the actual
                address where the registers used for RCC control are stored.
            . Start a debug session(Ctrl+F5) using any compilable project (the "empty_project_fx" from the same folder for example)
            . View the actual, physicall memory of the microcontroller.
            . Open a memory view: View - Memory Windows - Memory x (doesnt matter which number, all show the same memory).
            . In the address field, type the address found in the memory map table as base address for RCC module(0x40021000 for F3 board for ex.).
            . Now the memory window should display the actual content found in memory at that address.
            . The default display mode is to show the memory as bytes(char,8bit size), something like: 83 54 00 00 ...
            . For a better view, the memory should be displayed as int(32bits, 4 bytes size), something like: 00005483 00000000 ...
            . To change view, right click in memory window - Unsigned - Int. The content displayed is the same, only now is grouped four bytes at a time.
            . Open the RCC module chapter in RM, and go to "RCC register map".
            . All the registers shown in RCC register map, are put in memory starting from the module`s base address.
            . Compare the content/reset value of the first register(RCC_CR) with the value stored at the module`s base address(0x40021000). 
            . The values should be equal. 
                    RCC_CR register reset value = 0b...0 0 0 0 0 0 x x x x x x x x 1 0 0 0 0 0 1 1
                    Value in memory = 0x00005483= 0b...0 0 0 0 0 0 0 1 0 1 0 1 0 0 1 0 0 0 0 0 1 1
            . You can also check using the Peripherals menu of the debugger. Pheripherals - System Viewer - RC - CR register field.
            . This confirms that all the registers for all the modules in RM can be found in memory at the address composed as
                the module base address(from memory map) plus its offset from the register map or register description, in the modules chapter.
    2. Set GPIO pins as output mode (using options from GPIO module registers).
    3. Turn GPIO pin output HIGH/LOW (using options from GPIO module registers).
    

TODO:   
    1. Create empty project for F3 and F4 targets.
    2. Add pictures in a document for all steps.
    3. Show using that enabling the clock to GPIOD, will activate the memory values.
*/

//0x4002 1000 RCC
int main(void){

    while(1)
    {}

    return 1;
}
