# Made by: Matthew Kachensky
# 1/3/2023




# The array package used in the problem
# Used for the homogeneity over lists
import array as array


# param:    numbers the list of numbers that we are tring to find how many to the right are smaller
# Returns the array for the number of elements
# Inefficient?
# Runtime could be better?
def to_the_right(numbers):
    # Create the array for the number of smaller elements
    isSmaller = array.array('d')

    # A counter used to splice the array
    counter = 0

    # Go throught the list of numbers
    for i in numbers:

        # Increament the counter for the splice
        counter += 1

        # Reset the value to add to the array
        smaller = 0

        # Go through all future elements in the list
        # Done by a splice
        for j in numbers[counter:len(numbers)]:

            # If the number is smaller than the current number then increase the count by 1
            if(j < i):
                smaller += 1

        # After compaing the elements add the number to the list
        isSmaller.append(smaller)

    # Return the final array, just used to print
    return isSmaller






# The main function
def main():

    # Original array to work on
    original = array.array('d', [3, 4, 9, 6, 1])
    # Output should be: [1, 1, 2, 1, 0]

    testvalues = array.array('d', [1, 2, 3, 4, 5])
    othertestvalues = array.array('d', [5, 4, 3, 2, 1])

    # Print the results
    print(to_the_right(original))
    print(to_the_right(testvalues))
    print(to_the_right(othertestvalues))





# Call the main function
if __name__ == "__main__":
    main()