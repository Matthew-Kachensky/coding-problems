#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * @param       values the list of values in which we are finding the window of
 * @param       first the first index for the window
 * @param       last the last index for the window
 * @param       size the amount of elements in the list of values
*/
void find_window(int *values, int *first, int *last, size_t size){
    //Make a vector
    std::vector<int> sorted(size);


    //Make a copy of the original list to the vector
    std::copy(values, values+size, sorted.begin());


    //Sort the copied vector
    std::sort(sorted.begin(), sorted.begin()+size);



    //Compare the sorted array to the original
    for(int i = 0, j = size - 1; i < j;){
        
        //If first element is matched then go next element
        if(values[i] == sorted[i]){
            i++;
        }

        //If last element is matched then go to the previous element
        else if(values[j] == sorted[j]){
            j--;
        }

        //If neither matches, then we have to perform a sort on the subset
        else {
            *first = i;
            *last = j;
            break;
        }
    }
}



int main(){
    //Initial values
    int values[] = {3, 7, 5, 6, 9};
    int first = 0;
    int last = 0;
    size_t size = sizeof(values)/sizeof(int);

    //Find the window
    find_window(values, &first, &last, size);

    //Print out the array
    std::cout << "{ ";
    for(int i = 0; i < size; i++){
        std::cout << values[i] << " ";
    }
    std::cout << "}" << endl;
    

    //Print out the window
    std::cout << "(" << first << ", " << last << ")" << endl;

    return 0;
}