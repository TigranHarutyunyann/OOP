#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

class Canvas;
class Shape {
public:
    virtual void Draw(Canvas& g) = 0;
    virtual ~Shape() {}
};

class Canvas {
private:
    int m_x, m_y;
    char** matrix;
    std::vector<Shape*> listShape;
public:

    Canvas() : m_x(40), m_y(40) {
        matrix = new char*[m_y];
        for (int i = 0; i < m_y; i++) {
            matrix[i] = new char[m_x];
        }
        for (int i = 0; i < m_y; i++) {
            for (int j = 0; j < m_x; j++) {
                matrix[i][j] = '*';
            }
        }
    }

    void addShape(Shape* sh) {
        listShape.push_back(sh);
    }

    void setChar(int x, int y, char ch) {
        if (y >= 0 && y < m_y && x >= 0 && x < m_x) {
            matrix[y][x] = ch;   
 	   }
	}

    int width() const { return m_x; }
    int height() const { return m_y; }

    void Show() {
        for (int i = 0; i < m_y; i++) {
            for (int j = 0; j < m_x; j++) {
                matrix[i][j] = '*';
            }
        }

        for (auto sh : listShape) {
            sh->Draw(*this);
        }

        for (int i = 0; i < m_y; i++) {
            for (int j = 0; j < m_x; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    virtual ~Canvas() {
        for (auto i : listShape) {
            delete i;
        }
        for (int i = 0; i < m_y; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

class Rectangle : public Shape {
private:
    int m_x, m_y, m_width, m_height;
public:
    Rectangle(int x, int y, int width, int height)
        : m_x(x), m_y(y), m_width(width), m_height(height) {}

    void Draw(Canvas& g) override {
        for (int i = m_y; i < m_height + m_y; i++) {
            for (int j = m_x; j < m_width + m_x; j++) {
                g.setChar(j, i, '#');
            }
        }
    }
};

class Circle : public Shape {
private:
    int m_x, m_y, m_radius;
public:
    Circle(int x, int y, int radius)
        : m_x(x), m_y(y), m_radius(radius) {}

    void Draw(Canvas& g) override {
        for (int i = 0; i < g.height(); i++) {
            for (int j = 0; j < g.width(); j++) {
                double dist = std::sqrt((j - m_x) * (j - m_x) + (i - m_y) * (i - m_y));
                if (std::fabs(dist - m_radius) < 0.5) {
                    g.setChar(j, i, 'O');
                }
            }
        }
    }
};

class Cross : public Shape {
private:
    int m_x, m_y, m_size;
public:
    Cross(int x, int y, int size)
        : m_x(x), m_y(y), m_size(size) {}

    void Draw(Canvas& g) override {
    	for(int i=m_y-m_size; i<=m_y+m_size; i++){
        	g.setChar(m_x, i, '+');
    	}
    	for(int i=m_x-m_size; i<=m_x+m_size; i++){
        	g.setChar(i, m_y, '+');
    	}
	}
};

int main() {
	std::cout << "=== Shape Drawer ===\n"
			  << "Available commands:\n"
			  << "   add rectangle x y width height\n"
			  << "   add cicle x y radius\n"
			  << "   add cross x y size\n"
			  << "   show\n"
			  << "Type Ctrl+C to quit\n";

    Canvas canvas;
	std::string line;

	while(true) {
		std::cout << "> ";
		std::getline(std::cin, line);
		std::istringstream iss(line);
		std::string cmd;
		iss >> cmd;

        if(cmd == "add"){
			std::string shape;
			iss >> shape;
			if(shape == "rectangle"){
				int x, y, width, height;
				iss >> x >> y >> width >> height;
				canvas.addShape(new Rectangle(x, y, width, height));
			}else if(shape == "circle"){
				int x, y, radius;
				iss >> x >> y >> radius;
				canvas.addShape(new Circle(x, y, radius));
			
			}else if(shape == "cross"){
				int x, y, size;
				iss >> x >> y >> size;
				canvas.addShape(new Cross(x, y, size));
			}

		}else if(cmd == "show"){
    		canvas.Show();
		}else{
	   		std::cout << "Unknown command\n"; 
		}
	}
    return 0;
}

