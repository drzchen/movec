build: basic-00180-large

basic-00180-large: basic-00180-large.c
	gcc -o basic-00180-large $^

run: basic-00180-large
	./basic-00180-large 1 2 3 10 > $<.output.txt 2> $<.error.txt

clean:
	@rm -f basic-00180-large *.output.txt *.error.txt
