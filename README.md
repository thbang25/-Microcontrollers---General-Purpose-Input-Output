# -Microcontrollers---General-Purpose-Input-Output

The aim of this practical is to introduce you to the general purpose output (GPIO) capability of your
STMicroelectronics STM32F0 Microcontroller. We will also introduce you to basic C programming for
microcontrollers. You will also learn how to read the microcontroller reference manuals to identify which
registers are needed to control the system’s operation

Write a C function in your main.c file called void initGPIO(void), which initialises the Reset
and Clock Control ( RCC) and General Purpose Input Output ( GPIO) registers as described in the
pre-practical. i.e. initialises the port pins connected to the user controlled LEDs and pushbuttons.
The LEDs must be OFF by default.
Copy this code segment and upload it to the post-practical quiz on Amathuba.
(b) Create a function called void delay(void) which uses two nested for loops to create an
approximate 1 second delay. Create two symbolic constants, using pre-processor commands, called
DELAY1 and DELAY2. These will be used as the values for your for loops to count up to. You
can therefore change the length of your delay easily. 1
Copy this code segment and upload it to the post-practical quiz on Amathuba.
(c) Write code in your main for loop to turn on LED B0. Copy this code segment and upload it to
the post-practical quiz on Amathuba.
(d) Create three global variables called bitpattern1 , bitpattern2 and bitpattern3 which
hold the values that produce the following patterns on the red LEDS.
(i) bitpattern1
(ii) bitpattern2
(iii) bitpattern3
Copy this code segment and upload it to the post-practical quiz on Amathuba.
(e) Create two symbolic constants, using pre-processor commands, called TRUE and FALSE where
TRUE is equal to 1 and FALSE is equal to 0.
Copy this code segment and upload it to the post-practical quiz on Amathuba.
(f) Write a line of code in your main.c file, which will create a new variable type called flag_t of the
same form as uint8_t.
Copy this code segment and upload it to the post-practical quiz on Amathuba.
(g) Create four global flag_t variables called startFlag, firstFlag, secondFlag, and
thirdFlag which will be used as flag conditions for the program. A binary flag is used to indicate
when a specific event or result has occurred in a program. In this case, we will use the flags to
indicate when a user has pressed a push button to start the program, or which LED bitpattern to
display. The initial value of each flag must be FALSE.
Copy this code segment and upload it to the post-practical quiz on Amathuba.
(h) Create a function called void firstDisplay(void) in your main.c file, which first displays
bitpattern1, then bitpattern2 and then bitpattern3 on the LEDS with a 1 second delay
in between each pattern. It must repeat once it has completed the sequence. Call the function in
your main function to test that it works as expected.
Copy this code segment and upload it to the post-practical quiz on Amathuba.
