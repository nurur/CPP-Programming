// Problem 8.5
// Class Vector2D


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;


class Vector2D
{
  friend const Vector2D operator*(const Vector2D& vector1, 
				  const Vector2D& vector2);
  friend ostream& operator<<(ostream& ostr, const Vector2D& vector);

public:
  Vector2D();
  Vector2D(int varx, int vary);

private:
  int x;
  int y;
};


Vector2D :: Vector2D()
{
  x = 0;
  y = 0;
}

Vector2D :: Vector2D(int varx, int vary)
{
  x = varx;
  y = vary;
}


const Vector2D operator*(const Vector2D& vector1, const Vector2D& vector2)
{
  Vector2D vector ((vector1.x * vector2.x), (vector1.y * vector2.y));
  return vector;
}


ostream& operator<<(ostream& ostr, const Vector2D& vector) 
{
  ostr << vector.x << " " << vector.y;
  return ostr;
}




int main()
{
  Vector2D A(1,2), B(3,2);
  Vector2D C = A*B;
  cout << "The components of C = A * B are: " << C << endl;

  return 0;
}
