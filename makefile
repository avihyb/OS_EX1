CC = g++
CFLAGS = -g -Wall

TARGET = crash_program Poisson q3 
SRCS = q1.cpp Poisson.cpp q3.cpp 
LIB_SRCS = Poissonlib.cpp

OBJS = $(SRCS:.cpp=.o)
LIB_OBJS = $(LIB_SRCS:.cpp=.o)

all: $(TARGET)


$(TARGET): $(OBJS) libpoisson.so
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L. -lpoisson

libpoisson.so: $(LIB_OBJS)
	$(CC) -shared -o $@ $(LIB_OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@ -fPIC

clean:
	rm -f $(OBJS) $(LIB_OBJS) $(TARGET) libpoisson.so *.gcda *.gcno *.gcov codecoverage q5 add2PB
