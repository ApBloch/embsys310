1:
  a) 0x80000000
  b) Stored in R1 0x80000000
  c) APSR.N is set because our last action has made the value negative because the greatest bit has changed from 0 to 1
     APSR.V changed from 0 to 1 because the last action resulted in overflow on our signed int value.     

2:
  a) The value changes from 0xFFFFFFFF to 0x0
  b) APSR.Z is set because the last operation changed the value to 0 which sets this flag
     APSR.C I think that value is to indicate that a 1 was shifted out to the left and to indicate we should carry a 1

3:
  a) The value changes form 0x7FFFFFFF to 0x80000000
  b) APSR.N and APSR.V are set I think because the ASPR doesnt really know if the values are signed or not and just watch the most significant bit and 
        reacte how they would regardless.

4:
  a) The value changes from 0xFFFFFFFF to 0x0
  b) APSR.Z and APSR.C are both set for the same reason in question 2 the result is 0 and also there is a carryover 1.

5: 
  a) The variable counter's scope is global now
  b) The variable is not in the local window
  c) We can find the variable in the watch window
  d) The address is 0x20000000

6:
  a) The value is 4
  b) The variable p_int is a pointer to address 0x20000000 which is where we are storing the counter variable. When we increment the pointer it will 
      increment the value of counter.

7:
  a) 0x20000000
  b) From my understanding of the data sheet it is store in the beginning of SRAM which would be a type of RAM.
  c) The value is 4

