import time
from random import randint
import matplotlib.pyplot as plt


def bubbleSort(arr):
    n = len(arr)
    for i in range(0, n - 1):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                (arr[j], arr[j+1]) = (arr[j+1], arr[j])


elements = []
times = []

for i in range(1, 10):
    arr = [randint(0, 1000) for i in range(0, 1000*i)]
    start = time.time()
    bubbleSort(arr)
    end = time.time()
    print(len(arr), "Elements sorted by Bubble Sort in:", end-start)
    elements.append(len(arr))
    times.append(end-start)

# Plot the graph
plt.xlabel("No. of elements")
plt.ylabel("Time required")
plt.plot(elements, times, label='Heap Sort')
plt.grid()
plt.legend()
plt.show()
