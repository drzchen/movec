build: basic-00181-large

basic-00181-large: basic-00181-large.c
	$(INSTRU_CC) -o basic-00181-large $^

run: basic-00181-large
	export STRINGLEN_LARGE=1234567890; ./basic-00181-large > $<.output.txt 2> $<.error.txt

clean:
	@rm -f basic-00181-large *.output.txt *.error.txt
