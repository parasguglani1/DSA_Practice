//Implementing polynomials using linked lists
#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

template <typename T>
class term
{
    public:
    int index;
    T coeff;
    term *next;
};

template <typename T>
class polynomial
{
    private:
    term<T>* pol;
    void putter(int);
    int hIndex;
    public:
    polynomial()
    {
        pol = NULL;
        hIndex = 0;
    }
    polynomial(int);
    polynomial operator +(polynomial&);
    template <typename U>
    U valueof(U);
    ~polynomial();
    template <typename U>
    friend istream& operator >>(istream&, polynomial<U>&);
    template <typename U>
    friend ostream& operator <<(ostream&, polynomial<U>&);
};

template <typename T>
polynomial<T>::polynomial(int ind):polynomial()
{
    if(ind >= 0)
        hIndex = ind;
}

template <typename T>
istream& operator >>(istream& in, polynomial<T>& p)
{
    T temp; term<T>* last, *newNode;
    for(int i = p.hIndex; i >= 0; i--)
    {
        cout<<"Enter the coefficient for "<<i<<"th index: ";
        in>>temp;
        if(temp)
        {
            newNode = new term<T>;
            newNode->coeff = temp;
            newNode->index = i;
            newNode->next = NULL;
            if(!p.pol)
                p.pol = last = newNode;
            else
            {
                last->next = newNode;
                last = last->next;
            }
        }
    }
    return in;
}

template <typename T>
void polynomial<T>::putter(int n)
{
    SetConsoleOutputCP(65001);
    string rev = "";
    while(n > 0)
    {
        rev += (char)(n%10 + 48);
        n = n/10;
    }
    while(rev.length() > 0)
    {
        n = (int)rev[rev.length() - 1] - 48;
        rev = rev.substr(0, rev.length() - 1);
        
        if(n==1)
            printf("¹");
        else if(n==2)
            printf("²");
        else if(n==3)
            printf("³");
        else if(n==4)
            printf("⁴");
        else if(n==5)
            printf("⁵");
        else if(n==6)
            printf("⁶");
        else if(n==7)
            printf("⁷");
        else if(n==8)
            printf("⁸");
        else if(n==9)
            printf("⁹");
        else
            printf("⁰");
    }
}

template <typename T>
ostream& operator <<(ostream& out, polynomial<T>& p)
{
    term<T>* ptr = p.pol;
    while(ptr)
    {
        if(ptr->coeff != 1 || ptr->index == 0)
            out<<ptr->coeff;
        if(ptr->index > 0)
            out<<"x";
        if(ptr->index != 1)
            p.putter(ptr->index);
        if(ptr->next && ptr->next->coeff > 0)
            out<<"+";
        ptr = ptr->next;
    }
    return out;
}

template <typename T>
polynomial<T>::~polynomial()
{
    term<T>* ptr = pol;
    while(pol)
    {
        pol = pol->next;
        delete ptr;
        ptr = pol;
    }
    cout<<"Polynomial destructed\n";
}

template <typename T>
polynomial<T> polynomial<T>::operator +(polynomial<T>& p)
{
    polynomial<T> ans;
    term<T>* last, *ptr1 = this->pol, *ptr2 = p.pol;
    while(ptr1 && ptr2)
    {
        if(ptr1->index > ptr2->index)
        {
            if(!ans.pol)
            {
                ans.pol = new term<T>;
                ans.pol->coeff = ptr1->coeff;
                ans.pol->index = ptr1->index;
                ans.pol->next = NULL;
                last = ans.pol;
            }
            else
            {
                last->next = new term<T>;
                last->next->coeff = ptr1->coeff;
                last->next->index = ptr1->index;
                last->next->next = NULL;
                last = last->next;
            }
            ptr1 = ptr1->next;
        }
        else if(ptr1->index < ptr2->index)
        {
            if(!ans.pol)
            {
                ans.pol = new term<T>;
                ans.pol->coeff = ptr2->coeff;
                ans.pol->index = ptr2->index;
                ans.pol->next = NULL;
                last = ans.pol;
            }
            else
            {
                last->next = new term<T>;
                last->next->coeff = ptr2->coeff;
                last->next->index = ptr2->index;
                last->next->next = NULL;
                last = last->next;
            }
            ptr2 = ptr2->next;
        }
        else
        {
            if(!ans.pol)
            {
                ans.pol = new term<T>;
                ans.pol->coeff = ptr1->coeff + ptr2->coeff;
                ans.pol->index = ptr1->index;
                ans.pol->next = NULL;
                last = ans.pol;
            }
            else
            {
                last->next = new term<T>;
                last->next->coeff = ptr1->coeff + ptr2->coeff;
                last->next->index = ptr1->index;
                last->next->next = NULL;
                last = last->next;
            }
            ptr1 = ptr1->next; ptr2 = ptr2->next;
        }
    }
    while(ptr1)
    {
        last->next = new term<T>;
        last->next->coeff = ptr1->coeff;
        last->next->index = ptr1->index;
        last->next->next = NULL;
        last = last->next;
        ptr1 = ptr1->next;
    }
    while(ptr2)
    {
        last->next = new term<T>;
        last->next->coeff = ptr2->coeff;
        last->next->index = ptr2->index;
        last->next->next = NULL;
        last = last->next;
        ptr2 = ptr2->next;
    }
    return ans;
}

template <typename T>
template <typename U>
U polynomial<T>::valueof(U x)
{
    U val = 0;
    term<T>* ptr = pol;
    while(ptr)
    {
        val += ptr->coeff*pow(x, ptr->index);
        ptr = ptr->next;
    }
    return val;
}

template <typename T>
T initializer(int op)
{
    T toEnt;
    if(op == 0)
    {
        while(true)
        {
            cout<<"Enter the highest index: ";
            cin>>toEnt;
            if(toEnt >= 0)
                break;
            cout<<"Retry with a non-negative integer\n";
        }
    }
    else
    {
        cout<<"Enter the value of x: ";
        cin>>toEnt;
    }
    return toEnt;
}

int main()
{
    int hIn; float sol;
    cout<<"-----------Polynomial 1-----------\n";
    hIn = initializer<int>(0);
    polynomial<float> p1(hIn); cin>>p1;
    sol = initializer<float>(1);
    cout<<p1<<" = "<<p1.valueof(sol)<<" for x = "<<sol<<"\n";
    

    cout<<"-----------Polynomial 2-----------\n";
    hIn = initializer<int>(0);
    polynomial<float> p2(hIn); cin>>p2;
    cout<<p2<<" = "<<p2.valueof(sol)<<" for x = "<<sol<<"\n";
    
    cout<<"-----------Adduct Polynomial-----------\n";
    polynomial<float> p3 = p1+p2;
    cout<<p3<<" = "<<p3.valueof(sol)<<" for x = "<<sol<<"\n";

    return 0;
}