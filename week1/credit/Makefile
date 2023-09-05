ARCH_FLAGS = -arch arm64
CC= clang
$(CFLAGS) $(ARCH_FLAGS) = -ferror-limit=1 -gdwarf-4 -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wno-unused-but-set-variable -Wshadow
LDLIBS = -lcs50

EXE = foo

SRCS = foo.c bar.c
OBJS = $(SRCS:.c=.o)


$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(ARCH_FLAGS) -o $@ $(OBJS) $(LDLIBS)