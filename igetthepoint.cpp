#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x, y;

public:
    Point(double x, double y) : x(x), y(y) {}

    // Override - operator to calculate distance between two points
    double operator-(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    // Override == operator to check if two points are the same
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    // Override != operator to check if two points are different
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    // Override / operator to find the midpoint between two points
    Point operator/(const Point& other) const {
        double midX = (x + other.x) / 2;
        double midY = (y + other.y) / 2;
        return Point(midX, midY);
    }

    // Getter functions for x and y coordinates
    double getX() const { return x; }
    double getY() const { return y; }
};

int main() {
    // Test the Point class
    Point p1(1, 2);
    Point p2(4, 6);

    // Test distance calculation
    cout << "Distance between p1 and p2: " << (p1 - p2) << endl;

    // Test equality and inequality
    cout << "p1 and p2 are ";
    if (p1 == p2) {
        cout << "equal." << endl;
    } else {
        cout << "not equal." << endl;
    }

    cout << "p1 and p2 are ";
    if (p1 != p2) {
        cout << "different." << endl;
    } else {
        cout << "not different." << endl;
    }

    // Test midpoint calculation
    Point midpoint = p1 / p2;
    cout << "Midpoint between p1 and p2: (" << midpoint.getX() << ", " << midpoint.getY() << ")" << endl;

    return 0;
}
