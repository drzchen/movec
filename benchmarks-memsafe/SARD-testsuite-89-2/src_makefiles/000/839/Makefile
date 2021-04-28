build: basic-00182-large

basic-00182-large: basic-00182-large.c
	$(INSTRU_CC) -o basic-00182-large $^

run: basic-00182-large
	$(INSTRU_BIN) ./basic-00182-large > $<.output.txt 2> $<.error.txt

clean:
	@rm -f basic-00182-large *.output.txt *.error.txt
