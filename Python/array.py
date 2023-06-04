class array_implemenation:

    def __init__(self, size):
        self.size = size
        self.arr = [None] * size

arr = [1, 2, 3, 4, 5]

def display():
    for i in range(len(arr)):
        print(arr[i], end=" ")
    print()



display()
