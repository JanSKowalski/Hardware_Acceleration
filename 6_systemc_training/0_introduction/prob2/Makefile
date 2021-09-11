src = $(wildcard *.cpp)
obj = $(src: .cpp=.o)

LDFLAGS = -lsystemc -lm

CFLAGS = -I. -I$(SYSTEMC_HOME)/include -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64

prob2: $(obj)
	$(CXX) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	./prob2
	gtkwave com_device.vcd
