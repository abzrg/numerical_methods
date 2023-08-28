$(CC) := gcc
CFLAGS := -Wall -Wextra -std=c11 -pedantic -g
LDFLAGS := -lm

SRCDIR := src
BUILDDIR := build

SRC := $(wildcard $(SRCDIR)/*.c)
TARGETS = $(patsubst $(SRCDIR)/%.c,%,$(SRC))


.PHONY: all
all: $(BUILDDIR)/$(TARGETS)


$(BUILDDIR)/%: $(SRCDIR)/%.c
	$(CC) $(CLFLAGS) $<  -o $(BUILDDIR)/$* $(LDFLAGS)


.PHONY: clean
clean:
	$(RM) -rf a.out $(BUILDDIR)/*
