
default: Makefile build build/carte.a 




SHELL:= /bin/sh
.SHELLFLAGS: -u -e  
#MAKEFLAGS:= s --warn-undefined-variables 
#MAKEFLAGS:= s 
.SUFFIXES: 
#.SILENT:
.NOTPARALLEL:
.EXPORT_ALL_VARIABLES:
.SECONDARY:
.PRECIOUS:
.ONESHELL:




clean:
	rm -Rf build 2>&1

clean-all: clean
	rm -Rf destroot rundir *~ .*~ src/*~ src/*.output COPYING_at_start_of_c_files src/carte.parser.tab.c src/carte.parser.code.c src/carte.parser.tab.h src/carte.parser.code.h src/carte.lexer.c 2>&1


Makefile: Makefile-gen.mkf
	@echo "--- \"Makefile-gen.mkf\" changed. Please type './configure' (or 'romake -f Makefile-gen.mkf') to update this Makefile ---"
	@false

build:
	mkdir -p build 2>&1 


install: destroot_do

destroot_do:
	rm -Rf destroot
	mkdir -p destroot
	mkdir -p destroot/lib
	cp -fp build/*.a destroot/lib/
	mkdir -p destroot/include
	cp -fp src/carte.h destroot/include/








run: build/carte.exe
	rm -f run
	ln -s build/carte.exe run


build/carte.exe: build/carte.a
	cc -o build/carte.exe build/carte.a -lm  2>&1


build/carte.a: build/carte.o build/carte.global.o build/carte.parser.tab.o build/carte.parser.code.o build/carte.lexer.o
	ar -r -c build/carte.a build/carte.o build/carte.global.o build/carte.parser.tab.o build/carte.parser.code.o build/carte.lexer.o 2>&1
	ranlib build/carte.a 2>&1









#src/carte.parser.c: src/carte.parser.y 
src/carte.parser.tab.h src/carte.parser.tab.c src/carte.parser.code.c: src/carte.parser.y 
#	bison --report=all,state,look-ahead,itemset --token-table --debug -d  src/carte.parser.y -o src/carte.parser.c 2>&1
#	yacc -d -t -p yycarte -r -v  -o src/carte.parser.c src/carte.parser.y 2>&1
	yacc -d -t -p yycarte -r -v  -b src/carte.parser src/carte.parser.y 2>&1
#	mv -f parser.c src/carte.parser.c 2>&1 || true 
#	mv -f carte.parser.c src/carte.parser.c 2>&1 || true
#	test -e src/carte.parser.c 2>&1






src/carte.lexer.c: src/carte.lexer.l 
	flex -Pyycarte -Cfa -p  -o src/carte.lexer.c src/carte.lexer.l 2>&1
	test -e src/carte.lexer.c 2>&1






build/carte.o: src/carte.c src/carte.global.h src/carte.h src/carte.lexer.h src/carte.parser.tab.h
	cc -std=c99 -D_THREAD_SAFE -D_REENTRANT -D __DEBUG__ -D DEBUG  -O0 -Wall -fmessage-length=0 -fdiagnostics-show-location=once -fdiagnostics-show-option -Wnewline-eof -Wfatal-errors -Werror-implicit-function-declaration -fno-exceptions -fstack-check -Werror -W  -Wparentheses -fverbose-asm -fno-omit-frame-pointer -ffreestanding -fno-builtin -fno-builtin-printf -fno-builtin-abs -fno-builtin-strcpy -fno-builtin-strcat -fno-builtin-strlen -fno-builtin-bzero -fno-builtin-memset -fno-builtin-memcpy -fno-builtin-assert -fno-builtin-tolower -fno-builtin-toupper -fno-builtin-log -fno-builtin-alloca -fno-common -fno-exceptions -fno-non-call-exceptions -fno-asynchronous-unwind-tables -fno-inline -fno-inline-functions -fno-inline-functions  -gfull  -feliminate-unused-debug-types  -Wimplicit -Wreturn-type -Wcomment -Wpointer-arith -Wchar-subscripts -Wimplicit-int -Werror-implicit-function-declaration -Wmain -Wmissing-braces -Wmultichar -Wsequence-point -Wreturn-type  -Wstrict-prototypes -Wpacked -Wcast-qual -Wcast-align -Wno-system-headers -Winline -Wformat-nonliteral -Wwrite-strings -Wmissing-field-initializers -Wsign-compare  -Wformat-zero-length -Wswitch -Wswitch-enum -Wswitch-default -Wnested-externs -Wunknown-pragmas -Wno-undef -Wno-redundant-decls -Wno-unused -Wno-unused-parameter -Wno-unused-function -Wno-switch-default -Wno-format-nonliteral -Wno-unsequenced -I /usr/X11R6/include  -I ./libs/SDL-1.2.15/destroot/include -I ./src/SDL_image -I ./src/SDL_mixer   -c src/carte.c -o build/carte.o  2>&1

build/carte.global.o: src/carte.global.c src/carte.global.h src/carte.h src/carte.lexer.h src/carte.parser.tab.h
	cc -std=c99 -D_THREAD_SAFE -D_REENTRANT -D __DEBUG__ -D DEBUG  -O0 -Wall -fmessage-length=0 -fdiagnostics-show-location=once -fdiagnostics-show-option -Wnewline-eof -Wfatal-errors -Werror-implicit-function-declaration -fno-exceptions -fstack-check -Werror -W  -Wparentheses -fverbose-asm -fno-omit-frame-pointer -ffreestanding -fno-builtin -fno-builtin-printf -fno-builtin-abs -fno-builtin-strcpy -fno-builtin-strcat -fno-builtin-strlen -fno-builtin-bzero -fno-builtin-memset -fno-builtin-memcpy -fno-builtin-assert -fno-builtin-tolower -fno-builtin-toupper -fno-builtin-log -fno-builtin-alloca -fno-common -fno-exceptions -fno-non-call-exceptions -fno-asynchronous-unwind-tables -fno-inline -fno-inline-functions -fno-inline-functions  -gfull  -feliminate-unused-debug-types  -Wimplicit -Wreturn-type -Wcomment -Wpointer-arith -Wchar-subscripts -Wimplicit-int -Werror-implicit-function-declaration -Wmain -Wmissing-braces -Wmultichar -Wsequence-point -Wreturn-type  -Wstrict-prototypes -Wpacked -Wcast-qual -Wcast-align -Wno-system-headers -Winline -Wformat-nonliteral -Wwrite-strings -Wmissing-field-initializers -Wsign-compare  -Wformat-zero-length -Wswitch -Wswitch-enum -Wswitch-default -Wnested-externs -Wunknown-pragmas -Wno-undef -Wno-redundant-decls -Wno-unused -Wno-unused-parameter -Wno-unused-function -Wno-switch-default -Wno-format-nonliteral -Wno-unsequenced -I /usr/X11R6/include  -I ./libs/SDL-1.2.15/destroot/include -I ./src/SDL_image -I ./src/SDL_mixer   -c src/carte.global.c -o build/carte.global.o  2>&1

build/carte.lexer.o: src/carte.lexer.c src/carte.global.h src/carte.h src/carte.lexer.h src/carte.parser.tab.h
	cc -std=c99 -D_THREAD_SAFE -D_REENTRANT -D __DEBUG__ -D DEBUG  -O0 -Wall -fmessage-length=0 -fdiagnostics-show-location=once -fdiagnostics-show-option -Wnewline-eof -Wfatal-errors -Werror-implicit-function-declaration -fno-exceptions -fstack-check -Werror -W  -Wparentheses -fverbose-asm -fno-omit-frame-pointer -ffreestanding -fno-builtin -fno-builtin-printf -fno-builtin-abs -fno-builtin-strcpy -fno-builtin-strcat -fno-builtin-strlen -fno-builtin-bzero -fno-builtin-memset -fno-builtin-memcpy -fno-builtin-assert -fno-builtin-tolower -fno-builtin-toupper -fno-builtin-log -fno-builtin-alloca -fno-common -fno-exceptions -fno-non-call-exceptions -fno-asynchronous-unwind-tables -fno-inline -fno-inline-functions -fno-inline-functions  -gfull  -feliminate-unused-debug-types  -Wimplicit -Wreturn-type -Wcomment -Wpointer-arith -Wchar-subscripts -Wimplicit-int -Werror-implicit-function-declaration -Wmain -Wmissing-braces -Wmultichar -Wsequence-point -Wreturn-type  -Wstrict-prototypes -Wpacked -Wcast-qual -Wcast-align -Wno-system-headers -Winline -Wformat-nonliteral -Wwrite-strings -Wmissing-field-initializers -Wsign-compare  -Wformat-zero-length -Wswitch -Wswitch-enum -Wswitch-default -Wnested-externs -Wunknown-pragmas -Wno-undef -Wno-redundant-decls -Wno-unused -Wno-unused-parameter -Wno-unused-function -Wno-switch-default -Wno-format-nonliteral -Wno-unsequenced -I /usr/X11R6/include  -I ./libs/SDL-1.2.15/destroot/include -I ./src/SDL_image -I ./src/SDL_mixer   -c src/carte.lexer.c -o build/carte.lexer.o  2>&1

build/carte.parser.code.o: src/carte.parser.code.c src/carte.global.h src/carte.h src/carte.lexer.h src/carte.parser.tab.h
	cc -std=c99 -D_THREAD_SAFE -D_REENTRANT -D __DEBUG__ -D DEBUG  -O0 -Wall -fmessage-length=0 -fdiagnostics-show-location=once -fdiagnostics-show-option -Wnewline-eof -Wfatal-errors -Werror-implicit-function-declaration -fno-exceptions -fstack-check -Werror -W  -Wparentheses -fverbose-asm -fno-omit-frame-pointer -ffreestanding -fno-builtin -fno-builtin-printf -fno-builtin-abs -fno-builtin-strcpy -fno-builtin-strcat -fno-builtin-strlen -fno-builtin-bzero -fno-builtin-memset -fno-builtin-memcpy -fno-builtin-assert -fno-builtin-tolower -fno-builtin-toupper -fno-builtin-log -fno-builtin-alloca -fno-common -fno-exceptions -fno-non-call-exceptions -fno-asynchronous-unwind-tables -fno-inline -fno-inline-functions -fno-inline-functions  -gfull  -feliminate-unused-debug-types  -Wimplicit -Wreturn-type -Wcomment -Wpointer-arith -Wchar-subscripts -Wimplicit-int -Werror-implicit-function-declaration -Wmain -Wmissing-braces -Wmultichar -Wsequence-point -Wreturn-type  -Wstrict-prototypes -Wpacked -Wcast-qual -Wcast-align -Wno-system-headers -Winline -Wformat-nonliteral -Wwrite-strings -Wmissing-field-initializers -Wsign-compare  -Wformat-zero-length -Wswitch -Wswitch-enum -Wswitch-default -Wnested-externs -Wunknown-pragmas -Wno-undef -Wno-redundant-decls -Wno-unused -Wno-unused-parameter -Wno-unused-function -Wno-switch-default -Wno-format-nonliteral -Wno-unsequenced -I /usr/X11R6/include  -I ./libs/SDL-1.2.15/destroot/include -I ./src/SDL_image -I ./src/SDL_mixer   -c src/carte.parser.code.c -o build/carte.parser.code.o  2>&1

build/carte.parser.tab.o: src/carte.parser.tab.c src/carte.global.h src/carte.h src/carte.lexer.h src/carte.parser.tab.h
	cc -std=c99 -D_THREAD_SAFE -D_REENTRANT -D __DEBUG__ -D DEBUG  -O0 -Wall -fmessage-length=0 -fdiagnostics-show-location=once -fdiagnostics-show-option -Wnewline-eof -Wfatal-errors -Werror-implicit-function-declaration -fno-exceptions -fstack-check -Werror -W  -Wparentheses -fverbose-asm -fno-omit-frame-pointer -ffreestanding -fno-builtin -fno-builtin-printf -fno-builtin-abs -fno-builtin-strcpy -fno-builtin-strcat -fno-builtin-strlen -fno-builtin-bzero -fno-builtin-memset -fno-builtin-memcpy -fno-builtin-assert -fno-builtin-tolower -fno-builtin-toupper -fno-builtin-log -fno-builtin-alloca -fno-common -fno-exceptions -fno-non-call-exceptions -fno-asynchronous-unwind-tables -fno-inline -fno-inline-functions -fno-inline-functions  -gfull  -feliminate-unused-debug-types  -Wimplicit -Wreturn-type -Wcomment -Wpointer-arith -Wchar-subscripts -Wimplicit-int -Werror-implicit-function-declaration -Wmain -Wmissing-braces -Wmultichar -Wsequence-point -Wreturn-type  -Wstrict-prototypes -Wpacked -Wcast-qual -Wcast-align -Wno-system-headers -Winline -Wformat-nonliteral -Wwrite-strings -Wmissing-field-initializers -Wsign-compare  -Wformat-zero-length -Wswitch -Wswitch-enum -Wswitch-default -Wnested-externs -Wunknown-pragmas -Wno-undef -Wno-redundant-decls -Wno-unused -Wno-unused-parameter -Wno-unused-function -Wno-switch-default -Wno-format-nonliteral -Wno-unsequenced -I /usr/X11R6/include  -I ./libs/SDL-1.2.15/destroot/include -I ./src/SDL_image -I ./src/SDL_mixer   -c src/carte.parser.tab.c -o build/carte.parser.tab.o  2>&1















