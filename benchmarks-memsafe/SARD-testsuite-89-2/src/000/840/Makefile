build: basic-00182-med

basic-00182-med: basic-00182-med.c
	gcc -o basic-00182-med $^

run: basic-00182-med
	./basic-00182-med > $<.output.txt 2> $<.error.txt

clean:
	@rm -f basic-00182-med *.output.txt *.error.txt
