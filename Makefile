# Nombre del ejecutable
TARGET = simulate

# Compilador a utilizar
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++11 -Wall

# Archivos fuente
SRCS = main.cpp Picture.cpp Network/Gen.cpp Network/Network.cpp Network/Eval1.cpp #Network/Eval2.cpp Network/Validation.cpp

# Archivos objetos generados a partir de los archivos fuente
OBJS = $(SRCS:.cpp=.o)

# Regla de compilación
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla de construcción de los archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) $(OBJS)

# Regla para reconstruir el proyecto desde cero
rebuild: clean $(TARGET)
