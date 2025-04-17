#include <stdio.h>
#include <stdlib.h>

float addn(float num1,float num2){
    return num1+num2;
}

float subs(float num1,float num2){
    return num1-num2;
}

float mult(float num1,float num2){
    return num1*num2;
}

float divide(float num1,float num2){
    if (num2==0){
        printf("Error, Division with 0 is not possible.");
        exit(1);
    }
    else{
        return num1/num2;
    }
}


void shift_elements(float num[],char ops[],int start,int end){
    for (int k = start; k < end; k++) {
        num[k] = num[k + 1];
        ops[k] = ops[k + 1];
    }
}


int main(){
    float num[200];
    float res=0;
    char ops[200];
    int i=0;
    printf("Write your Equation in form of (2+3-4=) No negative numbers:");
    scanf("%f %c",&num[i],&ops[i]);
    i++;

    //Reading the Expression
    while (1){
        scanf("%f %c",&num[i],&ops[i]);
        if (ops[i]=='='){
            break;
        }
        i++;
    }

    int Total_elements=i;
    
    //Printing the same expression
    printf("Expression:");
    for (int j=0; j<=i ; j++){
        printf("%.2f %c ",num[j],ops[j]);
    }
    printf("\n");

    //Operation Precedence

    //Division
    for (int j=0;j<i;j++){
        if (ops[j] == '/'){
            res=divide(num[j],num[j+1]);
            ops[j]=ops[j+1];
            num[j]=res;
            shift_elements(num,ops,j+1,i);
            i--,j--;
            }
        }

    //Multiplication
    for (int j=0;j<i;j++){
        if (ops[j] == '*'){
            res=mult(num[j],num[j+1]);
            ops[j]=ops[j+1];
            num[j]=res;
            shift_elements(num,ops,j+1,i);
            i--,j--;
        }
    }

    //Subtraction
    for (int j=0;j<i;j++){
        if (ops[j] == '-'){
            res=subs(num[j],num[j+1]);
            ops[j]=ops[j+1];
            num[j]=res;
            shift_elements(num,ops,j+1,i);
            i--,j--;
        }
    }

    //Addition
    for (int j=0;j<i;j++){
        if (ops[j] == '+'){
            res=addn(num[j],num[j+1]);
            ops[j]=ops[j+1];
            num[j]=res;
            shift_elements(num,ops,j+1,i);
            i--,j--;
        }
    }


    //for (int j=0;j<= Total_elements;j++){
    //    printf(" %f %d \n",num[j],j);
    //}

    //Result
    printf("Result: %.2f \n",num[0]);
    printf ("END\n");
    return 0;
}

