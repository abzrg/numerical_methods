$(CC) := gcc
CFLAGS := -Wall -Wextra -std=c11 -pedantic -g
LDFLAGS := -lm

BUILDDIR := build

SRC := $(wildcard *.c)
TARGETS = $(patsubst %.c,%,$(SRC))

.PHONY: all
all: $(BUILDDIR)/$(TARGETS)


$(BUILDDIR)/%: %.c
	$(CC) $(CLFLAGS) $<  -o $(BUILDDIR)/$* $(LDFLAGS)


.PHONY: clean
clean:
	$(RM) -rf a.out $(BUILDDIR)/*

