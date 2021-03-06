## Welcome to Samantha Coyle's Research Page

With the hope of acquiring a masters in computer science (MCS) degree or a PhD in computer science, I have begun researching topics of interest to me in my field of study as an undergraduate.

### Motivation

Algorithmic efficiency has become hugely important due to the need to analyze massive data sets generated by cloud computing and the Internet of Things. While making algorithms more succinct and comprehensive, recursion can also be highly inefficient when applied to these data sets. As an alternative to recursion in many applications, dynamic programming techniques can significantly improve runtime efficiency. Although runtime efficiency has been widely studied for specific problem applications, less attention has been given to the relationship of language and underlying architecture to a broader measure of efficiency that includes both runtime and resource consumption. This investigation explores and compares runtime efficiency and resource consumption for both recursive and dynamic programming across several different programming languages that abstract widely differing architectural elements. In order to get a broad understanding of the relationship between recursive algorithms and dynamic algorithms, the widely applicable Fibonacci algorithm was chosen as a simple means of keeping the algorithm as constant as possible, while maintaining feasibility for the monitoring of resources across several programming languages. A full comparison of all studied languages is presented, the potential factors behind the results analyzed and the possible ramifications for actual use discussed.

### Objectives
- Learn about profile monitoring utilities for complex processes
- Access the functionality and limitations of the perf command line resource monitoring utility
- Gain an understanding of the architectural differences among a variety of programming languages, to include compiled versus interpreted
- Determine how programming languages with differing architectural components affect runtime, task-clock time, CPU-cycles, instruction count, page-faults, and cache-misses
- Analyze how recursive algorithms compare to dynamic algorithms in resource consumption and runtime efficiency

### Methodology

1. Set up the environment
- Figure out the kind of machine you are going to perform on. Ensure all programming languages and performance monitoring utilities are installed and up-to-date.
2. Execution
- Utilize a Fibonacci algorithm for both the recursive and dynamic algorithm. Execute the programs utilizing Fibonacci numbers of 20, 30, 40, and 50, gathering data on runtime, CPU-cycles, task-clock rates, instruction counts, clock rate, page-faults, cache-misses, % of all cache refs, and speedup.
3. Analysis
- Compare the results across the various programming languages tested, and in terms of the dynamic algorithm, versus the recursive algorithm.
- Focus on C vs Python

### Algorithm Results
#### Observations
The overall runtime for the recursive algorithms were larger than the dynamic algorithm runtimes. The overall trend for the recursive algorithms included an increase in resource consumption for the Fibonacci numbers of 30 and 40, whereas the dynamic algorithm results trended mostly linearly.

#### Analysis
Because of the characteristics of recursive algorithms, it is expected for the runtimes to be slower as there is higher overhead from the call stack being used so heavily. Furthermore, programs are bounded by physical memory, so it is likely that Perl, Python, and Go reached their limit. Otherwise, as the compiler was setting up the activation records, it was trying to do something fancy with the algorithm; thus, causing issues for the runtimes. The dynamic algorithm did not have these issues as there is little overhead. The CPU-cycles may have been reported incorrectly as perf is sample based, and does not count every cycle. It is likely the programs ran too fast and perf didn’t catch all of the CPU-cycles. In addition, the task-clock and instruction count results can be explained by the higher overhead. For larger Fibonacci numbers, it became unfeasible to calculate the resources as the stack grew too large for the recursive algorithm. The dynamic algorithms were more linear as the resources needed to calculate the larger Fibonacci numbers became higher, because more resources are necessary to deal with larger input values.

### Language Results
#### Observations
The runtimes of Python and Perl appear to be essentially infinite near the Fibonacci number of 30 with the result that no data could be collected for higher numbers. Perl showed a recursive runtime increase of 99.97% up to the Fibonacci number of 40. It’s interesting that Go was 99.97% slower than C, another compiled language, for the recursive algorithm. Also surprisingly, the dynamic algorithm showed a higher runtime for C and Go, versus Perl and Python rather than the inverse, which was expected.

#### Analysis
Being that interpreted languages are interpreted one line at a time, they generally execute slower. However, in this experiment, they executed faster for the dynamic algorithm. This inconsistency can be explained by the default optimization levels of each of the programs potentially being different, or issues with the scope of the Fibonacci numbers. In addition, Go had an unusually high resource consumption possibly due to perf not calculating the results properly as its results are  sample based. Furthermore, all languages should have increased more for the dynamic algorithmic instruction count, as the overhead increased; however, this was not the case. The task-clock rates also should have increased more, but there was a maximum increase of 3.35% for the language of Perl.

### C vs Python Results
#### Recursive Algorithm
C consistently outperformed Python on task-clock time, CPU-cycles, instruction count, instructions per second, and elapsed time. When it came to speedup calculations, C greatly outperformed Python by at least a factor of 28 over Python for fib of 20-40, with fib of 5 for the intervals. Regarding the memory resources, Python had significantly more page faults than C overall. For both the recursive algorithm, and the dynamic algorithm, C had around 40 page faults, whereas Python had about 800 page faults for both its recursive and dynamic algorithm for all fib numbers evaluated. As for the cache misses, Python also fared worse. Python showed exponential growth for its recursive algorithm cache misses, starting at about 300000, whereas C started around 15000 for its cache misses, and also depicted exponential growth. Python also had more cache misses in the dynamic algorithm with about 270000 cache misses, whereas C had about 7800 cache misses for the dynamic algorithm. In addition, the cache misses’ percent of all cache references decreased substantially for Python from 16 to just above 0 for fib of 20-40; this trend was similar to C’s performance, but from a starting point of 25 down to 10. A cache miss is when the data requested for is not in the cache memory and requires the program to fetch the data from other cache levels, or main memory. These high percentages for the cache misses as a percent of all cache references can lead to significant delays in execution time. 

