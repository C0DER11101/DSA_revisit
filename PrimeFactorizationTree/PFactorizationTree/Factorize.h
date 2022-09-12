#ifndef FAC_H
#define FAC_H

factorTree*factorize(factorTree*root, int num)
{
    if(root==NULL)
    {
        if(isPrime(num))
        {
            root=new factorTree;
            root->data=num;
            root->right=root->left=NULL;
            return root;
        }

        else
        {
            root=new factorTree;
            root->data=num;
            root->left=root->right=NULL;
        }
    }


    root->left=factorize(root->left, getFactor(num));
    root->right=factorize(root->right, num/getFactor(num));

    return root;
}

void preorder(factorTree*root)
{
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(factorTree*root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(factorTree*root)
{
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void PrimeFactors(factorTree*root)
{
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
        return;
    }

    PrimeFactors(root->left);
    PrimeFactors(root->right);
}

void terminate(factorTree*root)
{
    if(root==NULL)
        return;

    terminate(root->left);
    terminate(root->right);
    delete root;
}

#endif // FAC_H
