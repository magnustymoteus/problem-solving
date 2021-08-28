#include <stddef.h>
int adjacentElementsProduct(int inputArray[], size_t input_size)
{
  int product = (inputArray[0] * inputArray[1]);
  for(int i=1;i<input_size-1;i++) {
  if((inputArray[i]*inputArray[i+1]) > product){
  product = (inputArray[i]*inputArray[i+1]);
}
}
  return product;
}
