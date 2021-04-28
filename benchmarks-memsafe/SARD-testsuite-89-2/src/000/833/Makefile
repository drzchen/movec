build: basic-00180-min

basic-00180-min: basic-00180-min.c
	gcc -o basic-00180-min $^

run: basic-00180-min
	./basic-00180-min 1 10 3 4 > $<.output.txt 2> $<.error.txt

clean:
	@rm -f basic-00180-min *.output.txt *.error.txt
