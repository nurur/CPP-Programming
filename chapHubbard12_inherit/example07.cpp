// Example : 12.14
// Abstract Base Class


#include <cstring>
#include <iostream>
using namespace std;


class VCR
{
public:
  virtual void   ON()   =0;
  virtual void  OFF()   =0;
  virtual void PLAY()   =0;
  virtual void STOP()   =0;
  virtual void RECORD() =0;
};


class Mitshubishi: public VCR
{
public: 
  void    ON ();
  void    OFF();
  void   PLAY();
  void   STOP();
  void RECORD();
};

class Panasonic: public VCR
{
public: 
  void    ON ();
  void    OFF();
  void   PLAY();
  void   STOP();
  void RECORD();
};

class Sony: public VCR
{
public: 
  void    ON ();
  void    OFF();
  void   PLAY();
  void   STOP();
  void RECORD();
};





int main()
{
  return 0;
}
