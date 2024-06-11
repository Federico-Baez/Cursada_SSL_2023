UNAME := $(shell uname)
ifeq ($(UNAME),Linux)
    FILE_EXT := out
else
    FILE_EXT := exe
    LIBS += -L lib
    CFLAGS += -m32
endif

SRCDIR := src
IDIR := src
ODIR := obj

LIBS += -lfl -ly -lm

CC := gcc
CFLAGS += -I$(IDIR)
BFLAGS += -v -d
FFLAGS +=

SRC := $(wildcard $(SRCDIR)/*.l)
DEPS := $(wildcard $(IDIR)/*.h) $(wildcard $(SRCDIR)/*.c)
OBJ := $(DEPS:$(SRCDIR)/%.c=$(ODIR)/%.o)

TARGETS := $(patsubst $(SRCDIR)/%.l,%.$(FILE_EXT),$(SRC))

all: $(TARGETS)

%.$(FILE_EXT): $(SRCDIR)/%.l $(OBJ)
	@echo "=================[ Build | $@ ]================="
	@echo "<<< Generando lex.yy.c >>>"
	@mkdir -p $(ODIR) && cd $(ODIR) && flex $(FFLAGS) ../$< && cd ..
	@echo "<<< lex.yy.c creado. >>>"
	@echo ""
	@echo "<<< Compilando >>>"
	@$(CC) $(CFLAGS) -I$(IDIR) $(ODIR)/lex.yy.c $(OBJ) -o $@ $(LIBS)
	@echo "<<< $@ creado. >>>"
	@echo ""

$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	@echo "<<< Compilando objeto: $@ >>>"
	@mkdir -p $(ODIR) && $(CC) $(CFLAGS) -c -o $@ $<
	@echo "<<< Objeto $@ compilado. >>>"
	@echo ""

clean:
	rm -f $(ODIR)/*
	rm -f *.$(FILE_EXT)