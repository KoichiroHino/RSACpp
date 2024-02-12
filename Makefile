PROGRAM = system # 生成したい実行ファイル名
CXX = g++
CXXFLAGS = -MMD -MP -Wall
SRCDIR = ./src
OBJDIR = ./obj
INCDIR = -I./inc
# 現在の日付と時刻を取得する（yyyymmddss形式）
DATE := $(shell date +"%Y%m%d%H%M%S")
# 出力ディレクトリの名前
OUTPUT_DIR := result_$(DATE)

SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))
DPNFILES = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.d,$(SRCFILES))

.PHONY: all
all: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ -o $(PROGRAM)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $(INCDIR) $< -o $@

-include $(DPNFILES)

.PHONY: clean
clean:
	rm -f $(DPNFILES) $(OBJFILES) $(PROGRAM)

.PHONY: rebuild
rebuild: clean all

.PHONY: init
init: 
	git init
	git commit --allow-empty -m "Initial empty commit"
	mkdir -p inc
	mkdir -p obj
	mkdir -p src
	touch inc/.gitkeep
	touch src/.gitkeep
	git add .gitignore
	git add Makefile
	git add inc/.gitkeep
	git add src/.gitkeep
	git add README.md
	git commit -m "commit for .gitignore, Makefile, README and some directories"

.PHONY: exe
exe:
	mkdir -p $(OUTPUT_DIR)
	./system
	cp *.txt ./$(OUTPUT_DIR)
