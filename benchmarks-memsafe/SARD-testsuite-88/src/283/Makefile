
all:	realpath-bad setup

clean:
	@rm -rf *-ok *-bad /tmp/foo *.output.txt *.error.txt

realpath-bad: call_fb_realpath.c realpath-bad.c
	gcc -o realpath-bad call_fb_realpath.c realpath-bad.c

setup:
	mkdir -p /tmp/foo/bar/foo/bar/foo/bar/foo/bar ; \
	touch /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefghi ; \
	ln -f -s /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefghi /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefgh

run: realpath-bad setup
	./realpath-bad /tmp/foo/bar/foo/bar/foo/bar/foo/bar/abcdefgh > $<.output.txt 2> $<.error.txt
