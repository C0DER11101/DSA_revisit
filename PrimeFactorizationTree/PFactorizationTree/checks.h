#ifndef CHECKS_H
#define CHECKS_H

bool isPrime(int n)
{
    for(int i=2; i<n; i++)
    {
        if(n%i==0)
            return false;
    }

    return true;
}

int getFactor(int n)
{
    for(int i=2; i<n; i++)
    {
        if(n%i==0)
            return i;
    }

    return -1;
}
#endif // CHECKS_H
