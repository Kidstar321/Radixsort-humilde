#ifndef RADIXSORT_H
#define RADIXSORT_H

//Radix sorts any integer (negative,positive,big or small)
//Parameters:
//i is the size of the array we will be sorting
//vetor the array we will be messing around with
//
//This is in ascending order btw
//You can ignore the aux functions if you want, but if you want to use them they are self explanatory I believe
void inverter(int i,int string[]) //aux function that reverses an array
{
    int aux[i];

    for(int a=0;a<i;a++)
        aux[a]=string[a];
    for(int a=0;a<i;a++)
        string[a]=aux[i-1-a];
    
}
int valorcasa(int n,int k) //aux funtction that guives you the k numerical digit (base 10) of a number n
{
    int b=1;
    for(int a=0;a<k;a++)
      b=b*10;
    n=n%b/(b/10);
    return n;

}
void sortncasas(int i,int vetor[]) //the good shit
{
    int posição[10][i],contador[10]={0,0,0,0,0,0,0,0,0,0},negativo=0,vetorneg[i],auxneg=0,maxcasas=0,auxtmn=1,b=0,maxvalor=0;

    for(int a=0;a<i;a++)
    {
        if(vetor[a]<0) //takes all negatives and throws it to another array in absolute value
        {
            vetorneg[auxneg]=-vetor[a];
            vetor[a]=0;
            auxneg++;
            negativo=1;
        }
    }

    for(int a=0;a<i;a++) //finds the highest value 
        maxvalor=(vetor[a]>maxvalor?vetor[a]:maxvalor);
    
    if(maxvalor) //checks how many digits it has
    {   while(maxvalor>0)
        {
            maxvalor/=10;
            maxcasas++;
        }
    }
    else maxcasas=1;

    for(int casa=1;casa<=maxcasas;casa++) //bucket sorts from the first digit to max one (maxcasas)
    {
        for(int a=0;a<i;a++) //takes every number vetor[a] and puts in inside a matrix
        {                    // where every line is it's "casa" digit (bucket sort pt1)
            for(int k=0;k<10;k++)
            {
                if(k==valorcasa(vetor[a],casa))
                {
                    posição[k][contador[k]]=vetor[a];
                    contador[k]++;
                    break;
                }
            }
        }

        b=0;

        for(int k=0;k<10;k++) //takes this new organized matrix and spreads it from line 0 to 9 into the og array
        {
            for(int a=0;a<contador[k];a++)
            {
                vetor[b]=posição[k][a];
                b++;
            }
            contador[k]=0;
        }
    }

   if (negativo) //applies the function into this aux array of the negative numbers (here in absolute value)
   {             //and then puts then in reverse order and give them back their negative sign
        sortncasas(auxneg,vetorneg);
        inverter(auxneg,vetorneg);

        for(int a=0;a<auxneg;a++)
            vetor[a]=-vetorneg[a];
   }

} 

#endif