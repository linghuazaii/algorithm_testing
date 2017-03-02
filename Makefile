CC=g++

SRC=main.o generator.o utility.o
TARGET=algo

.PHONY:
all:$(TARGET)

$(TARGET):$(SRC)
	$(CC) -o $@ $^

%.o:%.cpp
	$(CC) -c -o $@ $^

%.o:%.c
	$(CC) -c -o $@ $^

.PHONY:
clean:
	rm -f $(SRC) $(TARGET)
