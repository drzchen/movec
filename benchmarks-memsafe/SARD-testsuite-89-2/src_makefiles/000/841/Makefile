build: basic-00182-min

basic-00182-min: basic-00182-min.c
	$(INSTRU_CC) -o basic-00182-min $^

run: basic-00182-min
	$(INSTRU_BIN) ./basic-00182-min > $<.output.txt 2> $<.error.txt

clean:
	@rm -f basic-00182-min *.output.txt *.error.txt
