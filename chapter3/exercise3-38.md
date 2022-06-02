# Exercise 3.38: In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?

Adding two pointers evaluates to gibberish addresses, therefore, even though they might point to a valid memory address, there is no guarantee that the executing program has access to it. Therefore, such addresses are meaningless.