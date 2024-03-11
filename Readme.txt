Emmanuel Colas 
lex.c

This program will go through the input text and will print the lexeme and the token corresponding to it. To make this run on eustis, you you gcc lex.c to make it compile then you use ./a.out to run it. Your input file must be in the folder and named "test.txt" to run the program and it will output a text file named "output.txt" with your results.
In Eustis, the new line character changes everytime you run the prograam for whatever reason so I wasnt able to target it for removal. Therefore, it reads the new line character as a token and messes with the output a bit.