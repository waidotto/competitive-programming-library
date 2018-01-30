CFLAGS = -Wall -Werror -D_GLIBCXX_DEBUG
CC = g++ $(CFLAGS)
TARGET_DIR = target
TEST_DIR = test
TARGETS = $(addprefix $(TARGET_DIR)/, $(basename $(shell ls $(TEST_DIR)/)))

all: $(TARGET_DIR) $(TARGETS)

$(TARGET_DIR):
	mkdir -p ./$(TARGET_DIR)/

$(TARGET_DIR)/%: $(TEST_DIR)/%.cpp $(TARGET_DIR)
	$(CC) -o $@ $<
	./$@

clean:
	rm -rf ./$(TARGET_DIR)/

