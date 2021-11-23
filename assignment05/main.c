
void swap_ptr(int** x, int** y)
{  
    int* tempPtr = *x;
    *x = *y;
    *y = tempPtr;
}

int main()
{
  
  int x = 10;
  int y = 20;
  int* xPtr = &x;
  int* yPtr = &y;
  
  swap_ptr(&xPtr, &yPtr);
  
  return 0;
}