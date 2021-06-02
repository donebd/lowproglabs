# Параметры для компилятора
# Стандарт языка СИ 11 года, агрегаторы предупреждений и указание папки, где следует искать хедеры
export CFLAGS= -std=c11 -Wall -pedantic -Wextra -I ./include

# Выбор компилятора
export CC=gcc

# Для удаления файлов
export R=del -f

# Build - сборка библиотеки + программы.

build: 
	make buildlib
	make buildapp
	make buildtest
	@echo ------------------------------
	@echo To start tests write make test
	@echo To start demo write make app

# Buildlib - собрать статически-линкуемую библиотеку в каталоге mylib
buildlib:
	$(MAKE) -C mylib

# Buildpp - скомпилировать программу с использованием нашей библиотеки

buildapp:
	$(MAKE) -C myapp
	
buildtest:
	$(MAKE) -C tests
	
# Test - запустить модульные тесты и вывести результат на консоль

test:
	./tests/tests.exe

app:
	./myapp/myapp.exe

.PHONY: build buildlib buildapp buildtests test app clean

# Clean - удаление всех файлов сгенерированных в процессе работы мейк-файлов и компилятора
# Вызывается во всех папках, где есть мейк-файлы

clean:
	$(MAKE) -C mylib clean
	$(MAKE) -C myapp clean
	$(MAKE) -C tests clean