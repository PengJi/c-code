# 输出标目名称
BINNAME = test

# 指定编译时依赖的头文件目录，然后放进编译选项
INC_DIR := ./src/inc

# 指出源文件存放路径
SRC_DIR := ./
SRC_DIR +=

# 设置 .o 文件输出路径
OBJDIR = ./

# 配置工具链 CC
CC = g++

# 配置编译选项，或许还需要添加 -Werror
CC_OPTS := -std=c++11 -Wall
CC_OPTS += -I$(INC_DIR)

# 配置链接选项
LD_OPTS :=

# 找出所有需要编译的 cpp 类型文件
# 第一种方法：使用 find 查找
# 注意 find 默认是会循环找子目录的，由于我们子目录的路径也需要写进 VPATH ，
# 所以这里把 find 的查找深度设置为了 1
# 指定依赖文件搜索路径，即我们的源文件路径
# VPATH = $(SRC_DIR)
# SRC = $(shell find $(SRC_DIR) -maxdepth 1 -name '*.cpp')
# 第二种方法：直接指定
SRC := Tree.cpp BinaryTree.cpp
#SRC += 32_01-PrintTreeFromTopToBottom.cpp
SRC += 32_02-PrintTreesInLines.cpp

# 生成需要输出的 .o 文件名
OBJ_0 = $(notdir $(patsubst %.cpp, %.o, $(SRC)))

# 加上 .o 文件存放路径前缀
OBJ = $(foreach file, $(OBJ_0), $(OBJDIR)/$(file))

.PHONY: all setup bin clean

all: setup bin

setup:
	@echo $(SRC)
	@echo $(OBJ_0)
	@echo $(OBJ)

bin: $(OBJ)
	$(CC) $(OBJ) $(LD_OPTS) -o $(BINNAME)

$(OBJ): %.o : %.cpp
	$(CC) $(CC_OPTS) -o $@ -c $<

clean:
	rm -rf $(OBJ_0)
	rm -rf $(BINNAME)
