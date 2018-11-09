def bubble_sort(arr):
    for i in range(0,len(arr)-1):
      for j in range(0, len(arr)-1-i):
        if arr[j] > arr[j+1]:
          arr[j] , arr[j+1] = arr[j+1], arr[j]
    return(arr)

print(bubble_sort([1,7,3,9,9,9,9,9,9,9,9,99,2,7,4,7,3]))