### Inline C vs C Results
#### Recursive Algorithm
C remained under 1 millisecond for all Fibonacci numbers tested, but inline C went all the way up to 3247.92 milliseconds. C utilized 858,889,235,221 CPU cycles for Fibonacci of 50, whereas inline C only got up to 6,971,907,740 CPU cycles. Inline C utilized a lot more instructions than C did, being that the idea behind the keyword “inline” reduces the amount of function calls by replacing the function call with the contents of the function itself. Both forms of C had about the same number of CPUs utilized. Interestingly, inline C used 100% less GHz for its clock rate compared to C for Fibonacci of 20, but inline C and C grow to about the same clock rate after Fibonacci of 50. Initially, inline C had more than double the number of instructions per second than C; however, as the Fibonacci value increased for the function parameter input, the processor speed for both equated to about the same. Both inline C and C had the same average number of page-faults, cache misses, and percent of all cache refs being cache misses. The one-minute difference between the two include C increasing a bit, and then gradually decreasing, while inline C decreases drastically, increases a bit, and then decreases at a more gradual pace.

### Decorated Python vs Python Results
#### Recursive Algorithm
Python took longer for its task clock rates than that of Decorated Python with Fib of 40 being 91871.376 milliseconds for Python, and about 36 milliseconds for Decorated Python. Decorated Python used far fewer CPU cycles with its highest around 61,000,000, and Python using around 132,298,225,415 cycles for Fib of 40. Decorated Python also used far fewer instructions, and a smaller clock rate. Decorated Python did use more instructions, having around 2,500,000,000,000 instructions, and Python using around 28,000,000. With regard to cache, Decorated Python was costlier having more page faults. However, it significantly improved cache misses from almost 42,500,000 cache misses with Python to almost 290,000 cache misses with Decorated Python. It’s interesting to note that Python had a continual decline down to almost 0% for its cache misses as a percent of all cache references; whereas Decorated Python remained constant at 15% for Fibonacci values of 20 through 100.
n took longer for its task clock rates than that of Decorated Python with Fib of 40 being 91871.376 milliseconds for Python, and about 36 milliseconds for Decorated Python. Decorated Python used far fewer CPU cycles with its highest around 61,000,000, and Python using around 132,298,225,415 cycles for Fib of 40. Decorated Python also used far fewer instructions, and a smaller clock rate. Decorated Python did use more instructions, having around 2,500,000,000,000 instructions, and Python using around 28,000,000. With regard to cache, Decorated Python was costlier having more page faults. However, it significantly improved cache misses from almost 42,500,000 cache misses with Python to almost 290,000 cache misses with Decorated Python. It’s interesting to note that Python had a continual decline down to almost 0% for its cache misses as a percent of all cache references; whereas Decorated Python remained constant at 15% for Fibonacci values of 20 through 100.

### C vs Decorated Python
#### Recursive Algorithm
C was faster than Decorated Python with a speedup of almost 30 for Fibonacci of 20, but the two switched places after Fibonacci of 30, with Decorated Python ending Fibonacci of 40 almost 90 times faster than C. Decorated Python had fewer CPU cycles at 60,976,899.33 cycles, with C using 858,889,235,221. Decorated Python also outperformed C in regard to instruction count, having 28,075,491.67 instructions, and C using 6,169,788,902. Both used about 0.9 CPUs, but C used 2.156 GHz, and Decorated Python only used 1.666 GHz for Fibonacci of 40. On the other hand, Decorated Python had at least 810 page faults for every Fibonacci value tested, whereas C had at most 41 page faults. Decorated Python was also costlier for cache misses. However, C’s cache misses as a percent of all cache references decreased from about 25% to 10% and Decorated Python maintained 15% for every trial.

### Summary Statements
1. C outperformed Python in almost every regard
2. Python was less efficient with its memory allocation, resulting in many more page faults and cache misses.
3. With many recursive calls, C would be the better choice with a faster execution time. However, inline C used far fewer CPU cycles, with hundreds of millions more instructions than C did. When it comes down to the cache, there is little difference between inline C and C.
4. Having a decorated Python function takes a bit longer to execute, but it significantly improved the number of CPU cycles utilized, the number of instructions executed, and far fewer cache misses. Decorated Python does take a hit with more page faults and a constant of about 15% of all cache references being cache misses.
5. Decorated Python outperformed C in regard to execution time and speedup, CPU cycles, clock rate, and instruction count. However, Decorated Python was far costlier in terms of page faults, and cache misses.


### Code
The code can be found within my [research repository](https://github.com/sicoyle/Research).

### Acknowledgements
Special thanks to Mr. Gregory Lakomski for his valuable input, expertise, and guidance on this project. I also appreciate him allowing me to utilize his Intel Nuc for testing purposes. I appreciate Dr. Apan Qasem for setting up a server for me to test on, as well as for providing the resources that were essential to the success of this research. Also, I appreciate the encouragement that my family and friends provided.

### Future Work
Further research can be put into exploring more languages, utilizing a higher experimental scope, as well as comparing more of the resources consumed. In addition, other resource monitoring tools can be utilized to determine the validity of these results.


### Personal Goals
```markdown
I plan to continue this research Fall 2018.
I am also working to add the corresponding graphs to this site.
```

