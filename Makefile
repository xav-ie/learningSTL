CC=g++
CFLAGS=-Wall -g -std=c++17
BINS=stdarray stdvector vectorPractices stdset containers matrices

all: $(BINS)
clean:
	rm -rf $(BINS) *.dSYM

%: %.cpp
	$(CC) $(CFLAGS) $^ -o $@

