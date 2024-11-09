file= fibonacci.asm


Assembler:
	@gcc -o asm_converter main.c asm2bin.c

Run:
	@./asm_converter $(file)

Run_Simulator:
	./program


Simulator:
	@gcc -o program main1.c loader.c instruction.c

Output:
	cat output.bin

help:
	@echo "Makefile"
	@echo "make Assmbler          -complie the main.c and asm2bin.c"
	@echo "make Simlator          -complie the main1.c and loader instruction"
	@echo "make Run               -exe the file fibonacci.asm and make asm_converter"
	@echo "make Run_Simulator     -exe the file "
	@echo "make Output            -Print the output in termainl"

