# CS 124 Project 4
# Wade Bradford

1.) Information about data set: 
My data set is a set containing data regarding the stream stastics and profiles of 1000 streamers on Twitch.Tv over the course of one year. There are 11 attributes to each streamer including: streamer name, watch time (minutes), stream time (minutes), peak viewers, average viewers, followers, followers gained, views gained, partnership status, maturity status, and the language the streamer broadcasts in.

2.) Graphs and Compare/Contrast

Bubble Sort:
![Bubble Sort (Streamers)](https://user-images.githubusercontent.com/112721212/200185309-7737db68-683b-4f12-84c1-1e714172d79f.png)
Bubble Sort is not a very efficient sorting algorithm as the number of reads and writes for the 1000 streamers are over two million and one million respectively. Bubble Sort iterates through the vector and compares each index with the index next to it and swapping depending on size. The time complexity is O(n^2), the auxillary complexity is O(1) and the space complexity is O(1).

Selection Sort:
![Selection Sort (Streamers)](https://user-images.githubusercontent.com/112721212/200185317-88c21919-5af3-433d-a9f8-61f89e003d89.png)s
Selection Sort is distinct as it has an enormous number of reads but very few writes, this is due to the swapping as it reads through the vector and only writes during a swap. It is efficient in writes, but still rather inefficient in reads as the vector of 1000 streamers reached over one million reads. The time complexity is O(n^2), the auxillary complexity is O(1) and the space complexity is O(1).


Quick Sort:
![Quick Sort (Streamers)](https://user-images.githubusercontent.com/112721212/200185322-ae0a4d15-60da-43b3-a689-e1d90f2a8609.png)
Quick Sort is very efficient (in comparison to bubble sort) as the reads and writes of the 1000 streamer vector are both < 50,000. Quick Sort splits the vector into partitions where the smaller values are on the left and the larger values are on the right. The time complexity is O(n log(n)), the auxillary complexity is O(1), and the space complexity is O(1).


Heap Sort:
![Heap Sort (Streamers, revised)](https://user-images.githubusercontent.com/112721212/200913167-24a28b21-e076-4685-ac14-d071251a7d0c.png)
Heap Sort has almost twice as many reads than writes, though it is still somewhat efficient though not as efficient as Quick Sort.  Heap Sort uses a binary heap tree to sort the elements of the vector. The time complexity is O(n log(n)), the auxillary complexity is O(1), and the space complexity is O(1).


Two Sort:
![Temp Sort (Streamers)](https://user-images.githubusercontent.com/112721212/200185339-e3609734-dd83-4808-8dcc-f27bbd29b983.png)
Two Sort uses one algorithm to sort (selection sort) and then another sorting algorithm (insertion sort) to sort on a different field. Given the sorting algorithms I used, there is once again more reads than writes by a wide margin, and the efficency of two sort depends solely on the algorithms selected for use. The time complexity of selection sort and insertion sort are O(n^2), so in theory the time complexity of two sort is O(n^4).

3.) If you need to sort a contacts list on a mobile app, which sorting algorithm(s) would you use and why?
I would use a Two Sort, likely with both being Merge Sort that first sort on the last name and then the first name. This is because merge sort is stable and while sorting by last name gets the contacts list mostly right it is likely that contacts may share a last name and then need to be sorted by first name within each last name.

4.) What about if you need to sort a database of 20 million client files that are stored in a datacenter in the cloud?
In the case of a database so large, I would use a sorting algorithm like merge sort or quick sort as they are both known for their efficency, while a faster algorithm may be more convenient it would likely be costly in memory.
