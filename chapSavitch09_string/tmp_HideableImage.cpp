// Image Class


class Image
{
public:
  Image();
  Image(const Image& im);
  Image(int w, int h, char* bm);
 ~Image();
  Image& operator=(const Image& im);
  
  virtual void Show(int xs, int ys);

protected:
  int w, h;          // Dimension of image 
  char* bitmap;      // Bitmap of image 
  int Copy(int iw, int ih, char* bm);
};



void Image :: Copy(int iw, int ih, char* bm)
{
  w = iw; 
  h = ih; 
  bitmap = new char[w*h];
  
  if (bitmap)     // Allocation worked
    {
      memcpy(bitmap,bm,w*h);
      return 1;
    }
  else           // Allocation failed. Set Image to Null
    { w = 0;
      h = 0;
      return 0;  // Allocation failed
    }
}



Image :: Image ()
// Default constructor 
// Create an empty image 
{
  w = 0;
  h = 0;
  bitmap = 0;
}

Image :: Image (const Image& im)
// Copy constructor 
// Copy Image type im into itself
{
  Copy(im.w, im.h, im.bitmap);
}


Image :: ~Image ()
// Destructor 
// De-allocates bitmap
{
  delete[] bitmap;
}


Image& Image :: operator=(const Image& im)
// Copy Assignment constructor 
// Copy Image type im into itself
{
  delete[] bitmap;
  Copy(im.w, im.h, im.bitmap);
  return *this;
}





HideableImage : public Image
{
};


HideableImage& HideableImage :: operator=(const Image& im)
{
  // we must reallocate backing store to a new size
  // but first, we must hide the image if it is showing

  // keep track of show status 
  int ss = showing;  

  Hide();
  delete[] backing_store;


  // let base class operator do its thing
  Image :: operator=(im);
  // noew reallocate the backing store to correct size
  backing_store = new char[w*h];

  // redisplay image if necessary
  if (ss) Show(x,y);
  return *this;
}




int main()
{

  return 0;
}
