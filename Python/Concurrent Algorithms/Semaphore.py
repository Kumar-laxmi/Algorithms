
from enum import Enum
from queue import Queue

class Semaphore:
	class Value(Enum):
		print('Semaphore help in synchronization')
		Zero = 0
		One = 1

	def __init__(self):
		self.q = Queue()
		self.value = Semaphore.Value.One

	def P(self, s, p):
		if s.value == Semaphore.Value.One:
			s.value = Semaphore.Value.Zero
		else:
			# add the process to the waiting queue
			s.q.put(p)
			p.Sleep()

	def V(self, s):
		if s.q.qsize() == 0:
			s.value = Semaphore.Value.One
		else:
			# select a process from waiting queue
			p = s.q.queue[0]
			# remove the process from waiting as it has
			# been sent for CS
			s.q.get()
			p.Wakeup()
