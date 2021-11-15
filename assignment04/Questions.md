
Problem 1:
	a) Using Bit Banding: MOVS, LDR.N, STR
	b) Without Bit Banding: LDR.N, LDR, ORRS.W, STR
	
Problem 2:
	a) It moves the called values in func1 into the R0-3 and in memory.
	b) It pushes F7 into LR.
	c) It moves the 5th value into R0 then moves that value into memory. Then rewrites the R0 later with the 1st value
	d) At the end of the func2 it pops R0 to PC, so the function in a function pushes values and then pops values after. I am not sure why it does this but it does not do that when calling the functions in sequence. 
	