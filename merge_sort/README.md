# Lab- Sorting Part 2: Merge Sort

> [!IMPORTANT]
> This activity builds on your Homework and Lab - Sorting. While we have provided template files here, you will want to merge (pun intended) this code into your Homework 05.  Please make sure to give credit on who worked on this code with you. As a reminder, the stuff done in team activities are the team's work, but your other homework requirements are your *own* (don't plagiarize!)

👉🏽 **Task**: As a group you will implement the `merge` and the `mergeSort` function in [sorts.h](sorts.h). 

Merge sort is a [divide and conquer algorithm] that was invented by [John von Neumann] in 1945. Merge sort has a worst-case time complexity being $Ο(n\log n)$. Of our sorting algorithms that we have seen, this is the best overall time complexity.

> Yes, the same von Neumann who designed [modern computer architecture]. 

The goals for this team activity are as follows:
* To implement merge sort as a group
* To better understand divide and conquer type algorithms
  
  
## :star: Working in Teams :star:
When working in teams, remember do not let one person do all the work. Make sure to work together, and ask questions. It is also better if different people program, and you all take turns programming for various team assignments. 

## Merge sort works as follows:

1. Repeatedly divide the unsorted array into n subarrays (a subarray being 'a smaller part' of the original array) until each subarray contains one element (Note: an array of one element is already sorted).
2. Then, repeatedly merge subarrays to produce new sorted subarrays until there is only one subarray remaining. The result will be the sorted array.


Here is a diagram showing the two steps above in the picture (As they say a picture is worth a thousand words!):

![Merge Sort]


As we are learning about psuedo-code, here is the same thing in psuedo-code:
```text
mergeSort(arr[], temp[], l,  r):
  if r > l
     1. Find the middle point 'm' to divide the array into two halves:  
             m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, temp, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, temp, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, temp, l, m, r)
```

### Discussion

1. Given the pseudo code: is merge sort an [in-place algorithm]? Why or why not?

We think that this qualifies as an in-place sort because at the end the result is copied back into the original array.


## MergeSort
In sorts.h, find `merge_sort(int arr[], int temp[], int l, int r)`. This is your primary of two functions you will want to implement. 


You will find the temp array has already been created for you in the provided function

```c
void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
        return;

    int *temp = (int *)malloc(sizeof(int) * size);
    merge_sort(array, temp, 0, size - 1);
    free(temp);
}
```

As such, your mergeSort function may only be three lines excluding NULL and size checks! Divide one half, Divide the other half, then merge the return result!

Make sure to compile as you write, as it is easier to track syntax errors. 

## Merge

This function can be a bit complex, if you don't carefully think about it. You have two arrays. Your temp array is handling where you first store the "sorted values". At the **end of the merge**, you copy your temp array, back into your original array. 


```c
for (i = l; i <= r; i++)
{
   arr[i] = temp[i];
}
```

### Building the temp array
The locations actually give the split arrays. So you have an array from `l` to `m` and an array from `m+1` to `r`. 

That is why in the provided code
```c
int i = l; // the start of the first array
int j = m+1; // the start of the second array!
```

and since the temp array has to hold all values as they are merging, we only modify the same indices in the sorted array, making `int start = l`

That will mean we will be copying from

```c
temp[start++] = arr[i++]; // or j++ depending on which is higher or lower, or both if they are equal!
```

#### Don't forget
It is also easy to forget to copy the remainder of the array into temp that hasn't been evaluated! 

In the end, you end up with 3 while loops (not nested!). 



### Discuss and Build
Work together with your partners to build the merge function. While the code is provided online, it is important to understand each step, so take piece of paper out and draw samples.  Comment in the code with your understanding.

> **Challenging**:  
> The merge sort is a challenging algorithm, that looks simple after it is completed. It is why we are doing it in a group, and you are free to use online resources if you get stuck. Just make sure you **understand** what is going on.
>


> [!NOTE]
> You are welcome to add a operations counter, and see how the operations look.
> However, we recommend you setting a print flag for the ops counter, 
> so it doesn't mess up your homework output. 

## Other Sorts?
Take time to search additional sorts online (there are a *ton* of them). Each person should find a sort, and describe to the group what situations it is best used for. Even better if you can find a visualization for that sort. 

* Daymian: Tim Sort is a hybrid algorithim, relying on insertion sort and merge sort mainly. Tim sort reduces the number of comparisons in sorting by identifying "runs", or series of already consectutive ordered elements existing in the dataset. Since most real-world data contain such runs, we don't need to make as many comparisons and our runtime is reduced. "In the worst case, Timsort takes O(n log n) comparisons to sort an array of n elements. In the best case, which occurs when the input is already sorted, it runs in linear time, meaning that it is an adaptive sorting algorithm [1]." You can view a visualization here [2]!.

* Umer - Heap Sort first builds a binary tree and than recursively work on smaller binary tree to bring the largest number to the top of the tree. [3]

* Judson: Pigeonhole Sort is a sorting algorithm that is best for sorting lists of elements where the number of elements and the number of possible key values are approximately the same. 
References: [4]

* Tor: Bucket Sort - Bucket sort is a sorting technique that involves dividing elements into various groups, or buckets. These buckets are formed by uniformly distributing the elements. Once the elements are divided into buckets, they can be sorted using any other sorting algorithm. Finally, the sorted elements are gathered together in an ordered fashion. [5]

## Technical Interview Practice

Lastly, work on leet code practice. Everyone pick a different problem, and take turns explaining your solution *as* you work through the code (as time allows). This is called "live coding" and often required in technical interviews. Moving forward, we would like you to emphasize the explaining of code as you work through it, to better prepare you for technical interviews. You should also discuss one of the technical interview questions as a group.

*Technical Question: When would you use recursion versus when would you not use recursion?*
Non-recursive functions are good for simple iterative processes. However, they can be performance heavy and lead to stack overflow issues. Recursive functions are good for repetitions and math-heavy sequences, like divide and conquer algorithms and factorials. Personally, I choose to write non-recursive functions whenever possible.

* Daymian: Number of 1 Bits

* Tor: Valid Parentheses

* Umer: Power of Two

* Judson: Remove Duplicates from Sort Array

## 📚 Resources
* [Merge Sort on Khan](https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/divide-and-conquer-algorithms)
* [Merge Sort Video](https://www.youtube.com/watch?time_continue=1&v=JSceec-wEyw)


## References
[1]: Wikipedia contributors. 2024. Timsort. Wikipedia, The Free Encyclopedia. Retrieved June 4, 2025 from https://en.wikipedia.org/wiki/Timsort
[2]: Laux, Chris. Timsort. Chris Laux Blog. Retrieved June 4, 2025 from https://www.chrislaux.com/timsort
[3]: https://sortvisualizer.com/heapsort/
[4]: https://www.geeksforgeeks.org/pigeonhole-sort/
[5]: https://www.geeksforgeeks.org/bucket-sort-2/
[Merge Sort]: mergesort.svg
[divide and conquer algorithm]: https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm
[John von Neumann]: https://en.wikipedia.org/wiki/John_von_Neumann
[in-place algorithm]: https://en.wikipedia.org/wiki/In-place_algorithm
[modern computer architecture]: https://en.wikipedia.org/wiki/Von_Neumann_architecture
