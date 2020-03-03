def partition(arr, start, end):
    pivot = arr[end]
    index = start-1

    for i in range(start, end):
        if arr[i] < pivot:
            index += 1
            arr[index], arr[i] = arr[i], arr[index]

    index += 1
    arr[index], arr[end] = arr[end], arr[index]
    return index

def qs(arr, start, end):
    if start < end:
        index = partition(arr, start, end)

        qs(arr, start, index-1)
        qs(arr, index+1, end)

ls = [1, 3, 3]

length = len(ls)
qs(ls, 0, length-1)

mid = int(length / 2)

if length % 2 == 0:
    mid = (ls[mid] + ls[mid+1]) / 2
else:
    mid = ls[mid]

# print(mid)

a = '\t\n d\t\n\r'

print(a.strip(' \n\t'))