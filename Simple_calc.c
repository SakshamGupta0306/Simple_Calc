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
    float num[200];
    float res;
    char ops[200]; 
    int i=0;
    printf("What calculations you want to do & end with = sign (eg 5+3-2/4=):");
    scanf("%f %c",&num[i],&ops[i]);
    i++;
    while (1){
        scanf("%f %c",&num[i],&ops[i]);/*This takes the multiple input from the user and stores in the arrays*/
        if (ops[i]=='='){
            break;
        }
        i++;
    }
    for (int j=0;j<i;j++){
        if (ops[j] == '+'){
            res=addn(num[j],num[j+1]);
        }
        else if (ops[j] == '-'){
            res=subs(num[j],num[j+1]);
        }
        else if (ops[j] == '*'){
            res=mult(num[j],num[j+1]);
        }
        else if (ops[j] == '/'){
            res=div(num[j],num[j+1]);
            if (num[j+1]==0){
                return 0;
            }
        }
        else{
            printf ("You used an invalid operator.");
            return 0;
        }
        num[j+1]=res;
    }

    printf(" %.2f \n",num[i]);
    printf ("END");
    return 0;
}