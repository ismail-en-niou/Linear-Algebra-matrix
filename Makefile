CXX      = c++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -Iinclude

ex00: ex00/main.cpp includes/Vector.hpp  includes/Matrix.hpp
	$(CXX) $(CXXFLAGS) ex00/main.cpp -o ex00/ex00
	
ex01: ex01/main.cpp includes/Vector.hpp  includes/Matrix.hpp
	$(CXX) $(CXXFLAGS) ex01/main.cpp -o ex01/ex01

ex02: ex02/main.cpp includes/Vector.hpp includes/Matrix.hpp includes/Lerp.hpp
	$(CXX) $(CXXFLAGS) ex02/main.cpp -o ex02/ex02

clean:
	rm -f ex00/ex00 ex01/ex01 ex02/ex02

fclean: clean

re: fclean all

.PHONY: clean fclean re ex00