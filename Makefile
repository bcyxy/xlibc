include env.mk

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(BUILD_DIR)/libxlibc.a

$(BUILD_DIR)/libxlibc.a: $(OBJ)
	mkdir -p $(BUILD_DIR)
	$(AR) -o $@ -rc $^

# TODO 不能发现头文件更新
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(SRC_DIR)/*.o
