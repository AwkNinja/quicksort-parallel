# quicksort-parallel
Quicksort algorithm in parallel using OPENMP.

$$Serial\ time = 2.681000\ seconds<br>
Speed-up = \frac{serial\ time}{parallel\ time}<br>
Efficiency = \frac{Speed-up}{no.\ of\ threads}$$<br>


| Threads	| Elapsed-time (sec) |	Speed-up	| Efficiency |
| --- | --- | --- | --- |
| 8 |	0.695000	| 2.877697	| 35.97% |
| 16	| 0.985000	| 2.030457	| 12.69% |
| 32	| 1.162000	| 1.721170	| 5.38% |

From the results it is observed that the efficiency decreases as we increase the number of threads because it is not needed for a task such as quicksort as the parallel part is limited because of the serial process as explained by Amdahl’s law.
