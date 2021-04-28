build: basic-00181-min

basic-00181-min: basic-00181-min.c
	$(INSTRU_CC) -o basic-00181-min $^

run: basic-00181-min
	export STRINGLEN_MIN=1234567890; ./basic-00181-min > $<.output.txt 2> $<.error.txt

clean:
	@rm -f basic-00181-min *.output.txt *.error.txt
