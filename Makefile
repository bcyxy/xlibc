include env.mk

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
TEST_SRC = $(wildcard $(TEST_SRC_DIR)/*.c)
TEST_OBJ = $(patsubst %.c, %.o, $(TEST_SRC))

all: $(BUILD_DIR)/libxlibc.a $(BUILD_DIR)/test

$(BUILD_DIR)/test: $(BUILD_DIR)/libxlibc.a $(TEST_OBJ)
	$(GCC) -o $@ $(TEST_OBJ) -L$(BUILD_DIR) -lxlibc

$(TEST_SRC_DIR)/%.o: $(TEST_SRC_DIR)/%.c
	$(GCC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/libxlibc.a: $(OBJ)
	mkdir -p $(BUILD_DIR)
	$(AR) -o $@ -rc $^

# TODO 不能发现头文件更新
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(SRC_DIR)/*.o
	rm -f $(TEST_SRC_DIR)/*.o
