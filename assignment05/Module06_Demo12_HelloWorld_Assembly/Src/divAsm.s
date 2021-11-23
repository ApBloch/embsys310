    EXTERN PrintString  // PrintString is defined outside this file.
    
    PUBLIC divAsm       // Exports symbols to other modules



    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               
                        
divAsm
    PUSH {R0,LR}        // save the input argument and return address
    BL PrintString      // call the print string function
    POP {R0,LR}         // Restore R0 and LR
    MOV R1,#2           // move 2 into register 1
    SDIV R0, R0, R1     //divide R0 by R1 and save into R0
    BX LR               //return back to function call address
    END