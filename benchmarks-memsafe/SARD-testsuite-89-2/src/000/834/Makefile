build: basic-00180-ok

basic-00180-ok: basic-00180-ok.c
	gcc -o basic-00180-ok $^

run: basic-00180-ok
	./basic-00180-ok 1 10 3 4 > $<.output.txt 2> $<.error.txt

clean:
	@rm -f basic-00180-ok *.output.txt *.error.txt
