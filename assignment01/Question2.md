Question 2:
Why use two’s complement to represent negative numbers?

Answer:
I think the main reason is that the math works out when doing addition and subtraction. I believe multiplication and division also work but negative numbers are usually avoided if possible in most applications as it limits your max number and creates complications. 

112 + (-30) = 82                                              -34 - (-80) = 46
  0111 0000  (112)                                            1101 1110  (-34)
+ 1110 0010  (-30)                                          - 1011 0000  (-80)

 10101 0010 drop the leading 1.                               0010 1110  (46) 
  0101 0010 = 82
