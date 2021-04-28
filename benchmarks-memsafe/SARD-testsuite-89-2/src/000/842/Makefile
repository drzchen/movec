build: basic-00182-ok

basic-00182-ok: basic-00182-ok.c
	gcc -o basic-00182-ok $^

run: basic-00182-ok
	./basic-00182-ok > $<.output.txt 2> $<.error.txt

clean:
	@rm -f basic-00182-ok *.output.txt *.error.txt
