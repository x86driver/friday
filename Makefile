TARGET = friday

all:$(TARGET)

friday:friday.c
	gcc -Wall -o $@ $< -g

clean:
	rm -rf $(TARGET)
