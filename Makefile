CC=g++ -g

SRC=main.o generator.o utility.o
TARGET=algo

RESERVOIR=reservoir
SRC_RESERVOIR=generator.o utility.o reservoir.o

.PHONY:
all:$(TARGET) $(RESERVOIR)

$(TARGET):$(SRC)
	$(CC) -o $@ $^

$(RESERVOIR):$(SRC_RESERVOIR)
	$(CC) -o $@ $^

%.o:%.cpp
	$(CC) -c -o $@ $^

%.o:%.c
	$(CC) -c -o $@ $^

.PHONY:
clean:
	rm -f $(SRC) $(TARGET) $(RESERVOIR) $(SRC_RESERVOIR)
