
HideableImage : public Image
{
};


HideableImage &HideableImage :: operator=(const Image& im)
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
