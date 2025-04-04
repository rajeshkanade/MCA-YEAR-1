  #include<stdio.h>
  #include<math.h>
  float calculateSum(int n , float x);
  float fact(int i);

  // main function 
  int main(){

    float x;
    int n;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    printf("Enter the value of x : ");
    scanf("%f",&x);


    float answer = calculateSum(n,x);
    printf("Total Sum : %.5f\n\n",answer);
    
    return 0;
  }

  float fact(int i){
    
    if(i == 0 || i == 1){ 
        return 1;
    }else{
    return  i * fact(i - 1);
    }
  }

 


  float calculateSum(int n , float x){

    float sum = 0;

    for(int i = 1 ; i <= n ; i++){
      float factorialNumber = fact(i);
      float powerNumber = pow(x,i);
      sum += (factorialNumber/powerNumber);
    }

    return sum;
  }