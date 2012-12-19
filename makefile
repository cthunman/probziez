runme : lotterypuzzle.o readint.o
		cc -o runme lotterypuzzle.o readint.o
     
	readint.o : readint.c
		cc -c readint.c
	lotterypuzzle.o : lotterypuzzle.c
		cc -c lotterypuzzle.c

clean :
	@rm runme lotterypuzzle.o readint.o
	@echo "boomslam!"
