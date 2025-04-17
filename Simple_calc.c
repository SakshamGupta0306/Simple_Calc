#include <stdio.h>

int addn(float num1,float num2){
    return num1+num2;
}

int subs(float num1,float num2){
    return num1-num2;
}

int mult(float num1,float num2){
    return num1*num2;
}

float div(float num1,float num2){
    if (num2==0){
        printf("Error, Division with 0 is not possible.");
    }
    else{
        return num1/num2;
    }
    return 0;
}



int main(){
    float num1,num2,res;
    char ops;
    printf("What you operations you want to do with 2 numbers:");
    scanf("%f %c %f",&num1,&ops,&num2);
    if (ops == '+'){
        res=addn(num1,num2);
    }
    else if (ops == '-'){
        res=subs(num1,num2);
    }
    else if (ops == '*'){
        res=mult(num1,num2);
    }
    else if (ops == '/'){
        res=div(num1,num2);
        if (num2==0){
            return 0;
        }
    }
    else{
        printf ("You used an invalid operator.");
        return 0;
    }
    printf ("%.2f",res);
return 0;
}