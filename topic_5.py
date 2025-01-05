class DynamicQueue:
    def __init__(self):
        self.queue = []

    def enqueue(self, order):
        self.queue.append(order)

    def dequeue(self):
        if not self.queue:
            return "Queue is empty"
        return self.queue.pop(0)

    def update_status(self, order_id, status):
        for order in self.queue:
            if order['id'] == order_id:
                order['status'] = status

    def display(self):
        print("Dynamic Queue Contents:", self.queue)


# Demo
dq = DynamicQueue()
dq.enqueue({"id": 1, "status": "Pending"})
dq.enqueue({"id": 2, "status": "Pending"})
dq.display()
dq.update_status(1, "Completed")
dq.display()
