CXX      = c++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -Iincludes
HEADERS  = includes/Vector.hpp includes/Matrix.hpp includes/Lerp.hpp

all: ex00 ex01 ex02 ex03

ex00: ex00/ex00
ex01: ex01/ex01
ex02: ex02/ex02
ex03: ex03/ex03
ex04: ex04/ex04

ex00/ex00: ex00/main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) ex00/main.cpp -o ex00/ex00

ex01/ex01: ex01/main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) ex01/main.cpp -o ex01/ex01

ex02/ex02: ex02/main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) ex02/main.cpp -o ex02/ex02

ex03/ex03: ex03/main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) ex03/main.cpp -o ex03/ex03

ex04/ex04: ex04/main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) ex04/main.cpp -o ex04/ex04

clean:
	rm -f ex00/ex00 ex01/ex01 ex02/ex02 ex03/ex03

fclean: clean

re: fclean all

.PHONY: all ex00 ex01 ex02 ex03 ex04 clean fclean re