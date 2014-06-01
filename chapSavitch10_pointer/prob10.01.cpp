// Problem 10.1 (Example : 10.9 using Class)
// Two-dimensional Dynamic Array 


#include <iostream>
using namespace std;


class TwoD
{
public:
  TwoD();
  TwoD(int nrows, int ncols);
  TwoD(const TwoD& twod);
 ~TwoD();

  void setRowsCols(int setRows, int setCols);
  int getRows() const { return MaxRows; } 
  int getCols() const { return MaxCols; }
  //double** getDynamicArray(int nrows, int ncols);

private:
  double** arrayTwoD;
  int MaxRows;
  int MaxCols;
};

TwoD :: TwoD()
{
  MaxRows = 5;
  MaxCols = 5;

  arrayTwoD = new double*[MaxRows];
  for (int i=0; i < MaxRows; i++)    
    arrayTwoD[i] = new double[MaxCols];
}

TwoD :: TwoD(int nrows, int ncols)
{
  MaxRows = nrows;
  MaxCols = ncols;

  arrayTwoD = new double*[nrows];
  for (int i=0; i < nrows; i++)    
    arrayTwoD[i] = new double[ncols];
}

TwoD :: TwoD(const TwoD& twod)
{
  MaxRows = twod.getRows();
  MaxCols = twod.getCols();

  arrayTwoD = new double*[twod.getRows()];
  for (int i=0; i < twod.getRows(); i++)
    arrayTwoD[i] = twod.arrayTwoD[i];
}

TwoD :: ~TwoD()
{
  for (int i=0; i < MaxRows; i++)
  delete[] arrayTwoD[i];
}


void TwoD :: setRowsCols(int setRows, int setCols)
{
  MaxRows = setRows;
  MaxCols = setCols;
} 



int main()
{
  TwoD x(3,4);

  TwoD y;
  y.setRowsCols(3,4);

  return 0;
}
