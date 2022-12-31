#include <iostream>
#include <string>

using namespace std;



/**
 * @param   find the array of integers
 * @param   size the size of the array
 * @return  A new list of product of all other elements for each index
 * n = size
 * runtime n^2
*/
int *product_no_div(int find[], size_t size){
    //Set the size of the new array
    int *result = (int*) malloc(sizeof(int) * size);
    
    //Go through each element
    for(int i = 0; i < size; i++){
        //Set the result to the multiplication identity
        result[i] = 1;
        //Then go through the list again and multiply each element together
        //EXCEPT for the one in the current index
        for(int j = 0; j < size; j++){
            if(i != j){
                result[i] *= find[j];
            }
        }
    }
    //Return the result of the array
    return result;
}



/**
 * @param   find the array of integers
 * @param   size the size of the array
 * @return  A new list of product of all other elements for each index
 * n = size
 * Runtime 2n
*/
int *product_fast(int find[], size_t size){

    //Set the size of the new array
    int *result = (int*) malloc(sizeof(int) * size);
    //Make the product equal to the identity
    //This could also be set to the first element, but that is not done in this case
    int product = 1;

    //Get the product of all the elements together
    for(int i = 0; i < size; i++){
        product *= find[i];
    }

    //Since its product we just remove the one element we don't want for that spot
    //We do this by dividing
    for(int i = 0; i < size; i++){
        result[i] = product/find[i];
    }

    //Then return the result
    return result;
}




/**
 * main function
*/
int main(){
    //List of test arrays to use
    int array[5] = {1, 2, 3, 4, 5};
    int array2[3] = {3, 2, 1};

    //Buffer space to make it look slightly better
    std::cout << endl;


    //No div len 5
    int *result = product_no_div(array, sizeof(array)/sizeof(int));
    std::cout << "No division length 5:" << endl;
    for(int i = 0; i < 5; i++){
        std::cout << result[i] << " ";
    }
    std::cout << endl << endl;
    //Free as we use malloc
    free(result);


    //No div len 3
    int *result2 = product_no_div(array2, sizeof(array2)/sizeof(int));
    std::cout << "No divison length 3:" << endl;
    for(int i = 0; i < 3; i++){
        std::cout << result2[i] << " ";
    }
    std::cout << endl << endl;
    //Free as we use malloc
    free(result2);



    //Div len 5
    result = product_fast(array, sizeof(array)/sizeof(int));
    std::cout << "Divison length 5:" << endl;
    for(int i = 0; i < 5; i++){
        std::cout << result[i] << " ";
    }
    std::cout << endl << endl;
    //Free as we use malloc
    free(result);



    //Div len 3
    result2 = product_fast(array2, sizeof(array2)/sizeof(int));
    std::cout << "Divison length 3:" << endl;
    for(int i = 0; i < 3; i++){
        std::cout << result2[i] << " ";
    }
    std::cout << endl << endl;
    //Free as we use malloc
    free(result2);

    return 0;
}