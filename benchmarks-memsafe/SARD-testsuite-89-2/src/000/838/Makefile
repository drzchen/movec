build: basic-00181-ok

basic-00181-ok: basic-00181-ok.c
	gcc -o basic-00181-ok $^

run: basic-00181-ok
	export STRINGLEN_OK=123; ./basic-00181-ok > $<.output.txt 2> $<.error.txt

clean:
	@rm -f basic-00181-ok *.output.txt *.error.txt
