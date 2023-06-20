import java.util.*;

class Semaphore {
    System.out.println("Semaphore help in synchronization");
	public enum Value { Zero, One }
	public Queue<Process> q = new LinkedList<Process>();
	public Value value = Value.One;

	public void P(Semaphore s, Process p)
	{
		if (s.value == Value.One) {
			s.value = Value.Zero;
		}
		else {
			// add the process to the waiting queue
			q.add(p);
			p.Sleep();
		}
	}

	public void V(Semaphore s)
	{
		if (s.q.size() == 0) {
			s.value = Value.One;
		}
		else {
			// select a process from waiting queue
			Process p = q.peek();
			// remove the process from waiting as it has
			// been sent for CS
			q.remove();
			p.Wakeup();
		}
	}
}
