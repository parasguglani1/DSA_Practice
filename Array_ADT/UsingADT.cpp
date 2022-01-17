//Utilizing the Array Data Type
#include "ADT.h" 
//may/may not include iostream
int main()
{
    int n, in;
    cout<<"Enter non-negative/valid integers only (within array size)!\n"; 
    cout<<"Enter the array size: "; cin>>n;
    Array<int> Arr(n);

    cout<<"Enter the number of elements you desire to enter: "; cin>>n;
    Arr.enterElements(n);
    cout<<"The array is: "; Arr.display();

    cout<<"Enter the index and value you want to insert: ";
    cin>>in>>n; Arr.insert(n, in);
    cout<<"The array is: "; Arr.display();

    cout<<"Enter the index for deleting an element: ";
    cin>>in; Arr.Delete(in);
    cout<<"The array is: "; Arr.display();

    cout<<"The array is: ";
    if(Arr.isSorted())
        cout<<"sorted\n";
    else
        cout<<"unsorted\n";

    cout<<"Enter a number for which the index is sought: "; cin>>n; 
    if(Arr.isSorted())
        if(Arr.bSearch(n) != -1)
            cout<<"Found at index: "<<Arr.bSearch(n)<<"\n";
        else
            cout<<"Not found\n";
    else
        if(Arr.lSearch(n) != -1)
            cout<<"Found at index: "<<Arr.lSearch(n)<<"\n";
        else
            cout<<"Not found\n";
    
    cout<<"Largest element: "<<Arr.largest()<<"\nSmallest element: "<<Arr.smallest()<<"\n";
    cout<<"Sum of elements: "<<Arr.sum()<<"\nAverage of elements: "<<Arr.average()<<"\n";

    cout<<"Enter an index and replacement for replacing an element: "; cin>>in>>n;
    cout<<Arr.set(n, in)<<" was replaced with "<<n<<" at index "<<in<<"\n";
    cout<<"The array is: "; Arr.display();

    cout<<"Enter an index to get the element situated therein: "; cin>>in;
    cout<<"Element at index "<<in<<" is: "<<Arr.get(in)<<"\n";

    cout<<"Array rotated rightwards by two units: "; 
    Array<int> temp; Arr.setEqual(&temp);
    temp.ShiftRotate(1, 2);
    cout<<"The array is: "; temp.display();

    cout<<"Array shifted leftwards by three units: ";
    Arr.setEqual(&temp); temp.ShiftRotate(0, -3);
    cout<<"The array is: "; temp.display();

    if(Arr.isSorted())
    {
        cout<<"Enter an element to be inserted: "; cin>>n;
        Arr.insertSorted(n); 
        cout<<"The array is: "; Arr.display();
    }

    cout<<"Enter the array size: "; cin>>n;
    Array<int> B(n), C(n);

    cout<<"Enter the number of elements you desire to enter: "; cin>>n;
    B.enterElements(n);
    cout<<"The array is: "; B.display();

    B.setEqual(&C); B.setEqual(&temp);

    cout<<"========================\n";
    Arr.display(); B.display();
    cout<<"Union of above two is: ";
    (Arr.Union(B))->display();
    
    cout<<"========================\n";
    Arr.display(); C.display();
    cout<<"Intersection of above two is: ";
    (Arr.Intersection(C))->display();

    cout<<"========================\n";
    Arr.display(); temp.display();
    cout<<"Difference between two is (first one being the minuend): ";
    (Arr.Difference(temp))->display();

    cout<<"Program terminated\n";

    try
    {
        B.~Array(); Arr.~Array();
        C.~Array(); temp.~Array();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
//a full-fledged menu-driven program can be developed