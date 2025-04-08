#include<stdio.h>
int main()
{
    int arr[800],size=800,choiceinput,length,i,index,newValue,choice,value,found=0,j,totalElements,elementsToAdd;
    do

    {
        system("cls");
        printf("\a\a CHOOSE YOUR OPERATION\n");
        printf("01.\a\a INSERT  ELEMENT\n");
        printf("02.\a \a DISPLAY ELEMENTS\n");
        printf("03.\a \a UPDATE  ELEMENTS\n");
        printf("04.\a \a DELETE  ELEMENTS\n");
        printf("05.\a \a SERACH  ELEMENT\n");
        printf("06.\a \a SORTING\n");
        printf("07.\a \a ADDING NEW ELEMENTS\n");
        printf("00.a\ \a EXIT\n");
        printf("\a \a ENTER A OPERATION NUMBER\n");
        scanf("%d",&choiceinput);
        switch(choiceinput)
        {
        case 01:
            printf("ENTER THE NUMBER OF ELEMENT IN THE ARRAY:");
            scanf("%d",&length);
            if(length<=size)
            {
                for(i=0;i<length;i++)
                {
                    printf("Enter a number:");
                    scanf("%d",&arr[i]);
                }
            }
            else
            {
                printf("Invalid input");
            }

            break;
        case 02:
            printf("ARRAY:\n");
            for(i=0;i<length;i++)
            {
                printf("%d\n",arr[i]);
            }
            break;


        case 03:

            printf("HOW TO UPDATE: 1)With Value\t 2)With Index\n");
            scanf("%d",&choice);

            if (choice==1)
            {
                printf("Enter value to update");
                scanf("%d",&value);

                for (int i=0;i<length;i++)
                {
                    if (arr[i]==value)
                    {
                        printf("Found at index %d\n",i);
                        found=1;
                    }
                }

                if (!found)
                {
                    printf("Value not found\n");
                }
                else
                {
                    printf("Enter index to update");
                    scanf("%d",&index);
                    if (index>=0 && index<length && arr[index]==value)
                    {
                        printf("Enter new value: ");
                        scanf("%d",&newValue);
                        if (arr[index]==newValue)
                        {
                            printf("Value is already the same. No update needed.\n");
                        }
                        else
                        {
                            arr[index]=newValue;
                            printf("Updated successfully!\n");
                        }
                    }
                }
            }
            else if (choice==2)
            {
                printf("Enter index to update: ");
                scanf("%d",&index);
                if (index >= 0 && index < length)
                {
                    printf("Enter new value: ");
                    scanf("%d", &newValue);
                    if (arr[index]==newValue)
                    {
                        printf("Value is already the same. No update needed\n");
                    }
                    else
                    {
                        arr[index]=newValue;
                        printf("Updated successfully\n");
                    }
                }
                else
                {
                    printf("Invalid index\n");
                }
            }
            else
            {
                printf("Invalid choice");


            }

            break;
        case 04:
            printf("HOW TO DELETE: 1)By Value 2)By Index\n");
            scanf("%d",&choice);

            if (choice==1)
            {
                printf("Enter value to delete");
                scanf("%d",&value);

                i=0;
                while (i<length && arr[i]!=value)
                {
                    i++;
                }
                if (i<size)
                {
                    while (i <length-1)
                    {
                        arr[i]=arr[i + 1];
                        i++;
                    }
                    size--;
                    printf("Deleted successfully\n");
                }
            }
            else if (choice==2)
            {
                printf("Enter index to delete: ");
                scanf("%d", &index);

                if (index>=0 && index<length)
                {
                    while (index <length-1)
                    {
                        arr[index]=arr[index + 1];
                        index++;
                    }
                    size--;
                    printf("Deleted successfully\n");
                }
                else
                {
                    printf("Invalid index.\n");
                }
            }
            else
            {
                printf("Invalid choice\n");
            }
            break;

        case 05:
            printf("HOW TO SEARCH: 1) By Value\t 2) By Index\n");
            scanf("%d",&choice);

            if (choice==1)
            {
                printf("Enter value to search: ");
                scanf("%d",&value);

                found=0;
                i=0;
                while (i<length)
                {
                    if (arr[i]==value)
                    {
                        printf("Found at index %d\n", i);
                        found = 1;
                    }
                    i++;
                }
                if (!found)
                {
                    printf("Value not found\n");
                }
            }
            else if (choice==2)
            {
                printf("Enter index to search");
                scanf("%d",&index);

                if (index>= 0 && index<length)
                {
                    printf("Value at index %d is %d\n",index,arr[index]);
                }
                else
                {
                    printf("Invalid index\n");
                }
            }
            else
            {
                printf("Invalid choice\n");
            }
            break;
        case 6:
            printf("SORT ELEMENTS: 1) Ascending 2) Descending\n");
            scanf("%d", &choice);
            if (choice==1)
            {
                for (i=0; i<length-1; i++)
                {
                    for (j=0; j<length-i-1; j++)
                    {
                        if (arr[j] > arr[j + 1])
                        {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j+1] = temp;
                        }
                    }
                }
                printf("Sorted in Ascending Order: ");
                for (i=0; i<length; i++)
                {
                    printf("%d ",arr[i]);
                }
                printf("\n");
            }
            else if (choice==2)
            {
                for (i=0; i<length-1; i++)
                {
                    for (j=0; j<length-i-1; j++)
                    {
                        if (arr[j]<arr[j + 1])
                        {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j+1]=temp;
                        }
                    }
                }
                printf("Sorted in Descending Order: ");
                for (i=0; i<length; i++)
                {
                    printf("%d ",arr[i]);
                }
                printf("\n");
            }
            else
            {
                printf("Invalid choice\n");
            }
            break;
        case 07:
            if (length<size)
            {
                printf("How many new elements do you want to add? ");
                scanf("%d", &elementsToAdd);

                totalElements =length + elementsToAdd;

                if (totalElements>size)
                {

                    printf("ERROR: Not enough space!\n");
                }
                else
                {
                    i=length;
                    while (i<totalElements)
                    {
                        printf("Enter new value: ");
                        scanf("%d", &arr[i]);
                        i++;
                    }
                    length=totalElements;
                    printf("Added successfully!\n");
                }
            }
            else
            {
                printf("Array full!\n");
            }
            break;
        }
        system("pause");
    }
    while(choiceinput!=0);
    return 0;
}
