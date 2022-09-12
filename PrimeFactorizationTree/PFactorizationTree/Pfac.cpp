#include<iostream>
#include<stdlib.h>
#include "Struct.h"
#include "checks.h" // to check for some conditions
#include "Factorize.h"  // actual factorization process

/*
SOURCE OF IDEA:
THE MATHEMATICS BOOK OF CLASS-4
THE CREDIT GOES TO MY LITTLE BROTHER WHO IS STUDYING IN CLASS-4
I FOUND THE PRIME-FACTORIZATION TREE IN HIS BOOK AND THOUGHT IF IT WAS POSSIBLE
TO REALLY IMPLEMENT IN CODE AND BOOOM!!! HERE IT IS!!!
*/

int main(void)
{
    int num;

    cout<<"enter a number: ";
    cin>>num;

    if(getFactor(num)==-1)
    {
        cout<<"Prime factors of "<<num<<":\n\n";
        cout<<num<<" "<<1<<endl;
        return 0;
    }

    factorTree*root=NULL;

    root=factorize(root, num);

    cout<<"\n\nhere is the factor tree displayed using traversals!!\n\n";

    cout<<"inorder traversal:\n\n";
    inorder(root);

    cout<<"\n\npreorder traversal:\n\n";
    preorder(root);

    cout<<"\n\npostorder traversal:\n\n";
    postorder(root);

    cout<<"\n\nhere are the prime factors!!\n\n";

    PrimeFactors(root);

    cout<<"\n\n";

    terminate(root);

    return 0;
}
