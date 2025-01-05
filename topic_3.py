class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self):
        if not self.queue:
            return "Queue is empty"
        return self.queue.pop(0)

    def display(self):
        print("Queue Contents:", self.queue)


# Demo
queue = Queue()
queue.enqueue("Order1")
queue.enqueue("Order2")
queue.display()
queue.dequeue()
queue.display()
