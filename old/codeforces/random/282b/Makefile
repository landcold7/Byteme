SHELL = /bin/bash -o pipefail
ALGOROOT = ${ALGO}
CXX = g++-9

CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2
CXXFLAGS += -Wfloat-equal -Wcast-qual -Wcast-align -fvisibility=hidden
# CXXFLAGS += -Wconversion

MKFLAG_RELEASE ?= 0
MKFLAG_SHOWTIME ?= 1
MKFLAG_NODIFF ?= 0
ifeq ($(MKFLAG_RELEASE), 0)
	DEBUGFLAGS += -fsanitize=address -fsanitize=undefined
	# DEBUGFLAGS += -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
	# Since this flag will case a AddressSantizer error on my debug
	# function `trace`, so here i just simply comment out this one.
	# -fstack-protector
	MKFLAG_SHOWTIME = 0
endif

# For local debug purpose
CXXFLAGS += -I$(ALGOROOT)
ifeq ($(MKFLAG_NODIFF), 0)
	DEBUGFLAGS += -DLOCAL
endif

TARGET := $(notdir $(CURDIR))

all: test

clean:
	@echo $(CURDIR)
	@-rm -rf *.inp

# Hacking to make it rebuilding when change debug flags.
% : %.cc Makefile
	@echo "cxx $<"
	@$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $< $(LDFLAGS)  -o $@


run: $(TARGET)
	./$(TARGET)

# Making samples.
samples: clean
	@-mv -f /tmp/algo-samples ./282b.in >>/dev/null 2>&1 || true
	@-test -f /tmp/algo-wrong && echo -e "\n" >> ./282b.in || true
	@-cat /tmp/algo-wrong 2>/dev/null | tee -a ./282b.in >/dev/null 2>&1 || true
	@-rm -f /tmp/algo-wrong
	byte-split 282b.in

test: samples $(TARGET)
	@echo byte-run $(TARGET)
	@unbuffer byte-run $(TARGET) $(MKFLAG_SHOWTIME) $(MKFLAG_NODIFF)

# Compare my results with other person's correct real results.
comp: samples
	@echo "cxx 282b.mp"
	@$(CXX) -x c++ $(CXXFLAGS) $(DEBUGFLAGS) 282b.mp $(LDFLAGS) -o cmp
	@echo byte-run cmp
	@unbuffer byte-run cmp $(MKFLAG_SHOWTIME) $(MKFLAG_NODIFF)

memo:
	ps aux | grep "[.]/$(TARGET)$$" | awk '{$$6=int($$6/1024)"M";}{print;}'

pygen: gen.py
	python3 gen.py | tee 282b.in

# Ugly hacking to speed up the compilation time of jngen library...
cppgen:
	@echo "cxx 282b.ge"
	@g++ -x c++ 282b.ge --std=c++11 -I$(ALGOROOT)/third_party/jngen/includes -o gen
	@rm -rf *.rel *.pdf *.gv
	./gen | tee 282b.in


.PHONY: all clean run test comp

print-%:
	@echo $* = $($*)
