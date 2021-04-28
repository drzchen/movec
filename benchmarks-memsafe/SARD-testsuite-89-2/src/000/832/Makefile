build: basic-00180-med

basic-00180-med: basic-00180-med.c
	gcc -o basic-00180-med $^

run: basic-00180-med
	./basic-00180-med 1 2 10 4 > $<.output.txt 2> $<.error.txt

clean:
	@rm -f basic-00180-med *.output.txt *.error.txt
