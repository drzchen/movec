build: basic-00181-med

basic-00181-med: basic-00181-med.c
	$(INSTRU_CC) -o basic-00181-med $^

run: basic-00181-med
	export STRINGLEN_MED=1234567890; ./basic-00181-med > $<.output.txt 2> $<.error.txt

clean:
	@rm -f basic-00181-med *.output.txt *.error.txt
