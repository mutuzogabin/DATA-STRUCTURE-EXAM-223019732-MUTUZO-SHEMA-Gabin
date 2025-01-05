def bubble_sort(orders):
    n = len(orders)
    for i in range(n):
        for j in range(0, n-i-1):
            if orders[j]['priority'] > orders[j+1]['priority']:
                orders[j], orders[j+1] = orders[j+1], orders[j]
    print("Sorted Orders by Priority:", orders)


# Demo
orders = [
    {"id": 1, "priority": 3},
    {"id": 2, "priority": 1},
    {"id": 3, "priority": 2}
]
bubble_sort(orders)
