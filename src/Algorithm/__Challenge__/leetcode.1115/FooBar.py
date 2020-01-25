import queue

class FooBar:
    def __init__(self, n):
        self.n = n
        self.queue = queue.Queue()
    
    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.queue.put(1)
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()


    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            self.queue.get()
            # printBar() outputs "bar". Do not change or remove this line.
        	printBar()