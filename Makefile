# Имя исполняемого файла
TARGET = MySystem.exe

# Компилятор и флаги
CXX = g++
CXXFLAGS = -O3 -s -DNDEBUG -Wl,--gc-sections -ffunction-sections -fdata-sections
LDFLAGS = -Wl,--gc-sections -ffunction-sections -fdata-sections

# Исходные файлы и объектные файлы
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Правила
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка объектных файлов и исполняемого файла
clean:
	del /Q $(OBJS) $(TARGET)

# Запуск исполняемого файла
run: $(TARGET)
	$(TARGET)

# Компиляция и запуск
build_and_run: all run clean

# Удаление исполняемого файла после запуска
clean_after_run: run 
	del /Q $(TARGET)

.PHONY: all clean run build_and_run clean_after_run