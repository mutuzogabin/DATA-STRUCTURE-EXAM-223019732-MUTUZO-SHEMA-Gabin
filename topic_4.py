class OrderArray:
    def __init__(self, size):
        self.size = size
        self.orders = [None] * size

    def add_order(self, index, order):
        if 0 <= index < self.size:
            self.orders[index] = order
        else:
            raise IndexError("Index out of bounds")

    def display(self):
        print("Order Array:", self.orders)


# Demo
order_array = OrderArray(5)
order_array.add_order(0, "Order1")
order_array.add_order(1, "Order2")
order_array.add_order(2, "Order3")
order_array.add_order(3, "Order4")

order_array.display()
